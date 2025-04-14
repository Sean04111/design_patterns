#pragma once

/*
 * 使用动态装饰器：具体的组合方式由使用用户来决定
 */

#include <string>
#include <sstream>

struct Shape {
	virtual std::string str() const = 0;
};

struct Circle : Shape {
	float radius;

	explicit Circle(float radius) : radius{ radius } {};

	std::string str() const override {
		std::ostringstream oss;
		oss << "A circle of radius " << radius;
		return oss.str();
	}
};

struct ColoredShape : Shape {
	Shape& shape;
	std::string color;

	ColoredShape(Shape& shape, std::string color) : shape{ shape }, color{ color } {};

	std::string str() const override {
		std::ostringstream oss;
		oss << shape.str() << " has the color of " << color;
		return oss.str();
	}
};

struct TransparentShape : Shape {
	Shape& shape;
	float transparency;

	TransparentShape(Shape& shape, float transparency) : shape{ shape }, transparency{ transparency } {};

	std::string str() const override {
		std::ostringstream oss;
		oss << shape.str() << " has the transparency of " << transparency;
		return oss.str();
	}
};

