#pragma once
#include "Player.hpp"
#include "Game.hpp"
#include "Assassin.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace coup {
    class Contessa: public Player {
    private:
        Game game;

    public:
        Contessa(const Game &game, const string& name);
        ~Contessa();
        void block(const Player &p);
       
    };
}