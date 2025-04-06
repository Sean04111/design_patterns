//
// Created by Sean on 4/6/25.
//
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
 *
 *SOLID 设计原则
 *单一职责原则 Single Responsibility Principle
 *开闭原则 Open-Closed Principle
 *里式替换原则 Liskov Substitution Principle
 *接口隔离原则 Interface Segregation Principle
 *依赖倒转原则 Dependency Inversion Principle
 */


/*
 *单一职责原则
 * 每个类只有一个职责；
 */

struct Journal {
 string title;
 vector<string> entries;

 explicit Journal(const string& title): title(title) {}

 void add(const string& entry) {
  static int count = 1;
  entries.push_back(entry + ":" + to_string(count++));
 }

 void save(const string& filename) {
  ofstream ofs(filename);
  for (auto& s: entries) {
   ofs << s << endl;
  }
 }

};

struct PersistanceManager {
 static void save(const Journal& j, const string & filename) {
  ofstream ofs(filename);
  for (auto& entry : j.entries) {
   ofs << entry << endl;
  }
 }
};


void show_SRP() {
 Journal j {"Dear Diary"};
 j.add("I cried today");
 j.add("I ate a bug");
}

/*
 * 开闭原则
 */

enum class Color{Red, Green, Blue};
enum class Size{Small, Medium, Large};

struct Product {
 string name;
 Color color;
 Size size;
};

struct ProductFilter {
 typedef vector<Product*> Items;
 Items by_color(Items items, Color color) {
  Items result;
  for (auto& item : items) {
   if (item -> color == color) {
    result.push_back(item);
   }
  }
  return result;
 }

 Items by_size(Items items, Size size) {
  Items result;
  for (auto& item : items) {
   if (item-> size ==  size) {
    result.push_back(item);
   }
  }
  return result;
 }

 Items by_size_color(Items items, Color color, Size size) {
  Items result;
  for (auto& item : items) {
   if (item -> color == color && item -> size == size) {
    result.push_back(item);
   }
  }
  return result;
 }
 /*
  * 这样后面每次新添加过滤的条件都会写一个结构一样的代码，很操蛋
  * 开闭原则要求软件实体对扩展开放，对修改关闭
  */
};

template <typename T>
struct Specification {
 virtual bool is_satisfied(T* item) = 0;
};

/*
 *基于 Specification 来定义过滤器
 */
template <typename T>
struct Filter {
 virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) const = 0;
};

struct BetterFilter: Filter<Product> {
 vector <Product*> filter(vector<Product*> items, Specification<Product>& spec) const override {
  vector<Product*> result;
  for (auto& item : items) {
   if (spec.is_satisfied(item)) {
    result.push_back(item);
   }
  }
  return result;
 }
};

template <typename T>
struct AndSpecification : Specification<T> {
 Specification<T>& first;
 Specification<T>& second;
 AndSpecification(Specification<T>& first, Specification<T>& second): first(first), second(second) {}
 bool is_satisfied(T* item) override {
  return first->is_satisfied(item) && second->is_satisfied(item);
 }
};

struct ColorSpecification : Specification<Product> {
 Color color;
 bool is_satisfied(Product* item) override {
  return item -> color == color;
 }
 explicit ColorSpecification(const Color color) : color(color) {}
};

struct SizeSpecification : Specification<Product> {
 Size size;
 bool is_satisfied(Product* item) override {
  return item-> size == size;
 }
 explicit SizeSpecification(const Size size) : size(size) {}
};

void show_OCP() {
 SizeSpecification large{Size::Large};
 ColorSpecification green{Color::Green};

 AndSpecification<Product> green_and_large{large, green};
}

/*
 * 里氏替换原则
 * 如果某个接口以基类Parent 类型为参数，那么它应该同等地接受子类 Child 类对象为参数
 * 并且程序不会产生任何异常
 */

class Rectangle {
protected:
 int width, height;
public:
 Rectangle(const int width, const int height): width(width), height(height) {}
 int get_width() const {return width;}
 virtual void set_width(const int width){this -> width = width;}

 int get_height() const {return height;}
 virtual void set_height(const int height) {this -> height = height;}

 int area() const {return width * height;}

};

class Square : public Rectangle {
 Square(int size) : Rectangle(size, size) {}
 void set_width(const int width) override {this -> width = height = width;}

 void set_height(const int height) override {this -> height = height;}
};

void process(Rectangle& r) {
 int w = r.get_width();
 r.set_height(10);
 cout <<  "expect area =" << (w*10) << ", got " << r.area() << endl;
}

/*
 *此时 process 函数如果接受了 Square 的对象就会出现问题，违背了里氏替换原则
 */

/*
 * 接口隔离原则
 *  所有接口需要拆分开，让实现者根据自身需求挑选接口实现
 *  基本思想就是将复杂的接口分离为多个独立的接口，以避免强制实现者必须实现某些他们实际上并不需要的接口
 */

struct Machine {
 virtual void print(vector<string> docs) = 0;
 virtual void fax(vector<string> docs) = 0;
 virtual void scan(vector<string> docs) = 0;
};

/*
 * 这里如果实现者只需要使用 print 接口，但是还是需要去重载一下 fax 和scan两个完全不需要的函数
 * 所以这里比较操蛋
 */
struct Printer : Machine {
 void print(vector<string> docs) override;
 void fax(vector<string> docs) override;
 void scan(vector<string> docs) override;
};

/*
 *应该遵循接口隔离原则，不同的接口应该隔离开
 */

struct IPrinter {
 virtual void print(vector<string> docs) = 0;
};

struct IFaxer {
 virtual void fax(vector<string> docs) = 0;
};

struct IScanner {
 virtual void scan(vector<string> docs) = 0;
};

/*
 * 这样实现者就可以根据自己的需要来挑选所需要的接口来实现了
 */

struct MyFavouritePrinter : IPrinter {
 void print(vector<string> docs) override{}
};

/*
 * 对于 Machine 这样接口，直接将几个接口组合就可以了
 */

struct IMachine : IPrinter , IScanner, IFaxer {
};

struct MyFavouriteMachine : IMachine {
 void print(vector<string> docs) override;
 void scan(vector<string> docs) override;
 void fax(vector<string> docs) override;
};

/*
 * 依赖倒转原则
 * 1. 高层模块不应该依赖底层模块，它们都应该依赖抽象接口；
 * 2. 抽象接口不应该依赖细节，细节应该依赖抽象接口；
 */