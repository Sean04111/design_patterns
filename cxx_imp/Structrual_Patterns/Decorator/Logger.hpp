#pragma once
#include <functional>
#include <type_traits>
#include <iostream>

template <typename F>
class Logger
{
private:
	F _function;

public:

	explicit Logger(const F& f) : _function(f){}

	template <typename ... Args>
	auto operator() (Args&&... args) -> decltype(_function(args...))
	{
		std::cout << "before working doing something" << std::endl;
		if constexpr(std::is_void_v<decltype(_function(args...))>)
		{
			_function(std::forward<Args>(args)...);
			std::cout << "after working doing something" << std::endl;
		}else
		{
			auto ret = _function(std::forward<Args>(args)...);
			std::cout << "after working doing something" << std::endl;
			return ret;
		}
	}
};


template <typename R , typename ... Args>
auto make_logger(R(*func)(Args...))
{
	return Logger<R(*)(Args...)>{func};
}

template <typename F>
auto make_logger(const F& func)
{
	return Logger<F>{func};
}