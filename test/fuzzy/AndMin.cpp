#include <gtest/gtest.h>
#include "../../src/core/ValueModel.h"
#include "../../src/fuzzy/AndMin.h"

using namespace fuzzy;
using namespace core;


TEST(AndMinTest,evaluateDouble){
    AndMin<double> op;
    ValueModel<double> model1(13.0);
    ValueModel<double> model2(15.0);
    ASSERT_EQ(op.evaluate(&model1,&model2), model1.evaluate());
}

TEST(AndMinTest,evaluateFloat){
    AndMin<float> op;
    ValueModel<float> model1(13.0f);
    ValueModel<float> model2(15.0f);
    ASSERT_EQ(op.evaluate(&model1,&model2), model1.evaluate());
}