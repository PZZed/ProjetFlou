//
// Created by pisel on 05/05/2020.
//

#ifndef PROJETFLOU_ENEMY_H
#define PROJETFLOU_ENEMY_H
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <cstdlib>     /* srand, rand */
#include <time.h>       /* time */
#include "../combat/Player.h"
#include "Player.h"


namespace combat{
    class Enemy{
    public:
        Enemy();
        virtual ~Enemy(){}
        virtual int attack();
        virtual void addEnergy(cosnt int i);
        virtual void substractEnergy(const int i);
        virtual void substractHP(const int i);
        virtual int getHP()const ;
        virtual int getEnergy()const;
        int makeDecision( const float descisione);


    private:
        int hp;
        int energy;


    };


}

#endif //PROJETFLOU_ENEMY_H
