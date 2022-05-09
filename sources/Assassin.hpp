//
// Created by USER on 25/04/2022.
//

#ifndef COUP_A_ASSASSIN_H
#define COUP_A_ASSASSIN_H
#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Game;
    using namespace std;
    class Assassin : public Player {
    public:
//        void coup(Player *player);
        Assassin(Game &game, const string &str);

    };
}

#endif //COUP_A_ASSASSIN_H
