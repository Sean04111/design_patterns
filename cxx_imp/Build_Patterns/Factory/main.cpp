//
// Created by Sean on 4/9/25.
//

#include <iostream>
#include <vector>
#include "dumbs.hpp"

Dumb::DumbFactory Dumb::university;

int main() {

    std::vector<std::shared_ptr<Dumb>> graduates;

    for (int i = 0; i < 10; ++i) {
        auto new_dumb_graduates = Dumb::university.create_fallen_dumb();
        graduates.push_back(new_dumb_graduates);
    }

    auto sean = Dumb::university.create_raised_dumb();
    graduates.push_back(sean);

    std::cout << Dumb::university.get_dumb_counts() << std::endl;
}