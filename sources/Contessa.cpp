#include "Contessa.hpp"
using namespace std;
namespace coup {
    Contessa::Contessa(Game &game, const string &str):Player::Player(game,str){
        this->rolePlayer="Contessa";
        const int six=6;
        if(this->game->turn1.size()>six){
            throw std::out_of_range{"add more than 6 players"};

        }
    }
    void Contessa::block(Player &assassin) {
        bool ans= true;
        const int zero=0;
        const int one=1;
        for (unsigned  long i = zero; i < this->game->turn1.size(); ++i) {
            Player *play =  this->game->turn1[i];
            if ( (assassin.namePlayer == play->namePlayer) &&(assassin.rolePlayer == play->rolePlayer)) {
                ans= false;
            }
        }
        if(ans){
            throw std::out_of_range{"not good"};

        }
        this->action.push_back("block");
        if( !assassin.action.empty()) {
            string c = assassin.action[assassin.action.size() - one];
            if (assassin.role() == "Assassin" && c.compare("coup") == zero) {
                auto itPos = this->game->turn1.begin() + assassin.index1;
                this->game->turn1.insert(itPos, assassin.copyPlayer);
                int j2 = zero;
                for (unsigned long i = zero; i < assassin.copy.size(); ++i) {
                    Player *play1 = assassin.copyPlayer;
                    Player *play2 = assassin.copy[i];
                    if ( (play1->namePlayer == play2->namePlayer) &&(play1->rolePlayer == play2->rolePlayer)) {
                        int g=(assassin.index1 + j2+one);
                        int g1=g%(int)(this->game->List_Of_Players.size());
                        auto itPos1 = this->game->List_Of_Players.begin() + g1;
                        this->game->List_Of_Players.insert(itPos1, assassin.copyPlayer);
                        break;
                    }
                    j2++;
                }

            }else{
                throw std::out_of_range{"not size"};
            }
        } else{
            throw std::out_of_range{"not size"};

        }
    }
}
