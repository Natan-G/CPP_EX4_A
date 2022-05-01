#include "Ambassador.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace coup {
    Ambassador::Ambassador(const Game &game, const string& name): Player(game,name) {

    }
    Ambassador::~Ambassador()
    {
    }

    void Ambassador::transfer(const Player &p1 , const Player &p2){

    }
    void Ambassador::block(const Player &p){

    }

}
