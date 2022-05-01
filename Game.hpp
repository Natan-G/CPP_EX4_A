#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;

namespace coup {

    class Game {
        private:
            vector<string> _players;
        public:
            Game();
            ~Game();
            string static turn();
            vector<string>players();
            string static winner();
            
    };
}
