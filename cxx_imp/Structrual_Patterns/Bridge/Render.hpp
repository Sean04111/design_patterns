#include <string>
#include <iostream>

struct Render {
	virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRender : Render {
	void render_circle(float x, float y, float radius) override{
		std::cout << "Vector render a circle of radius " << radius << std::endl;
	}
};

struct RasterRender : Render {
	void render_circle(float x, float y, float radius) override {
		std::cout << "Raster render a circle of radius " << radius << std::endl;
	}
};

struct Shape {
protected:
	Render& render;
	Shape(Render& render) : render(render) {}
public:
	virtual void draw() = 0;
	virtual void resize(float factor) = 0;
};

/*使用桥接模式:
* 但是感觉没有什么用，这种应该属于使用abstract base class(cxx) / interface(golang) / traits(rust) 的基本用法
*/
struct Circle : Shape {
private:
	float x, y, radius;
public:
	void draw() override {
		std::cout << "drawing circle" << std::endl;
		render.render_circle(x, y,radius);
	}

	void resize(float factor) override {
		std::cout << "resize circle with facotr" << factor << std::endl;
		render.render_circle(x, y, radius);
	}
};