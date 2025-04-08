//
// Created by Sean on 4/8/25.
//

#pragma once
#ifndef PC_HPP
#define PC_HPP
#include <string>

/*
 * 以组装 PC 为例：
 * 一台 PC 需要有 CPU、GPU、MEM、DISK、POWER、MOTHERBOARD 这几种成员；
 * 每一个成员都有独自的组装方式
 */

class CPU;
class CPUBuilder;

class GPU;
class GPUBuilder;

class RAM;
class RAMBuilder;

class PC;
class PCBuilder;


class Components {
protected:
    std::string _model;
public:
    void with_model(std::string model) {
        _model = model;
    }

    Components(){}
};

class CPU  : public Components {
    enum Cooling {
        AIR_COOLING,
        LIQUID_COOLING,
    };
private:
    Cooling _cooling = AIR_COOLING;
public:
    void set_air_cooling() { _cooling = AIR_COOLING; }
    void set_liquid_cooling() {_cooling = LIQUID_COOLING; }

    CPU(){}
};

class GPU : public Components {
    enum Fans_Type {
        TREE_FANS,
        TWO_FANS,
    };
private:
    Fans_Type _fans_type = TWO_FANS;
    bool _with_mount = false;
public:
    void set_mount() { _with_mount = true; }

    void with_three_fans() {
        _fans_type = TREE_FANS;
    }
    void with_two_fans() {
        _fans_type = TWO_FANS;
    }

    GPU(){}
};

class RAM : public Components {
    enum DDR_TYPE {
        DDR4,
        DDR5
    };
private:
    DDR_TYPE _ddr_type = DDR4;
public:
    void ddr4() {
        _ddr_type = DDR4;
    }
    void ddr5() {
        _ddr_type = DDR5;
    }
    RAM(){}
};


class PC {
    CPU _cpu;
    GPU _gpu;
    RAM _ram;
    /*
     *这里通过隐藏构造函数来强制用户使用构造器来构造
     */
    PC(){}
public:

    static PCBuilder create();

    friend class PCBuilder;
    friend class CPUBuilder;
    friend class GPUBuilder;
    friend class RAMBuilder;
};


class PCBuilder {
protected:
    PC _pc;
public:
    operator PC() {
        return std::move(_pc);
    }
    PCBuilder(){};

    PCBuilder(PC& pc) : _pc(pc) {}

    CPUBuilder cpu();
    GPUBuilder gpu();
    RAMBuilder ram();
};


class CPUBuilder : public PCBuilder{
    using self = CPUBuilder;
public:
    self& model(std::string model) {
        _pc._cpu.with_model(model);
        return *this;
    }
    self& with_air_cooling() {
        _pc._cpu.set_air_cooling();
        return *this;
    }
    self& with_liquid_cooling() {
        _pc._cpu.set_liquid_cooling();
        return *this;
    }

    /*
     * 这里需要注意继承的时候，派生类的成员和基类的成员不是同一个；
     * 这里需要对基类做初始化，所以需要把_pc 的引用传给 CPUBuilder 的基类，也就是一个新的 PCBuilder
     * 这里其实也就是继承和组合的区别所在了;
     * 这个点应该是组合构造器的最关键的点了
     */
    CPUBuilder(PC& pc) : PCBuilder(pc) {
        _pc._cpu = CPU();
    }
};

class GPUBuilder : public PCBuilder {
    using self = GPUBuilder;
public:
    self& model(std::string model) {
        _pc._gpu.with_model(model);
        return *this;
    }

    self& set_mount() {
        _pc._gpu.set_mount();
        return *this;
    }

    self& with_three_fans() {
        _pc._gpu.with_three_fans();
        return *this;
    }

    self& with_two_fans() {
        _pc._gpu.with_two_fans();
        return *this;
    }

    GPUBuilder(PC& pc): PCBuilder(pc) {
        _pc._gpu = GPU();
    }
};

class RAMBuilder : public PCBuilder {
    using self = RAMBuilder;
public:
    self& model(std::string model) {
        _pc._ram.with_model(model);
        return *this;
    }

    self& ddr4() {
        _pc._ram.ddr4();
        return *this;
    }

    self& ddr5() {
        _pc._ram.ddr5();
        return *this;
    }

    RAMBuilder(PC& pc) : PCBuilder(pc) {
        _pc._ram = RAM();
    }
};

inline CPUBuilder PCBuilder::cpu() {
    return CPUBuilder(_pc);
}

inline RAMBuilder PCBuilder::ram() {
    return RAMBuilder(_pc);
}

inline GPUBuilder PCBuilder::gpu() {
    return GPUBuilder(_pc);
}

inline PCBuilder PC::create() {
    return PCBuilder();
}






#endif //PC_HPP
