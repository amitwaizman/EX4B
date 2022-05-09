#include "Captain.hpp"
using namespace std;
namespace coup {

    Captain::Captain(Game &game, const string &str):Player::Player(game,str){
        this->rolePlayer="Captain";
        const int six=6;
        if(this->game->turn1.size()>six){
            throw std::out_of_range{"add more than 6 players"};

        }
    }

    void Captain::block(Player &captain) {
        this->action.push_back("block");
        const int one=1;
        const int zero=0;
        const int two=2;
        if( !action.empty()) {
            string cap = captain.action[action.size() - one];
            if (captain.role() == "Captain" && cap.compare("steal") == zero) {
               this->steal1->numberOFcoins =this->steal1->numberOFcoins + two;
                captain.numberOFcoins = captain.numberOFcoins - two;
            } else {
                throw std::out_of_range{"not Captain"};

            }
        } else{
            throw std::out_of_range{"not size"};

        }
    }

    void Captain::steal(Player &player) {
        const int one=1;
        const int two=2;
        const int zero=0;

        this->action.push_back("steal");
        string name=game->turn();
        if(name== this->namePlayer) {
            if(player.numberOFcoins>=one) {
                if (player.numberOFcoins >= two) {
                    player.numberOFcoins = player.numberOFcoins - two;
                    this->steal1 = &player;
                    this->numberOFcoins = this->numberOFcoins + two;
                } else{
                    player.numberOFcoins = player.numberOFcoins - one;
                  this->steal1 = &player;
                   this->numberOFcoins = this->numberOFcoins + one;
            }
            } else{
                throw std::out_of_range{"no money"};
            }
            Player *play = game->List_Of_Players[zero];
            game->List_Of_Players.erase(game->List_Of_Players.begin());
            game->List_Of_Players.push_back(play);
        }else{
            throw std::out_of_range{"not foreign_aid"};

        }
    }
}
