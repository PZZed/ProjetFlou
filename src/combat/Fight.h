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

using namespace fuzzy;
using namespace core;
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


}

#endif //PROJETFLOU_FIGHT_H
