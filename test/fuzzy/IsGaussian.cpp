//
// Created by lesli on 03/05/2020.
//
#include <gtest/gtest.h>
#include "../../src/fuzzy/IsGaussian.h"
#include "../../src/core/ValueModel.h"

TEST(IsGaussian, evaluateFloat){
    core::ValueModel<float> v(1.0f);
    fuzzy::IsGaussian<float> op(1.0f, 1.0f);
    ASSERT_NEAR(op.evaluate(&v), 0.398942f,0.00001f);
}

TEST(IsGaussian, evaluateDouble){
    core::ValueModel<double> v(1.0);
    fuzzy::IsGaussian<double> op(2.0, 2.0);
    ASSERT_NEAR(op.evaluate(&v), 0.176033,0.000001);
}