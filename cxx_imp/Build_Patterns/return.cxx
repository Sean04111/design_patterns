/*
 * 函数是如何返回对象的；
 * 如果要从函数中返回比 word 更大的对象，有几种方式：
 *
 *
 */

#include <iostream>
using namespace std;



struct Foo {
    Foo(int n){cout << "Foo constructor called" << endl;}
    Foo(const Foo&) {cout << "Foo copy constructor called" << endl; }
};


/*
 * 1. 直接返回值： 这个时候就会涉及到使用了返回值优化， RVO 是一项用于防止发生额外拷贝的编译器技术；
 *               调用这个函数的时候，会发现，Foo 的复制构造函数根本没有被调用；
 *               这就是使用 RVO 优化的结果，具体的内容，参考《深度探索 C++对象模型》 page 63
 */
Foo make_Foo() {
    return Foo{1};
}

/*
 * 2. 返回智能指针
 *
 */
unique_ptr<Foo> make_Foo(int n) {
    return make_shared<Foo>(n);
}

/*
 * 3. 返回原始指针
 */


Foo* make_Foo_ptr(int n) {
    return new Foo(n);
}

int main() {
    auto foo = make_Foo();
}