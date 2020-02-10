#include <gtest/gtest.h>
#include "../../src/fuzzy/IsTrapeze.h"
#include "../../src/core/ValueModel.h"

using namespace fuzzy;
using namespace core;


TEST(IsTrapeze, evaluateFloat){
    ValueModel<float> v(7.0f);
    IsTrapeze<float> op(5.0f, 10.0f, 15.0f, 20.0f);
    ASSERT_EQ(op.evaluate(&v), 0.4f);
    v.setValue(7.5f);
    ASSERT_EQ(op.evaluate(&v), 0.5f);
    v.setValue(10.0f);
    ASSERT_EQ(op.evaluate(&v), 1.0f);
    v.setValue(12.0f);
    ASSERT_EQ(op.evaluate(&v), 1.0f);
    v.setValue(17.5f);
    ASSERT_EQ(op.evaluate(&v), 0.5f);
}

TEST(IsTrapeze, evaluateDouble){
    ValueModel<double> v(7.0);
    IsTrapeze<double> op(5.0, 10.0, 15.0, 20.0);
    ASSERT_EQ(op.evaluate(&v), 0.4);
    v.setValue(7.5);
    ASSERT_EQ(op.evaluate(&v), 0.5);
    v.setValue(10.0);
    ASSERT_EQ(op.evaluate(&v), 1.0);
    v.setValue(12.0);
    ASSERT_EQ(op.evaluate(&v), 1.0);
    v.setValue(17.5);
    ASSERT_EQ(op.evaluate(&v), 0.5);
}

TEST(IsTrapeze, evaluateFalling){
    ValueModel<float> v(7.0f);
    IsTrapeze<float> op(10.0f, 10.0f, 15.0f, 20.0f);
    ASSERT_EQ(op.evaluate(&v), 1.0f);
    v.setValue(12.0f);
    ASSERT_EQ(op.evaluate(&v), 1.0f);
    v.setValue(17.5f);
    ASSERT_EQ(op.evaluate(&v), 0.5f);
    v.setValue(22.0f);
    ASSERT_EQ(op.evaluate(&v), 0.0f);
}

TEST(IsTrapeze, evaluateRising){
    ValueModel<float> v(7.0f);
    IsTrapeze<float> op(5.0f, 10.0f, 15.0f, 15.0f);
    ASSERT_EQ(op.evaluate(&v), 0.4f);
    v.setValue(12.0f);
    ASSERT_EQ(op.evaluate(&v), 1.0f);
    v.setValue(17.5f);
    ASSERT_EQ(op.evaluate(&v), 1.0f);
    v.setValue(2.0f);
    ASSERT_EQ(op.evaluate(&v), 0.0f);
}