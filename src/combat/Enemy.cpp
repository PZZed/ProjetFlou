//
// Created by pz on 05/05/2020.
//

#include "Enemy.h"
#include "Player.h"

combat::Enemy::Enemy() {
    hp=100;
    energy=200;
}

void combat::Enemy::attack(Player& p){
    srand (time(NULL));
    int damage = rand() % 10 + 10;
    p.substractHP(damage);
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

/*void combat::Enemy::makeDecision(Player & p , float decisionp, float decisione ){
    if(decisionp < 0.5){
        addEnergy(50);
    }
    else{
        attack(p);
    }
}*/
