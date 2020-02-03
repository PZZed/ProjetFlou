#include <gtest/gtest.h>
#include "../../src/core/ValueModel.h"
#include "../../src/fuzzy/AggPlus.h"

using namespace fuzzy;
using namespace core;



TEST(AggPlusTest,evaluateDouble){
    AggPlus<double> op;
    ValueModel<double> model1(13.0);
    ValueModel<double> model2(15.0);
    ASSERT_EQ(op.evaluate(&model1,&model2), model1.evaluate()+model2.evaluate());
}

TEST(AggPlusTest,evaluateFloat){
    AggPlus<float> op;
    ValueModel<float> model1(13.0f);
    ValueModel<float> model2(15.0f);
    ASSERT_EQ(op.evaluate(&model1,&model2), model1.evaluate()+model2.evaluate());
}