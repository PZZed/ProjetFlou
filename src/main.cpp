#include <iostream>
#include "core/ValueModel.h"

#include "core/UnaryExpressionModel.h"
#include "core/BinaryExpressionModel.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/IsGaussian.h"
#include "fuzzy/IsBell.h"
#include "fuzzy/SugenoConclusion.h"
#include "fuzzy/ThenMin.h"
#include "fuzzy/IsTrapeze.h"
#include "fuzzy/NotMinus1.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/CogDefuzz.h"
#include "fuzzy/FuzzyFactory.h"
#include "fuzzy/AggMax.h"

using namespace core;
using namespace std;
using namespace fuzzy;

int main() {
    NotMinus1<float> opNot;
    AndMin<float> opAnd;
    OrMax<float> opOr;
    ThenMin<float> opThen;
    CogDeFuzz<float> opDefuzz(0,25,1);
    AggMax<float> opAgg;
    SugenoThen<float> opSugThen;
    SugenoDefuzz<float> opSugDefuzz;
    vector<float> coefficient;
    coefficient.push_back(1);
    coefficient.push_back(2);
    coefficient.push_back(3);

    SugenoConclusion<float> opSugCcl(&coefficient);
    //todo rename to fuzzyExpressionFactory
    FuzzyFactory<float> f(&opAnd,&opOr,&opThen,&opDefuzz,&opAgg,&opNot);
    IsTriangle<float> poor(-5,0,5);
    IsTriangle<float> good(0,5,10);
    IsTriangle<float> excellent(5,10,15);
    IsTriangle<float> cheap(0,5,10);
    IsTriangle<float> average(10,15,20);
    IsTriangle<float> generous(20,25,30);
    ValueModel<float> service(0);
    ValueModel<float> food(0);
    ValueModel<float> tips(0);
    Expression<float> *r =
            f.newAgg(
                    f.newAgg(
                            f.newThen(
                                    f.newIs(&poor,&service),
                                    f.newIs(&cheap,&tips)
                            ),
                            f.newThen(
                                    f.newIs(&good,&service),
                                    f.newIs(&average,&tips)
                             )
                    ),
            f.newThen(
                    f.newIs(&excellent,&service),
                    f.newIs(&generous,&tips)
                    )
    );
    Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);
    float s;

    // *****************************************************************************************************************

    FuzzyFactory<float> factorySugeno(&opAnd,&opOr,&opSugThen,&opSugDefuzz,&opSugCcl,&opAgg,&opNot);
    vector<Expression<float>*>* regle;
    regle->push_back(f.newAgg(
            f.newAgg(
                    f.newThen(
                            f.newIs(&poor,&service),
                            f.newIs(&cheap,&tips)
                    ),
                    f.newThen(
                            f.newIs(&good,&service),
                            f.newIs(&average,&tips)
                    )
            ),
            f.newThen(
                    f.newIs(&excellent,&service),
                    f.newIs(&generous,&tips)
            )
    ));
    Expression<float> *system2 = f.newDefuzz(&tips, r, 0, 25, 1);

    // *****************************************************************************************************************
    while(true)
    {
        cout << "service : ";cin >> s;
        service.setValue(s);
        cout << "food : ";cin >> s;
        food.setValue(s);
        cout << "tips -> " << system2->evaluate() << endl;
    }

    return 0;
}