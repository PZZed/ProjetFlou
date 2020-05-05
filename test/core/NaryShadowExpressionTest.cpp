//
// Created by pz on 04/05/2020.
//

#include <gtest/gtest.h>
#include "../../src/core/NaryShadowExpression.h"
#include "../../src/fuzzy/SugenoConclusion.h"
#include "../../src/core/UnaryExpressionModel.h"
#include "../../src/core/ValueModel.h"
#include "../../src/fuzzy/IsTriangle.h"
#include "../../src/core/BinaryExpressionModel.h"
#include "../../src/fuzzy/AndMin.h"
#include "../../src/core/NaryExpressionModel.h"

using namespace core;
using namespace fuzzy;
TEST(NaryShadowExpression,NaryShadowExpression_Constructor_Test){
    core::ValueModel<float> food(8);
    core::ValueModel<float> service(3);

    IsTriangle<float> excellent(7.f,8.f,10.f);
    IsTriangle<float> bad(0.f,2.f,4.f);

    core::UnaryExpressionModel<float> left(&food,&excellent);
    core::UnaryExpressionModel<float> right(&service,&bad);
    std::vector<Expression<float>*> vec;
    AndMin<float> amin;
    core::BinaryExpressionModel<float> binaryExpressionModel(&left,&right,&amin);
    vec.push_back(reinterpret_cast<Expression<float> *const>(&amin));



}