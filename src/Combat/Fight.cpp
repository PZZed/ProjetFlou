//
// Created by pz on 05/05/2020.
//


#include <string>

#include "Fight.h"

combat::Fight::Fight(std::string statFile, combat::Player & p,  combat::Enemy & e) : statFile(statFile), p(p),e(e) {
}

void combat::Fight::startFight(){
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
    ValueModel<float> Eenergy(0);
    NotMinus1<float> opNot;
    AndMin<float> opAnd;
    OrMax<float> opOr;
    ThenMin<float> opThen;
    CogDeFuzz<float> opDefuzz(0,200,1);
    AggMax<float> opAgg;
    FuzzyFactory<float> f(&opAnd,&opOr,&opThen,&opDefuzz,&opAgg,&opNot);

    Expression<float> *r1 =
            f.newAgg(
                    f.newAgg(
                            f.newThen(
                                    f.newIs(&critcical,&Phealth),
                                    f.newIs(&exhausted,&Penergy)
                            ),
                            f.newThen(
                                    f.newIs(&wounded,&Phealth),
                                    f.newIs(&tired,&Penergy)
                            )
                    ),
                    f.newThen(
                            f.newIs(&good,&Phealth),
                            f.newIs(&excellent,&Penergy)
                    )
            )  ;

    Expression<float> *r2 =
            f.newAgg(
                    f.newAgg(
                            f.newThen(
                                    f.newIs(&critcical,&Ehealth),
                                    f.newIs(&exhausted,&Eenergy)
                            ),
                            f.newThen(
                                    f.newIs(&wounded,&Ehealth),
                                    f.newIs(&tired,&Eenergy)
                            )
                    ),
                    f.newThen(
                            f.newIs(&good,&Ehealth),
                            f.newIs(&excellent,&Eenergy)
                    )
            )  ;

    Expression<float> *valp = f.newDefuzz(&Phealth, r1, 0, 200, 1);
    Expression<float> *vale = f.newDefuzz(&Ehealth, r2, 0, 100, 1);

    while(e.getHP()>0 || p.getHP()>0){

        std::cout << "votre energie=\"" << p.getEnergy() << "\" votre santé=\"" << p.getHP() << "\"" ;
        std::cout << "l\'ennemie energie=\"" << e.getEnergy() << "\" et sa santé=\"" << e.getHP() << "\" \n ";

        std::cout << "que voulez vous faire ?";
        std::cout << "1.attaquer";
        std::cout << "2.se soigner";
        std::string choix;
        std::cin >> choix;
        if(choix == "1"){
            e.substractHP(p.attack());
        }
        else if(choix == "2"){
            p.addHP(30);
        }

        p.substractHP(e.makeDecision((float)valp->evaluate(),(float)vale->evaluate()));

        p.addEnergy(15);
        e.addEnergy(15);

    }


    if(e.getHP()==0){
        std::cout << "player win";
    }
    else{
        std::cout << "you have been defeated";
    }


}

combat::Fight::~Fight() {
}
