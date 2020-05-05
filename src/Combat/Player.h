//
// Created by pisel on 05/05/2020.
//

#ifndef PROJETFLOU_PLAYER_H
#define PROJETFLOU_PLAYER_H

namespace Combat{
    class Player{
        public:
            Player();
            virtual void attack(Player p);
            virtual void addEnergy(int i);
            virtual void substactEnergy(int i);
            virtual void addHP(int i);
            virtual void substractHP(int i);
            virtual int getHP();
            virtual int getEnergy;



        private:
            int hp;
            int energy;


    };
    
    Player::Player(){
        hp=100;
        energy=200;
    }

    void Player::attack(Player p){
        srand (time(NULL));
        damage = rand() % 10 + 10;
        p.substactHP(damage);
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
        if(hp >100{
            hp=100;
        }
    }

    void Ennemy::substractHP(int i) {
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
