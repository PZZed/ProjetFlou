//
// Created by pz on 05/05/2020.
//


#include "Player.h"

combat::Player::Player() {
    hp=100;
    energy=200;
}

int combat::Player::attack(){
    srand (time(nullptr));
    int damage = rand() % 10 + 10;
    substractEnergy(20)
    return damage;
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


