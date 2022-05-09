#include "Ambassador.hpp"
using namespace std;
namespace coup {

    Ambassador::Ambassador(Game &game, const string &str):Player::Player(game,str){
        this->rolePlayer="Ambassador";
        const int six=6;
        if(this->game->turn1.size()>six){
            throw std::out_of_range{"add more than 6 players"};
        }
    }


    void Ambassador::block(Player &captain) {
        const int zero=0;
        const int one=1;
        const int two=2;

        this->action.push_back("block");
        if(!action.empty()) {
            string cap = captain.action[captain.action.size() - one];
            if (captain.role() == "Captain" && cap.compare("steal") == zero) {
                 captain.steal1->numberOFcoins= captain.steal1->numberOFcoins+two;
                  captain.numberOFcoins = captain.numberOFcoins - two;
            } else {
                throw std::out_of_range{"not Captain"};
            }
        }else{
            throw std::out_of_range{"not size"};

        }
    }

    void Ambassador::transfer(Player &A, Player &B) {
        this->action.push_back("transfer");
        string name=game->turn();
        const int zero=0;
        if(name== this->namePlayer) {
            if(A.coins()>zero){
                A.numberOFcoins--;
                B.numberOFcoins++;
                Player *p = game->List_Of_Players[zero];
                game->List_Of_Players.erase(game->List_Of_Players.begin());
                game->List_Of_Players.push_back(p);
            } else{
                throw std::out_of_range{"not coins"};

            }
        }else{
            throw std::out_of_range{"not foreign_aid"};

        }
    }


}