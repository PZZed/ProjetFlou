#include <gtest/gtest.h>
#include "../../src/fuzzy/IsTriangle.h"
#include "../../src/core/ValueModel.h"

using namespace fuzzy;
using namespace core;


TEST(IsTriangle,evaluateFloat){
    ValueModel<float> v(7.f);
    IsTriangle<float> op(5.0f,10.0f,15.0f);
    ASSERT_EQ(op.evaluate(&v),0.4f);
    v.setValue(7.5f);
    ASSERT_EQ(op.evaluate(&v),0.5f);
    v.setValue(12.5f);
    ASSERT_EQ(op.evaluate(&v),0.5f);
}

TEST(IsTriangle,evaluateDouble){
    ValueModel<double> v(7.);
    IsTriangle<double> op(5.0,10.0,15.0);
    ASSERT_EQ(op.evaluate(&v),0.4);
    v.setValue(7.5);
    ASSERT_EQ(op.evaluate(&v),0.5);
    v.setValue(12.5);
    ASSERT_EQ(op.evaluate(&v),0.5);

}