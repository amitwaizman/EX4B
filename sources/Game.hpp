#ifndef COUP_A_GAME_H
#define COUP_A_GAME_H
#pragma once
#include <vector>
#include <string>
#include "Player.hpp"
using namespace std;
namespace coup {
    class Player;
    class Game {
    public:
        int countPlayer;
        bool start=false;
        bool start1=false;

        vector <Player *> List_Of_Players;
        vector <Player *> turn1;
        bool EndFGame= false;
        string  turn();
        vector <string> players();
        string winner();
    };
}
#endif //COUP_A_GAME_H


