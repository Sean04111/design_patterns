//
// Created by Sean on 4/9/25.
//

#ifndef DUMBS_HPP
#define DUMBS_HPP

#include "Wall.hpp"


class Dumb {
private:
    bool play_games = false;
    bool no_tech = false;
    bool has_experience = false;
    int age = 22;


    void fall() {
        play_games = true;
        no_tech = true;
        has_experience = false;
        age = 22;
    }

    void raise() {
        play_games = false;
        no_tech = false;
        has_experience = true;
        age = 21;
    }

    class DumbFactory {
        std::atomic<int> dumb_count = 0;
    public:
        DumbFactory() = default;

        std::shared_ptr<Dumb> create_fallen_dumb() {
            std::shared_ptr<Dumb> dumb = std::make_shared<Dumb>();
            dumb->fall();
            dumb_count.fetch_add(1);
            return dumb;
        }

        std::shared_ptr<Dumb> create_raised_dumb() {
            std::shared_ptr<Dumb> dumb = std::make_shared<Dumb>();
            dumb->raise();
            dumb_count.fetch_add(1);
            return dumb;
        }

        int get_dumb_counts() const {
            return dumb_count.load();
        }
    };
public:
    Dumb() = default;

    static DumbFactory university;
};



#endif //DUMBS_HPP
