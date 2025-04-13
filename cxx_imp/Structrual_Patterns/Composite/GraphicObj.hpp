#pragma once

#include <iostream>
#include <vector>

struct  GraphicObj {
	virtual void Draw() = 0;
};

struct Circle : GraphicObj {
	void Draw() override {
		std::cout << "Circle" << std::endl;
	}
};


struct ObjGroups : GraphicObj {
	std::string name;
	std::vector<GraphicObj*> objs;

	void Draw() override {
		std::cout << name.c_str() << "contains : " << std::endl;
		for (auto&& obj : objs) {
			obj->Draw();
		}
	}
};
