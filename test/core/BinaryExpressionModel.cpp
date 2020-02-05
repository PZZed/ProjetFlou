//
// Created by pz on 05/02/2020.
//

#include <gtest/gtest.h>
#include "../../src/core/BinaryExpressionModel.h"
#include "../../src/core/UnaryExpressionModel.h"
#include "../../src/core/ValueModel.h"

#include "../../src/fuzzy/AndMin.h"
#include "../../src/fuzzy/IsTriangle.h"

using namespace fuzzy;

TEST(BinaryExpression,evaluate){

    core::ValueModel<float> food(8);
    core::ValueModel<float> service(3);

    IsTriangle<float> excellent(7.f,8.f,10.f);
    IsTriangle<float> bad(0.f,2.f,4.f);

    core::UnaryExpressionModel<float> left(&food,&excellent);
    core::UnaryExpressionModel<float> right(&service,&bad);


    AndMin<float> amin;
    core::BinaryExpressionModel<float> binaryExpressionModel(&left,&right,&amin);
    ASSERT_EQ(binaryExpressionModel.evaluate(),0.5f);
}