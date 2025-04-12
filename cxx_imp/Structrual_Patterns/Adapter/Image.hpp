#pragma once
#include <vector>

struct Point {
	int x, y;
};

struct Line {
	Point start, end;
};


/*由于几何类型的图像不一定是以vector组织线段的，所以这里设计一个对线段的迭代的抽象*/
struct VectorObject {
	virtual std::vector<Line>::iterator begin() = 0;
	virtual std::vector<Line>::iterator end() = 0;
};

struct VectorRectangle : VectorObject {
private:
	std::vector<Line> lines;
public:
	VectorRectangle(int x, int y, int width, int height) {
		lines.emplace_back(Line{ Point{x,y}, Point{x + width,y}});
		lines.emplace_back(Line{ Point{x,y}, Point{x, y + height}});
		lines.emplace_back(Line{ Point{x + width,y},Point{x + width, y + height} });
		lines.emplace_back(Line{ Point{x, y + height},Point{x + width, y + height} });
	}

	std::vector<Line>::iterator begin() override {
		return lines.begin();
	}

	std::vector<Line>::iterator end() override {
		return lines.end();
	}
};

struct LineToPointAdaptor {
	using Points = std::vector<Point>;
private:
	Points points;
public:
	LineToPointAdaptor(Line& line) {
	//TODO: fix me
	}
	virtual Points::iterator begin() { return points.begin(); }
	virtual Points::iterator end() { return points.end(); }
};