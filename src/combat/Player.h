//
// Created by pisel on 05/05/2020.
//

#ifndef PROJETFLOU_PLAYER_H
#define PROJETFLOU_PLAYER_H
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <cstdlib>     /* srand, rand */
#include <time.h>       /* time */
#include "Enemy.h"


namespace combat{
    class Player{
        public:
            Player();
            virtual int attack();
            virtual void addEnergy(const int i);
            virtual void substractEnergy(const int i);
            virtual void addHP(const int i);
            virtual void substractHP(const int i);
            virtual int getHP()const;
            virtual int getEnergy()const;



        private:
            int hp;
            int energy;


    };



}


#endif //PROJETFLOU_PLAYER_H
