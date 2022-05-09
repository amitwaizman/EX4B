//
// Created by USER on 25/04/2022.
//

#ifndef COUP_A_CAPTAIN_H
#define COUP_A_CAPTAIN_H

#include "Player.hpp"
#include <string>
#include "Game.hpp"
namespace coup{
    class Game;
    using namespace std;
    class Captain : public  Player{
    public:
        Captain(Game &game, const string &str);
        void steal(Player &player);
        void block(Player &captain);



    };
}
#endif //COUP_A_CAPTAIN_H
