//
// Created by pz on 05/05/2020.
//


#include <string>

#include "Fight.h"
#include "../fuzzy/IsTrapeze.h"

combat::Fight::Fight(std::string statFile, combat::Player & p,  combat::Enemy & e) : statFile(statFile), p(p),e(e) {
}

void combat::Fight::startFight(){
    //les pdvs
    IsTrapeze<float> lowHealth(0, 0, 20, 40);
    IsTrapeze<float> highHealth(20, 40, 100, 100);

    //l'energie
    IsTrapeze<float> lowEnergy(0, 0, 40, 80);
    IsTrapeze<float> highEnergy(20, 80, 200, 200);

    //Actions
    IsTriangle<float> spell(0, 1, 2);
    IsTriangle<float> block(2, 3, 4);
    IsTriangle<float> attack(4, 5, 6);

    // les valeurs

    ValueModel<float> Phealth(0);
    ValueModel<float> Penergy(0);
    ValueModel<float> Ehealth(0);
    ValueModel<float> Eenergy(0);
    ValueModel<float> actionp(0);
    ValueModel<float> actione(0);
    NotMinus1<float> opNot;
    AndMin<float> opAnd;
    OrMax<float> opOr;
    ThenMin<float> opThen;
    CogDeFuzz<float> opDefuzz(0,200,1);
    AggMax<float> opAgg;
    FuzzyFactory<float> f(&opAnd,&opOr,&opThen,&opDefuzz,&opAgg,&opNot);

    Expression<float> *r1 =
        f.newAgg(
                        f.newThen(
                                f.newIs(&lowHealth, &Phealth),
                                f.newIs(&spell, &actionp)
                        ),
                        f.newThen(
                                f.newAnd(
                                        f.newIs(&highHealth, &Phealth),
                                        f.newIs(&highEnergy, &Penergy)
                                ),
                                f.newIs(&attack,&actionp)
                        )
                );

    Expression<float> *r2 =
            f.newAgg(
                    f.newAgg(
                            f.newThen(
                                    f.newIs(&lowEnergy, &Eenergy),
                                    f.newIs(&spell, &actione)
                            ),
                            f.newThen(
                                    f.newIs(&lowHealth, &Ehealth),
                                    f.newIs(&block, &actione)
                            )
                    ),
                    f.newThen(
                            f.newAnd(
                                    f.newIs(&highHealth, &Ehealth),
                                    f.newIs(&highEnergy, &Eenergy)
                            ),
                            f.newIs(&attack,&actione)
                    )
            );

    Expression<float> *valp = f.newDefuzz(&actionp, r1, 0, 6, 0.1);
    Expression<float> *vale = f.newDefuzz(&actione, r2, 0, 6, 0.1);

    while(e.getHP()>0 && p.getHP()>0){

        //Update fuzzy
        Phealth.setValue(p.getHP());
        Penergy.setValue(p.getEnergy());
        Ehealth.setValue(e.getHP());
        Eenergy.setValue(e.getEnergy());

        std::cout << "Vous avez " << p.getEnergy() << " points d'energie et " << p.getHP() << " points de vie." << std::endl;
        std::cout << "L\'ennemie a " << e.getEnergy() << " points d'energie et " << e.getHP() << " points de vie." << std::endl;

        std::cout << "Que voulez vous faire ?" << std::endl;
        std::cout << "1.Attaquer" << std::endl;
        std::cout << "2.Se soigner" << std::endl;
        std::string choix;
        std::cin >> choix;
        if(choix == "1"){
            e.substractHP(p.attack());
        }
        else if(choix == "2"){
            p.addHP(30);
        }


        p.substractHP(e.makeDecision((float)valp->evaluate(),(float)vale->evaluate()));

        p.addEnergy(30);
        e.addEnergy(30);

    }


    if(e.getHP()==0) {
        std::cout << "player win";
    }else{
        std::cout << "you have been defeated";
    }


}

combat::Fight::~Fight() {
}
