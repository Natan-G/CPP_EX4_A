#include "Player.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include <iostream>
#include <string>

using namespace std;
namespace coup {

    Duke::Duke(const Game &game, const string& name): Player(game, name){

    }
    Duke::~Duke()
    {
    }
    void Duke::tax(){

    }
    void Duke::block(const Player &p){

    }

}