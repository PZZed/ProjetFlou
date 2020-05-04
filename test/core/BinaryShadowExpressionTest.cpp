//
// Created by pz on 04/05/2020.
//

#include <gtest/gtest.h>
#include "../../src/core/BinaryShadowExpression.h"
#include "../../src/fuzzy/AndMin.h"
#include "../../src/fuzzy/AndMult.h"

TEST(BinaryShadow,BinaryShadow_Constructor_Test){
    fuzzy::AndMin<float> binaryExpression;
    core::BinaryShadowExpression<float> bse(&binaryExpression);
    ASSERT_TRUE(bse.getTarget()==&binaryExpression);
}

TEST(BinaryShadow,BinaryShadow_BinaryShadow_SET_TARGET){
    fuzzy::AndMin<float> binaryExpression;
    fuzzy::AndMult<float> binaryExpression2;
    core::BinaryShadowExpression<float> bse(&binaryExpression);
    ASSERT_TRUE(bse.getTarget()==&binaryExpression);
    bse.setTarget(&binaryExpression2);
    ASSERT_TRUE(bse.getTarget()==&binaryExpression2);
    bse.setTarget(nullptr);
    ASSERT_TRUE(bse.getTarget()==&binaryExpression2);
}