#include <algorithm>
#include <iostream>
#include <vector>

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
	T& operator[](std::size_t index)
	{
	}
};

int main(int argc, char **argv)
{
	auto print = [](const char* s) { std::cout << s << std::endl; };
	std::for_each(argv, argv + argc, print);

	const int i = 0; // decltype(i) to const int
	decltype(i) z = 1;
	std::cout << "decltype(i): " << typeid(decltype(i)).name() << std::endl;
	std::cout << "decltype(z): " << typeid(decltype(z)).name() << std::endl;

	//z = 6; //cannot assign to a variable that is const

	bool f(const Widget& w);
	std::cout << "decltype(f): " << typeid(decltype(f)).name() << std::endl;
	
	Point p;
	std::cout << "decltype(p): " << typeid(decltype(p)).name() << std::endl;

	Vector<decltype(p)> v;
	std::cout << "decltype(v): " << typeid(decltype(v)).name() << std::endl;
	std::cout << "decltype(Vector::operator): " << typeid(decltype(&Vector<decltype(p)>::operator[])).name() << std::endl;

	return 0;
}
