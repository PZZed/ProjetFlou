//
// Created by pisel on 05/05/2020.
//

#ifndef PROJETFLOU_PLAYER_H
#define PROJETFLOU_PLAYER_H
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Enemy.h"


namespace combat{
    class Player{
        public:
            Player();
            virtual int attack();
            virtual void addEnergy(int i);
            virtual void substractEnergy(int i);
            virtual void addHP(int i);
            virtual void substractHP(int i);
            virtual int getHP();
            virtual int getEnergy();



        private:
            int hp;
            int energy;


    };



}


#endif //PROJETFLOU_PLAYER_H
