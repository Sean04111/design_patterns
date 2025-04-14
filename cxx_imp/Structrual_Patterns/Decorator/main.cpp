
#include <iostream>
#include "Logger.hpp"




int add(int a, int b) {
	std::cout << "adding" << std::endl;
	return a + b;
}


void work()
{
	std::cout << "working" << std::endl;
}

int main()
{
	auto l1 = make_logger(add);

	l1(1,2);

	auto l2 = make_logger([&]()->void
		{
			std::cout << "working" << std::endl;
		});


	l2();
}	