//
// Created by pisel on 05/05/2020.
//

#ifndef PROJETFLOU_ENEMY_H
#define PROJETFLOU_ENEMY_H
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Player.h"

namespace combat{
    class Enemy{
    public:
        Enemy();
        virtual ~Enemy(){}
        virtual void attack(Player p);
        virtual void addEnergy(int i);
        virtual void substractEnergy(int i);
        virtual void substractHP(int i);
        virtual int getHP();
        virtual int getEnergy();
        virtual void makeDecision(Player p , double decision);


    private:
        int hp;
        int energy;


    };
    Enemy::Enemy(){
        hp=100;
        energy=200;
    }

    void Enemy::attack(Player p){
        srand (time(NULL));
         int damage = rand() % 10 + 10;
        p.substractHP(damage);
    }

    void Enemy::addEnergy(int i){
        energy +=i;
        if (energy>200){
            energy=200;
        }
    }

    void Enemy::substractEnergy(int i){
        energy-=i;
        if(energy < 0){
            energy=0;
        }
    }

    void Enemy::substractHP(int i) {
        hp-=i;
        if(hp < 0){
            hp=0;
        }
    }

    int Enemy::getHP() {
        return hp;
    }

    int Enemy::getEnergy(){
        return energy;
    }

    void Enemy::makeDecision(Player p , double decision){
        if(decision < 0.5){
            addEnergy(50);
        }
        else{
            attack(p);
        }
    }


}

#endif //PROJETFLOU_ENEMY_H
