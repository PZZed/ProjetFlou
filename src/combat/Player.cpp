//
// Created by pz on 05/05/2020.
//

#include "Player.h"

combat::Player::Player(int i, int i1, int i2, int i3) {
    hp=100;
    energy=200;
}

void combat::Player::attack(Enemy p ){
    srand (time(NULL));
    int damage = rand() % 10 + 10;
    p.substractHP(damage);
}

void combat::Player::addEnergy(int i){
    energy +=i;
    if (energy>200){
        energy=200;
    }
}

void combat::Player::substractEnergy(int i){
    energy-=i;
    if(energy < 0){
        energy=0;
    }
}

void combat::Player::addHP(int i) {
    hp-=i;
    if(hp >100){
        hp=100;
    }
}

void combat::Player::substractHP(int i) {
    hp-=i;
    if(hp < 0){
        hp=0;
    }
}

int combat::Player::getHP() {
    return hp;
}

int combat::Player::getEnergy(){
    return energy;
}


