#pragma once
/*静态装饰器基于Maxin技术，来对最初的类型进行保留*/
#include <string>
#include <sstream>
#include <utility>

namespace static_decorator {

	struct Shape {
		virtual std::string str() const = 0;
	};

	struct Square : Shape{
		int width;

		Square(int width) : width(width) {}

		std::string str() const override {
			std::ostringstream oss;
			oss << "Square has width " << width;
			return oss.str();
		}
	};

	template <typename T> requires std::derived_from<T,Shape>
	struct ColoredShape : T {
		std::string color;

		template <typename... Args>
		ColoredShape(std::string color, Args...args) : color(color), T(std::forward<Args>(args)...) {}

		std::string str() const override {
			std::ostringstream oss;
			oss << this->T::str() <<" has color of " << color;
			return oss.str();
		}
	};
}

