#ifndef COUP_A_PLAYER_H
#define COUP_A_PLAYER_H
#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace coup{
    class Game;
    class Player{
    public:
        string namePlayer;
        string rolePlayer;
        int numberOFcoins;
        Game *game;
        vector<string> action;
        Player *steal1;
        Player *copyPlayer;
        int index1;
        int index2;

        vector<Player *> copy;
        Player(Game &game, const string &B);
        void income();
        void foreign_aid();
        void coup(Player player);
        string role() const;
         int  coins() const;
         void   update() const ;
    };
}

#endif //COUP_A_PLAYER_H