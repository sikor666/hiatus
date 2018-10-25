#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	auto print = [](const char* s) { std::cout << s << std::endl; };

	std::for_each(argv, argv + argc, print);

	return 0;
}
