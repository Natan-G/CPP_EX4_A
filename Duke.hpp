#pragma once
#include "Player.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace coup {
    class Duke: public Player{
    private:
        Game game;
    public:

        Duke(const Game &game, const string& name);
        ~Duke();
        void tax();
        void block(const Player &p);
        
    };
}