//
// Created by pisel on 05/05/2020.
//

#ifndef PROJETFLOU_FIGHT_H
#define PROJETFLOU_FIGHT_H

#include <string>
#include <iostream>
#include "../fuzzy/IsTriangle.h"
#include "../core/ValueModel.h"
#include "../fuzzy/FuzzyFactory.h"
#include "../fuzzy/NotMinus1.h"
#include "../fuzzy/OrMax.h"
#include "../fuzzy/AndMin.h"
#include "../fuzzy/CogDefuzz.h"
#include "../fuzzy/ThenMin.h"
#include "../fuzzy/AggMax.h"
#include "../combat/Player.h"
#include "../combat/Enemy.h"


using namespace fuzzy;
using namespace core;



namespace combat{
    class Fight{
        public :
            Fight(std::string statFile,  Player &p, Enemy &e);
            virtual ~Fight();
            void startFight();

    private:
        std::string statFile;
        Enemy & e;
        Player & p;
    };


}

#endif //PROJETFLOU_FIGHT_H
