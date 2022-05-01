#include "Contessa.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Assassin.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace coup {

    Contessa::Contessa(const Game &game, const string& name): Player(game, name){
    }

    Contessa::~Contessa(){
    }

    void Contessa::block(const Player &p){
    }
}