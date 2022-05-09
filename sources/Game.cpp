#include "Game.hpp"

namespace coup {
    string Game::turn() {
        Player *p= List_Of_Players[0];
        string name=p->namePlayer;
        return name;
    }

    vector <string> Game::players() {
        vector <string> names;
        for (unsigned long i = 0; i <turn1.size() ; ++i) {
          Player* p=turn1[i];
          names.push_back(p->namePlayer);
       }
        return names;
    }

    string Game::winner() {
       if(this->List_Of_Players.size()>1|| !(this->start)){
           throw std::out_of_range{"not good"};
       }

       Player *win=this->List_Of_Players[0];
        return win->namePlayer;
    }
}
