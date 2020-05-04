//
// Created by pz on 04/05/2020.
//

#include <gtest/gtest.h>
#include "../../src/core/UnaryShadowExpression.h"
#include "../../src/fuzzy/NotMinus1.h"

TEST(UnaryShadow,UnaryShadow_Constructor_Test){
    fuzzy::NotMinus1<float> ue;
    core::UnaryShadowExpression<float> use(&ue);
    ASSERT_TRUE(use.getTarget()==&ue);
}

TEST(UnaryShadow,UnaryShadow_Set_Target_Test) {
    fuzzy::NotMinus1<float> ue;
    core::UnaryShadowExpression<float> use;
    ASSERT_TRUE(use.getTarget()!=&ue);
    use.setTarget(&ue);
    ASSERT_TRUE(use.getTarget()==&ue);
    use.setTarget(nullptr);
    ASSERT_TRUE(use.getTarget()==&ue);
}
