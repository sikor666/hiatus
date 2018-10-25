#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

#include <boost/type_index.hpp>

class Widget
{
};

struct Point
{
	int x, y;
};

template<typename T> class Vector
{
public:
	T operator[](std::size_t index)
	{
		return T{};
	}
};

template<typename Container, typename Index>
auto access(Container&& c, Index i) -> decltype(std::forward<Container>(c)[i])
{
	return std::forward<Container>(c)[i];
}

int main(int argc, char **argv)
{
	using boost::typeindex::type_id_with_cvr;

	auto print = [](const char* s) { std::cout << s << std::endl; };
	std::for_each(argv, argv + argc, print);

	const int i = 0; // decltype(i) to const int
	decltype(i) z = i;
	std::cout << "decltype(i): " << typeid(decltype(i)).name() << std::endl;
	std::cout << "decltype(i): " << type_id_with_cvr<decltype(i)>().pretty_name() << std::endl;
	std::cout << "decltype(z): " << typeid(decltype(z)).name() << std::endl;
	std::cout << "decltype(z): " << type_id_with_cvr<decltype(z)>().pretty_name() << std::endl;

	//z = 6; //cannot assign to a variable that is const

	bool f(const Widget& w);
	std::cout << "decltype(f): " << typeid(decltype(f)).name() << std::endl;
	std::cout << "decltype(f): " << type_id_with_cvr<decltype(f)>().pretty_name() << std::endl;
	
	Point p;
	std::cout << "decltype(p): " << typeid(decltype(p)).name() << std::endl;
	std::cout << "decltype(p): " << type_id_with_cvr<decltype(p)>().pretty_name() << std::endl;

	Vector<decltype(p)> v;
	std::cout << "decltype(v): " << typeid(decltype(v)).name() << std::endl;
	std::cout << "decltype(v): " << type_id_with_cvr<decltype(v)>().pretty_name() << std::endl;
	std::cout << "decltype(Vector::operator): " << typeid(decltype(&Vector<decltype(p)>::operator[])).name() << std::endl;
	std::cout << "decltype(Vector::operator): " << type_id_with_cvr<decltype(&Vector<decltype(p)>::operator[])>().name() << std::endl;

	auto r = access(v, z);
	std::cout << "decltype(r): " << typeid(decltype(r)).name() << std::endl;
	std::cout << "decltype(r): " << type_id_with_cvr<decltype(r)>().name() << std::endl;

	std::deque<int> d{ 0 };
	access(d, z) = 1;
	std::cout << "decltype(authAndAccess(d, z)): " << typeid(decltype(access<decltype(d), decltype(z)>)).name() << std::endl;
	std::cout << "decltype(authAndAccess(d, z)): " << type_id_with_cvr<decltype(access<decltype(d), decltype(z)>)>().name() << std::endl;

	std::vector<bool>b{ true };
	std::cout << "decltype(b[0]): " << typeid(decltype(b[0])).name() << std::endl;
	std::cout << "decltype(b[0]): " << type_id_with_cvr<decltype(b[0])>().name() << std::endl;

	return 0;
}
