//
// Created by pisel on 05/05/2020.
//

#ifndef PROJETFLOU_FIGHT_H
#define PROJETFLOU_FIGHT_H

#include <string>
#include <iostream>


namespace combat{

    class Fight{
        public :
            Fight(std::string statFile);
            virtual ~Fight();
            void startFight();

    private:
        std::string statFile;
        Ennemy e;
        Player p;


    };

    Fight::Fight(std::string statFile): statFile(statFile) {
        //this.e = new ennemy(100,200,10,10);
        //this.p = new player(100,200,10,10);

    }

    void Fight::startFight(){

        // crée courbe fuzzy

        // pv 0->100
        // energie 0->200
        // taper -> 20 energie
        // heal -> 40 energie
        // chaque tour +15 energie
        // attendre
        // si pas énergie attaque échou
        //

        while(e.getHP()>0 || p.getHP()>0){
                // fuzzy evaluate avec joueur.pv, joueur.energy, ennemy.pv, ennemy.energy

                // show fuzzy stats en fonction des pv et de l'énergie de chacuns

                // cout << que voulez vous faire ?
                // cout << 1.attaquer
                // cout << 2.se soigner


                // cin >>  chaine
                // switch sur chaine
                    //if chaine == heal -> player.heal
                    //if chaine == attack -> player.attack(ennemy)
               // ennemy.decision(porcentcritiqueenergy,pourcentblesserenergy,pourcentGoodenergy,joueur)

                // votre energie : ""  votre energie : ""
                // l'ennemie à  energie : ""  votre energie : ""
        }


        if(e.getHP()==0){
            std::cout << "player win";
        }
        else{
            std::cout << "you have been defeated";
        }


    }



}

#endif //PROJETFLOU_FIGHT_H
