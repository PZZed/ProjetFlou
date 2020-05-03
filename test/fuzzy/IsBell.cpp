//
// Created by lesli on 03/05/2020.
//
#include <gtest/gtest.h>
#include "../../src/fuzzy/IsBell.h"
#include "../../src/core/ValueModel.h"


TEST(IsBell, evaluateFloat){
    ValueModel<float> v(1.0f);
    IsBell<float> op(1.0f, 1.0f, 0.0f);
    ASSERT_EQ(op.evaluate(&v), 0.25f);


}

TEST(IsBell, evaluateDouble){
    ValueModel<double> v(1.0);
    IsTrapeze<double> op(1.0, 1.0, 0.0);
    ASSERT_EQ(op.evaluate(&v), 0.25);
}