#pragma once
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace coup {
    class Captain: public Player {
    private:
        Game game;
    public:
        Captain (const Game &game, const string& name);
        void steal (const Player &p);
        void block(const Player &p);
        ~Captain();
    };
}