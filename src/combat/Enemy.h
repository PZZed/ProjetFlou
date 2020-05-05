//
// Created by pisel on 05/05/2020.
//

#ifndef PROJETFLOU_ENEMY_H
#define PROJETFLOU_ENEMY_H
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "../combat/Player.h"
#include "Player.h"


namespace combat{
    class Enemy{
    public:
        Enemy();
        virtual ~Enemy(){}
        virtual void attack(combat::Player & p);
        virtual void addEnergy(int i);
        virtual void substractEnergy(int i);
        virtual void substractHP(int i);
        virtual int getHP();
        virtual int getEnergy();
        //virtual void makeDecision(Player& p , float decisionp, float descisione);


    private:
        int hp;
        int energy;


    };


}

#endif //PROJETFLOU_ENEMY_H
