#include <iostream>
#include "core/ValueModel.h"

#include "core/UnaryExpressionModel.h"
#include "core/BinaryExpressionModel.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/IsGaussian.h"
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

    //s.evaluate(reinterpret_cast<Expression<float> *>(tab));
    return 0;
}