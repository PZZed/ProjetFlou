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
#include "calculate/Commands.h"

using namespace core;
using namespace std;
using namespace fuzzy;

int main() {

    Commands c;
    c.running();

    return 0;
}