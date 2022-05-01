#pragma once
#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace coup {
    class Ambassador: public Player {
    private:
        Game game;
    public:
        Ambassador(const Game &game , const string& name);
        ~Ambassador();
        void transfer(const Player &p1 , const Player &p2);
        void block(const Player &p);
    };
}