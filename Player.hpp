#pragma once
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>


using namespace std;

namespace coup {
    class Player{
    protected:
        int coin;
        string name;
        Game game;

    public:
        Player(const Game &game, const string& name);
        ~Player();
        void income();
        void foreign_aid();
        void coup(const Player &p);
        static int coins();
        static string role();
        
        
        
    };
}