//
// Created by lesli on 03/05/2020.
//
#include <gtest/gtest.h>
#include "../../src/fuzzy/IsGaussian.h"
#include "../../src/core/ValueModel.h"

TEST(IsGaussian, evaluateFloat){
    ValueModel<float> v(1.0f);
    IsGaussian<float> op(1.0f, 1.0f);
    ASSERT_EQ(op.evaluate(&v), 0.799178f);

}

TEST(IsGaussian, evaluateDouble){
    ValueModel<double> v(1.0);
    IsGaussian<double> op(2.0, 2.0);
    ASSERT_EQ(op.evaluate(&v), 0.799178);
}