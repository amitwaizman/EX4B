#include "Assassin.hpp"
using namespace std;
namespace coup {

    Assassin::Assassin(Game &game, const string &str):Player::Player(game,str){
        this->rolePlayer="Assassin";
        const int six=6;
        if(this->game->turn1.size()>six){
            throw std::out_of_range{"add more than 6 players"};

        }

    }



}