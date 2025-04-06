//
// Created by Sean on 4/6/25.
//

/*
 *  Curiously Recurring Template Pattern
 *  奇异递归模板模式
 *
 * 继承者将自身作为模板参数传递给基类
 * 这样可以在基类的实现中访问特定类型的 this 指针
 */
template<typename T>
class BaseClass<T> {
    void foo() {
        // 这里可以强制把 this 指针转化为 T类型的指针，也就是派生类的 this 指针了
        for (auto& item: *static_cast<T*>(this)) {

        }
    }
};


struct foo: BaseClass<foo> {
    class iterator {

    };
    iterator begin(){}
    iterator end(){}
};


