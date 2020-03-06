#include <iostream>
#include "core/ValueModel.h"

#include "core/UnaryExpressionModel.h"
#include "core/BinaryExpressionModel.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/IsGaussian.h"
#include "fuzzy/IsBell.h"

using namespace core;
using namespace std;
using namespace fuzzy;

int main() {

    IsBell<float> bell(0,1,2);
    IsGaussian<float> gaussian(0,1);
    ValueModel<float> m(12.f);

    cout << bell.evaluate(&m);
    return 0;
}