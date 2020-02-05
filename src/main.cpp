#include <iostream>
#include "core/ValueModel.h"

#include "core/UnaryExpressionModel.h"
#include "core/BinaryExpressionModel.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/IsTriangle.h"

using namespace core;
using namespace std;
using namespace fuzzy;

int main() {


    ValueModel<float> food(8);
    ValueModel<float> service(3);

    IsTriangle<float> excellent(7.f,8.f,10.f);
    IsTriangle<float> bad(0.f,2.f,4.f);

    UnaryExpressionModel<float> left(&food,&excellent);
    UnaryExpressionModel<float> right(&service,&bad);
    cout << left.evaluate() << " left"<< endl;
    cout << right.evaluate() << " right"<< endl;



    AndMin<float> amin;
    BinaryExpressionModel<float> binaryExpressionModel(&left,&right,&amin);
    cout << binaryExpressionModel.evaluate();



    return 0;
}