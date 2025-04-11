//
// Created by Sean on 4/11/25.
//

#ifndef CARS_HPP
#define CARS_HPP
#include <string>

class Engine{};
class Framework{};
class Wheels{};


class Benz {
public:
    Engine* engine;
    Framework* framework;
    Wheels* wheels;

    Benz() {
        engine = new Engine();
        framework = new Framework();
        wheels = new Wheels();
    }

    Benz(const Benz& other) {
        engine = new Engine(other.engine);
        framework = new Framework(other.framework);
        Wheels = new Wheels(other.wheels);
    }
};

class C_Class : public Benz {
public:
    std::string model;

    Benz* benz_proto;
    bool has_massage;

    C_Class() {
        has_massage = true;
    }

    C_Class(const C_Class& other) {
        model = "C_Class";
        benz_proto = new Benz(*other.benz_proto);
        has_massage = other.has_massage;
    }
};


#endif //CARS_HPP
