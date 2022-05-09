
#include "Player.hpp"

namespace coup {
    Player::Player(Game &game, const string &B ){
        this->namePlayer=B;
        this->game=&game;
        this->index1=0;
        this->index2=0;
        this->steal1=NULL;
        this->copyPlayer=NULL;
        this->numberOFcoins=0;
        this->game->List_Of_Players.push_back(this);
        this->game->turn1.push_back(this);
        if(this->game->start){
            throw std::out_of_range{"not start"};
        }

    }

//    Player:: Player(Player &other){
//        this->namePlayer=other.namePlayer;
//        this->numberOFcoins=other.numberOFcoins;
//        this->rolePlayer=other.rolePlayer;
//        this->game=other.game;
//
//    }


    void Player::income() {
        const int one=1;
        const int ten =10;
        if(this->game->turn1.size()>one) {
            string name = game->turn();
            if (name == this->namePlayer) {
                this->game->start= true;
                if (this->numberOFcoins >= ten) {
                    throw std::out_of_range{"you need to do coup"};
                }
                numberOFcoins++;
                update();

            } else {
                throw std::out_of_range{"not income"};

            }
        }else{
            throw std::out_of_range{"one player"};

        }

    }

    void Player::update() const{
        Player *p = game->List_Of_Players[0];
        game->List_Of_Players.erase(game->List_Of_Players.begin());
        game->List_Of_Players.push_back(p);
    }
    void Player::foreign_aid() {
        const int ten=10;
        const int two=2;
        if(this->game->turn1.size()>1) {
            this->action.push_back("foreign_aid");
            string name = game->turn();
            if (name == this->namePlayer) {
                this->game->start= true;
                if (this->numberOFcoins >= ten) {
                    throw std::out_of_range{"you need to do coup"};
                }
                numberOFcoins = numberOFcoins + two;
                update();
            } else {
                throw std::out_of_range{"not foreign_aid"};
            }
        }else{
            throw std::out_of_range{"not good"};

        }
    }

    void Player::coup(Player player) {
        bool ans= true;
        const int seven=7;
        const int three=3;
        this->action.push_back("coup");
        if(this->numberOFcoins>=seven ||((this->rolePlayer=="Assassin")&&(this->numberOFcoins>= three)&&(this->numberOFcoins<seven)) ){
            if(this->numberOFcoins>=seven &&(this->rolePlayer=="Assassin")){
                this->action.push_back("notCoup");
            }
            update();
            int j=0;
            for (unsigned i = 0; i < this->game->List_Of_Players.size(); ++i) {
                Player *p=this->game->List_Of_Players[i];
                if((p->namePlayer==player.namePlayer)&&(p->rolePlayer==player.rolePlayer)){
                    this->copy= this->game->turn1;
                    ans= false;
                    this->game->List_Of_Players.erase(this->game->List_Of_Players.begin()+j);
                }
                j++;
            }
            if(ans){
                this->action.push_back("notCoup");
                throw std::out_of_range{"ALREADY DEAD"};

            }

            int j1=0;
            for (unsigned i = 0; i < this->game->turn1.size() ; ++i) {
                Player *p=this->game->turn1[i];
                if((p->namePlayer==player.namePlayer)&&(p->rolePlayer==player.rolePlayer)){
                    this->copyPlayer=&player;
                    this->index1=j1;
                    this->game->turn1.erase(this->game->turn1.begin()+j1);
                }
                j1++;
            }

            if(((this->rolePlayer=="Assassin")&&(this->numberOFcoins>=three)&&(this->numberOFcoins<seven))){
                this->numberOFcoins=this->numberOFcoins-three;
            }else{
                this->numberOFcoins=this->numberOFcoins-seven;
            }
        } else{
            this->action.push_back("notCoup");
            throw std::out_of_range{"not coup"};
        }

    }

     string  Player:: role()const {
        return this->rolePlayer;
    }

     int  Player::  coins()const {
        return this->numberOFcoins;
    }
}
