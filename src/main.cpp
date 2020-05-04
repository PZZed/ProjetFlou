#include <iostream>
#include "core/ValueModel.h"

#include "core/UnaryExpressionModel.h"
#include "core/BinaryExpressionModel.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/IsGaussian.h"

using namespace core;
using namespace std;
using namespace fuzzy;

int main() {


    IsGaussian<float> gaussian(0, 1);
    ValueModel<float> m(12.f);
    gaussian.evaluate(&m);
    return 0;
}