#include "Player.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace coup {

    Player::Player(const Game &game, const string &name) {
        this->game=game;
        this->name=name;
        this->coin=0;
    }

    Player::~Player()
    {
    }

    void Player::income() {

    }
    void Player::foreign_aid() {

    }
    void Player::coup(const Player &p) {

    }

    int Player::coins() {
        return 0;
    }
    
    string Player::role(){
        return "";
    }

}