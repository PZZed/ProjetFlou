#include <gtest/gtest.h>
#include "../../src/core/ValueModel.h"
#include "../../src/fuzzy/OrMax.h"

using namespace fuzzy;
using namespace core;


TEST(OrMaxTest,evaluateDouble){
    OrMax<double> op;
    ValueModel<double> model1(13.0);
    ValueModel<double> model2(15.0);
    ASSERT_EQ(op.evaluate(&model1,&model2),  model2.evaluate());
}

TEST(OrMaxTest,evaluateFloat){
    OrMax<float> op;
    ValueModel<float> model1(13.0f);
    ValueModel<float> model2(15.0f);
    ASSERT_EQ(op.evaluate(&model1,&model2), model2.evaluate());
}