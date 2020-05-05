//
// Created by pz on 05/05/2020.
//

#include "Enemy.h"
#include "Player.h"

combat::Enemy::Enemy() {
    hp=100;
    energy=200;
}

int combat::Enemy::attack(){
    srand (time(nullptr));
    int damage = rand() % 10 + 10;
    substractEnergy(20);
    return damage;
}

void combat::Enemy::addEnergy(int i){
    energy +=i;
    if (energy>200){
        energy=200;
    }
}

void combat::Enemy::substractEnergy(int i){
    energy-=i;
    if(energy < 0){
        energy=0;
    }
}

void combat::Enemy::substractHP(int i) {
    hp-=i;
    if(hp < 0){
        hp=0;
    }
}

int combat::Enemy::getHP() {
    return hp;
}

int combat::Enemy::getEnergy(){
    return energy;
}

int combat::Enemy::makeDecision( float decisionp, float decisione ){
    if(decisionp < 0.5){
        addEnergy(50);
    }
    else{
        return attack();
    }
    return 0;
}
