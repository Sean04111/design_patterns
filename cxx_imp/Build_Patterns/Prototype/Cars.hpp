//
// Created by Sean on 4/11/25.
//

#ifndef CARS_HPP
#define CARS_HPP
#include <string>
/*
 *  �������ʹ��ԭ��ģʽ�����Ǹ���Ҫ���ƵĶ��󴴽�һ��clone������
 *  clone�����ܹ�֧�ֶ����еĳ�Ա���и���
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
 * Benz �����������Է���������ܡ���̥��ͳһ�ı�׼
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
     * ʹ��clone������ʵ�ֿ�����˵��c_classҲ����һ��ԭ��
     * ���Ը���c_classȥ��װ���߹����������͵Ķ���
     */
    C_Class* clone() override
    {
        return new C_Class(*this);
    }
};

#endif //CARS_HPP
