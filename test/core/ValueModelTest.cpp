#include <gtest/gtest.h>
#include "../../src/core/ValueModel.h"
using namespace core;


TEST(ValueModel,ValueModelEvaluate){
    ValueModel<int> v(12);
    ASSERT_EQ(v.evaluate(),12);
}

TEST(ValueModel, ValueModelSetValue){
    ValueModel<int> v(12);
    ASSERT_EQ(v.evaluate(),12);
    v.setValue(15);
    ASSERT_EQ(v.evaluate(),15);
}