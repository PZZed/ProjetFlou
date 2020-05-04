#include <gtest/gtest.h>
#include "../../src/core/ValueModel.h"
#include "../../src/fuzzy/IsGaussian.h"

using namespace fuzzy;
using namespace core;



TEST(isGaussianTest,evaluateDouble){
    ValueModel<float> v(7.f);
    IsGaussian<float> gaus(0.5f,2.f);

    ASSERT_EQ();


}

TEST(isGaussianTest,evaluatefloat){
    AggMax<float> op;
    ValueModel<float> model1(13.0f);
    ValueModel<float> model2(15.0f);
    ASSERT_EQ(op.evaluate(&model1,&model2), model2.evaluate());
}
