#include "Game.hpp"
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

namespace coup {
    Game::Game(){

    }
    Game::~Game(){

    }

    string Game::turn(){
        return " ";
    }

    string Game::winner(){
        return " ";
    }
    
    vector<string> Game:: players(){
        return this->_players;
    }
    
    


}