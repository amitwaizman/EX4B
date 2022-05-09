

#ifndef COUP_A_DUKE_H
#define COUP_A_DUKE_H
#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup{
   class Game;
    using namespace std;
    class Duke : public Player {
    public:
        Duke(coup::Game &game, const string &str);
        void block(Player &player);
        void tax();
    };

}
#endif //COUP_A_DUKE_H
