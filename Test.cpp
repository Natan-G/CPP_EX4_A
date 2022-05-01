#include "doctest.h"
#include "Game.hpp"
#include "Ambassador.hpp"
#include "Player.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"
#include "Duke.hpp"
#include "Contessa.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;
using namespace coup;

TEST_CASE("Coins and cup function"){

    Game game{};

    Duke duke{game , "Moshe"};
	Assassin assassin{game , "Yossi"};
	Ambassador ambassador{game , "Meirav"};

    
    CHECK_EQ(duke.coins() , 0);
    duke.income();
    CHECK_EQ(duke.coins() , 1);

    CHECK_EQ(assassin.coins() , 0);
    assassin.income();
    CHECK_EQ(assassin.coins() , 1);

    ambassador.income();
    ambassador.foreign_aid();
    ambassador.foreign_aid();
    CHECK_THROWS(ambassador.coup(duke));//cup cost 7 coins
    ambassador.foreign_aid();
    CHECK_EQ(ambassador.coins() , 7);
    CHECK_NOTHROW(ambassador.coup(duke));//cup duke
    CHECK_EQ(ambassador.coins() , 0);
    CHECK(game.players().size()==2);//duck is out

}

TEST_CASE("role players functionality"){
    Game game{};

    Duke duke{game , "Moshe"};
	Assassin assassin{game , "Yossi"};
	Ambassador ambassador{game , "Meirav"};
	Captain captain{game , "Reut"};
	Contessa contessa{game , "Gilad"};
    

    //Assassin and Contessa
    CHECK_EQ(assassin.coins() , 0);
    assassin.income();
    CHECK_EQ(assassin.coins() , 1);
    assassin.foreign_aid();
    CHECK_EQ(assassin.coins() , 3);

    CHECK_NOTHROW(assassin.eliminate(duke));
    CHECK_EQ(assassin.coins() , 0);//eliminate cost 3 coins
    CHECK_THROWS(contessa.block(duke));
    CHECK_NOTHROW(contessa.block(assassin));
    CHECK_EQ(game.players().size() , 3);//still 3 plyaers until assassin turn again

    //Ambassador and captain
    duke.income();
    assassin.income();
    ambassador.transfer(assassin , duke);
    CHECK_EQ(assassin.coins() , 0);
    CHECK_EQ(duke.coins() , 2);
    captain.steal(duke);//captain steal from duke
    CHECK_EQ(captain.coins() , 2);
    assassin.foreign_aid();//assasin 2 coins
    captain.steal(assassin);
    ambassador.block(captain);
    CHECK_EQ(captain.coins() , 2);//steal blocked

}

TEST_CASE("Game proccess, full scenario"){
    Game game{};

	Duke duke{game , "Moshe"};
	Assassin assassin{game , "Yossi"};
	Ambassador ambassador{game , "Meirav"};
	Captain captain{game , "Reut"};
	Contessa contessa{game , "Gilad"};

    CHECK(game.players().size()==5);// 5 players
    
    //check turn
    CHECK_FALSE(game.turn() == "Gilad");
    CHECK(game.turn() == "Moshe");
    duke.income();//moshe 1 coins

    CHECK(game.turn() == "Yossi");
    assassin.foreign_aid();//yossi 2 coins
    
    CHECK(game.turn() == "Meirav");
    ambassador.transfer(duke , assassin);//now yossi 3 and moshe 0
    CHECK_EQ(assassin.coins() , 3);
    CHECK_EQ(duke.coins() , 0);

    CHECK(game.turn() == "Reut");
    captain.steal(assassin);
    ambassador.block(assassin);
    CHECK_EQ(assassin.coins() , 3); // Meirav block reut steal

    CHECK(game.turn() == "Gilad");
    contessa.income();//gilad 1 coin

    duke.foreign_aid();// moshe 2 coins
    assassin.eliminate(ambassador);//hahaha revange
    CHECK_EQ(assassin.coins() , 0);
    CHECK(game.players().size()==4);// 4 players

    captain.steal(duke);//reut 2 coins
    CHECK_EQ(captain.coins() , 2);

    contessa.income();//gilad 2 coin

    duke.foreign_aid();//4 coins

    assassin.foreign_aid();//2 coins
    
    captain.foreign_aid();//4 coins
    duke.block(captain);
    CHECK_EQ(captain.coins() , 2);

    contessa.foreign_aid();//4 coins
    duke.foreign_aid();//4 coins
    assassin.income();//3 coins
    captain.foreign_aid();//6 coins

    contessa.income();//5 coins
    duke.foreign_aid();//6 coins
    assassin.eliminate(duke);
    contessa.block(assassin);


    CHECK(game.players().size()==4);// still 4 players
    captain.income();//7 coins
    contessa.foreign_aid();//7 coins

    duke.income();//7 coins

    assassin.foreign_aid();//2 coins
    captain.coup(assassin);
    CHECK(game.players().size()==3);//3 players

    contessa.coup(captain);
    CHECK(game.players().size()==2);//2 players

    duke.coup(contessa);
    CHECK(game.players().size()==1);//1 players

    
    CHECK(game.winner()=="Moshe");
}




