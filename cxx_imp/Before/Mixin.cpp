//
// Created by Sean on 4/6/25.
//

/*
 * 类可以继承他的模板参数
 */

template<typename T>
struct Mixin: T {

};

/*
 *使用 Mixin 继承，可以允许实现不同类型的分层组合，例如：
 *可以实例化一个 Foo<Bar<Baz>> x 类型的对象，而不需要实际构造一个 FooBarBaz 类型
 /
