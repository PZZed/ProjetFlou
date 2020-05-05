//
// Created by pisel on 05/05/2020.
//

#ifndef PROJETFLOU_ENNEMY_H
#define PROJETFLOU_ENNEMY_H
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

namespace Combat{
    class Ennemy{
    public:
        Ennemy();
        virtual void attack(Player p);
        virtual void addEnergy(int i);
        virtual void substactEnergy();
        virtual void substractHP(int i);
        virtual int getHP();
        virtual int getEnergy;
        virtual void makeDecision(Player p , double decision);


    private:
        int hp;
        int energy;


    };
    Ennemy::Ennemy(){
        hp=100;
        energy=200;
    }

    void Ennemy::attack(Player p){
        srand (time(NULL));
        damage = rand() % 10 + 10;
        p.substactHP(damage);
    }

    void Ennemy::addEnergy(int i){
        energy +=i;
        if (energy>200){
            energy=200;
        }
    }

    void Ennemy::substractEnergy(int i){
        energy-=i;
        if(energy < 0){
            energy=0;
        }
    }

    void Ennemy::substractHP(int i) {
        hp-=i;
        if(hp < 0){
            hp=0;
        }
    }

    int Ennemy::getHP() {
        return hp;
    }

    int Ennemy::getEnergy(){
        return energy;
    }

    void Ennemy::makeDecision(Player p , double decision){
        if(decision < 0.5){
            addEnergy(50);
        }
        else{
            attack(p);
        }
    }
}

#endif //PROJETFLOU_ENNEMY_H
