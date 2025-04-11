//
// Created by Sean on 4/11/25.
//

#ifndef CARS_HPP
#define CARS_HPP
#include <string>
/*
 *  个人理解使用原型模式，就是给需要复制的对象创建一个clone方法；
 *  clone方法能够支持对所有的成员进行复制
 */


struct  Engine
{
    Engine();
    Engine(const Engine& other);
};
struct  Framework
{
    Framework();
};
struct  Wheels
{
    Wheels();
};


/*
 * Benz 类型汽车，对发动机、框架、轮胎有统一的标准
 */
class Benz {
private:
    Engine* engine_;
    Framework* framework_;
    Wheels* wheels_;

public:
    Benz() {
        engine_ = new Engine();
        framework_ = new Framework();
        wheels_ = new Wheels();
    }

    Benz(const Benz& other) {
        engine_ = new Engine(other.engine_);
        framework_ = new Framework(other.framework_);
        Wheels = new Wheels(other.wheels_);
    }

    virtual Benz* clone();
};

class C_Class : public Benz {
public:
    std::string model;
    bool has_massage;

    C_Class() {
        has_massage = false;
    }

    C_Class(const C_Class& other) {
        model = "C_Class";

        has_massage = other.has_massage;
    }

    /*
     * 使用clone函数来实现拷贝，说明c_class也就是一个原型
     * 可以根据c_class去组装或者构建其他类型的对象
     */
    C_Class* clone() override
    {
        return new C_Class(*this);
    }
};

#endif //CARS_HPP
