
#include <vector>
#include <string>
#include <functional>
#include <iostream>



class initial
{
public:

	std::vector<int> numbers;
	initial(std::initializer_list<int> list)
	{
		for (std::initializer_list<int>::iterator it = list.begin(); it != list.end();++it)
		{
			numbers.push_back(*it);
		}
	}
	
};

std::tuple<int,double, std::string> f()
{
	return std::tuple<int, double, std::string>{1, 1.2, "hello"};
}
auto get(auto x, auto y) 
{
	return x + y;
}


template <typename... Ts>
void magic(Ts...args)
{
	std::cout << sizeof...(args) << std::endl;
}

enum class number
{
	first ,
	second 
};

int add(int x, int y)
{
	return x + y;
}

struct alignas(std::max_align_t) AlignasStorage {
	char a;
	int b;
	double c;
	long long d;
};


int main()
{
	initial data =  { 1,2,3,4 };

	auto [x, y, z] = f();

	std::cout << get(1, 2) << std::endl;

	using my_int = int;

	using add_func = int(*)(int, int);

	// 不要使用typedef ，使用using，能够更加贴切函数指针的定义

	add_func adder = [](int x, int y) -> int{return x + y;};

	std::cout << adder(10, 10) << std::endl;
	magic(1, "", 32);


	std::function<int(int, int)> foo = add;

	auto foo1 = std::bind(foo, std::placeholders::_1, 10);

	std::cout << foo1(100) << std::endl;




	return 0;
}