#include "Captain.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace coup {

    Captain::Captain(const Game &game, const string& name): Player(game,name){

    }
    Captain::~Captain()
    {
    }
    void Captain::steal (const Player &p) {

    }
    void Captain::block(const Player &p){

    }
}