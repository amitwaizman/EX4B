#include "Duke.hpp"
#include <vector>

using namespace std;
namespace coup {

    Duke::Duke(coup::Game &game, const string &str):Player(game,str){
        const int six=6;
        this->rolePlayer="Duke";
        if(this->game->turn1.size()>six){
            throw std::out_of_range{"add more than 6 players"};
        }
    }
    void Duke::block(Player &player) {
        const int one=1;
        const int two=2;
        const int zero=0;
        this->action.push_back("block");
        string p=player.action[player.action.size()-one];
        if(p.compare("foreign_aid")==zero){
            player.numberOFcoins= player.numberOFcoins-two;
        }else{
            throw std::out_of_range{"not good"};
        }
    }

    void Duke::tax() {
        const int three=3;
        const int zero=0;

        this->action.push_back("tax");
        string name=game->turn();
        if(name== this->namePlayer) {
            numberOFcoins=numberOFcoins+three;
            Player *p = game->List_Of_Players[zero];
            game->List_Of_Players.erase(game->List_Of_Players.begin());
            game->List_Of_Players.push_back(p);
        }else{
            throw std::out_of_range{"Not your turn"};

        }
    }


}