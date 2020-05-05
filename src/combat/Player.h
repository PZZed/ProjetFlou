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
            virtual void attack(Enemy p );
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

    Player::Player(){
        hp=100;
        energy=200;
    }

    void Player::attack(Enemy p ){
        srand (time(NULL));
         int damage = rand() % 10 + 10;
        p.substractHP(damage);
    }

    void Player::addEnergy(int i){
        energy +=i;
        if (energy>200){
            energy=200;
        }
    }

    void Player::substractEnergy(int i){
        energy-=i;
        if(energy < 0){
            energy=0;
        }
    }

    void Player::addHP(int i) {
        hp-=i;
        if(hp >100){
            hp=100;
        }
    }

    void Player::substractHP(int i) {
        hp-=i;
        if(hp < 0){
            hp=0;
        }
    }

    int Player::getHP() {
        return hp;
    }

    int Player::getEnergy(){
        return energy;
    }

}


#endif //PROJETFLOU_PLAYER_H
