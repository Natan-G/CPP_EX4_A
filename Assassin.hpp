#pragma once
#include "Player.hpp"
#include "Game.hpp"
using namespace std;

namespace coup {
    class Assassin: public Player {
    private:
        Game game;
    public:
        Assassin(const Game &game, const string& name);
        ~Assassin();
        void eliminate(Player &p);
    };
}