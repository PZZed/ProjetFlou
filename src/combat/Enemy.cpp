//
// Created by pz on 05/05/2020.
//

#include <iostream>
#include "Enemy.h"
#include "Player.h"

combat::Enemy::Enemy() {
    hp=100;
    energy=200;
}

int combat::Enemy::attack(){
    srand (time(nullptr));
    int damage = rand() % 10 + 10;
    substractEnergy(80);
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

int combat::Enemy::getHP() const{
    return hp;
}

int combat::Enemy::getEnergy()const{
    return energy;
}

int combat::Enemy::makeDecision(  float decisione ){
    std::cout << std::endl << decisione << std::endl;
    if(decisione <= 2){
        addEnergy(50);
    }
    else if(decisione <= 4 ){
        return attack();
        //rien mais doit block
    }
    else{
        return attack();
    }
    return 0;
}
