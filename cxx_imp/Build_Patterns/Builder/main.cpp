//
// Created by Sean on 4/8/25.
//
#include "Person.hpp"
#include "Pc.hpp"


void build_person() {
    Person sean = Person::create()
    .lives().at("University Street ")
            .with_postcode("W323 US1")
            .in("New Jersey")
    .works().at("JPMorgan")
            .as_a("Market Manager")
            .earning(700000);

    sean.introduce();
}

// 通过构造器模式来组装一台 pc
void build_pc_with_builder() {
    PC computer = PC::create()
    .cpu()
          .model("i512400kf")
          .with_liquid_cooling()
    .ram()
          .model("XPG Lancer ROG")
          .ddr5()
    .gpu()
          .model("RTX5090")
          .set_mount()
          .with_three_fans();

}

// 通过构造函数来组装一台 pc
void build_pc_without_builder() {
    CPU cpu{};
    cpu.with_model("i512400kf");
    cpu.set_liquid_cooling();

    RAM ram{};
    ram.with_model("XPG Lancer ROG");
    ram.ddr5();

    GPU gpu{};
    gpu.with_model("RTX5090");
    gpu.set_mount();
    gpu.with_three_fans();
    /*
     * 因为隐藏了构造函数，所以不可用
     */
    // PC computer{cpu, gpu, ram};
    // PC ai{};
}

int main() {

    build_pc_with_builder();

    build_pc_without_builder();

    return 0;
}

