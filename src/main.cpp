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

using namespace core;
using namespace std;
using namespace fuzzy;

int main() {
    float t[] = {5.f, 6.f};
   // SugenoConclusion<float> s(t);
    IsTriangle<float> op(5.0f,10.0f,15.0f);
    IsTriangle<float> op2(5.0f,10.0f,15.0f);
    IsTriangle<float> tab[] = {op,op2,op};
    std::cout << (sizeof(tab)/ sizeof(*tab));

    IsBell<float> bell(0,1,2);
    IsGaussian<float> gaussian(0,1);
    ValueModel<float> m(12.f);

    cout << bell.evaluate(&m);

    return 0;
}