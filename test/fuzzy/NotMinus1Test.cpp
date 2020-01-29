#include <gtest/gtest.h>
#include "../../src/fuzzy/NotMinus1.h"
#include "../../src/core/ValueModel.h"
using namespace fuzzy;


TEST(NotMinus1,evaluate){
    NotMinus1<float> op;
    core::ValueModel<float> v(0.15);
    ASSERT_EQ(op.evaluate(&v), 1-v.evaluate());
}