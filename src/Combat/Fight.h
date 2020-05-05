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
        Ennemy *e;
        Player *p;


    };

    Fight::Fight(std::string statFile): statFile(statFile) {

        e = new ennemy(100,200,10,10);
        p = new player(100,200,10,10);

    }

    void Fight::startFight(){

        //les pdvs
        IsTriangle<float> critcical(0,0,40);
        IsTriangle<float> wounded(30,50,80);
        IsTriangle<float> good(70,100,100);

        //l'energie
        IsTriangle<float> exhausted(0,0,40);
        IsTriangle<float> tired(80,100,140);
        IsTriangle<float> excellent(100,150,200);

        // les valeurs
        ValueModel<float> Phealth(0);
        ValueModel<float> Penergy(0);
        ValueModel<float> Ehealth(0);
        ValueModel<float> Penergy(0);

        Expression<float> *r1 =
                        f.newAgg(
                                f.newAgg(
                                        f.newThen(
                                                 f.newIs(&Phealth,&critcical),
                                                 f.newIs(&Penergy,&exhausted)
                                        ),
                                        f.newThen(
                                                f.newIs(&Phealth,&wounded),
                                                f.newIs(&Penergy,&tired)
                                        )
                                ),
                        f.newThen(
                                f.newIs(&Phealth,&good),
                                f.newIs(&Penergy,&excellent)
                        )
                        )  ;

        Expression<float> *r2 =
                f.newAgg(
                        f.newAgg(
                                f.newThen(
                                        f.newIs(&Ehealth,&critcical),
                                        f.newIs(&Eenergy,&exhausted)
                                ),
                                f.newThen(
                                        f.newIs(&Ehealth,&wounded),
                                        f.newIs(&Eenergy,&tired)
                                )
                        ),
                        f.newThen(
                                f.newIs(&Ehealth,&good),
                                f.newIs(&Eenergy,&excellent)
                        )
                )  ;

        Expression<float> *valp = f.newDefuzz(&Phealth, r1, 0, 200, 1);
        Expression<float> *vale = f.newDefuzz(&Ehealth, r2, 0, 100, 1);

        while(e.getHP()>0 || p.getHP()>0){

                std::cout << "votre energie=\"" << p->getEnergy() << "\" votre santé=\"" << p->getHealth() << "\"" ;
                std::cout << "l\'ennemie energie=\"" << e->getEnergy() << "\" et sa santé=\"" << e->getHealth() << "\" \n ";

                std::cout << "que voulez vous faire ?"
                std::cout << "1.attaquer"
                std::cout << "2.se soigner"
                std::string choix;
                std::cin >> choix;

                if(choix == "1"){
                    p.attack(e);
                }
                else if(choix == "2"){
                    p.heal();
                }


                e->decision(valp->evaluate(),vale->evaluate(),p);

                p->addEnergie(15);
                e->addEnergie(15);

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
