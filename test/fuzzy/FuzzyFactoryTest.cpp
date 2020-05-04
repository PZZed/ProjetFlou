#include <gtest/gtest.h>
#include "../../src/fuzzy/FuzzyFactory.h"
#include "../../src/core/ValueModel.h"
#include "../../src/fuzzy/AndMult.h"
#include "../../src/fuzzy/OrMax.h"
#include "../../src/fuzzy/ThenMin.h"
#include "../../src/fuzzy/AggMax.h"
#include "../../src/fuzzy/NotMinus1.h"
#include "../../src/fuzzy/IsTriangle.h"
#include "../../src/fuzzy/AndMin.h"

using namespace fuzzy;


TEST(FuzzyFactory,newAnd){
    ValueModel<float> model1(10);
    ValueModel<float> model2(20);
    AndMult<float> andm;
    OrMax<float> orMax;
    ThenMin<float> thenMin;
    MamdaniDeFuzz<float> defuzz(0,10,1);
    AggMax<float> aggMax;
    NotMinus1<float> notMinus1;
    FuzzyFactory<float> f(&andm,&orMax,&thenMin,&defuzz,&aggMax, &notMinus1);
    f.changeAnd(&andm);
    ASSERT_EQ(f.newAnd(&model1,&model2)->evaluate(),model1.evaluate()*model2.evaluate());

}



TEST(FuzzyFactory,newOr){
    ValueModel<float> model1(10);
    ValueModel<float> model2(20);
    AndMult<float> andm;
    OrMax<float> orMax;
    ThenMin<float> thenMin;
    MamdaniDeFuzz<float> defuzz(0,10,1);
    AggMax<float> aggMax;
    NotMinus1<float> notMinus1;
    FuzzyFactory<float> f(&andm,&orMax,&thenMin,&defuzz,&aggMax, &notMinus1);
    ASSERT_EQ(f.newOr(&model1,&model2)->evaluate(),model2.evaluate());

}



TEST(FuzzyFactory,newThen){
    ValueModel<float> model1(10);
    ValueModel<float> model2(20);
    AndMult<float> andm;
    OrMax<float> orMax;
    ThenMin<float> thenMin;
    MamdaniDeFuzz<float> defuzz(0,10,1);
    AggMax<float> aggMax;
    NotMinus1<float> notMinus1;
    FuzzyFactory<float> f(&andm,&orMax,&thenMin,&defuzz,&aggMax, &notMinus1);
    ASSERT_EQ(f.newThen(&model1,&model2)->evaluate(),model1.evaluate());

}



TEST(FuzzyFactory,newDefuzz){

}


TEST(FuzzyFactory,newAgg){
    ValueModel<float> model1(10);
    ValueModel<float> model2(20);
    AndMult<float> andm;
    OrMax<float> orMax;
    ThenMin<float> thenMin;
    MamdaniDeFuzz<float> defuzz(0,10,1);
    AggMax<float> aggMax;
    NotMinus1<float> notMinus1;
    FuzzyFactory<float> f(&andm,&orMax,&thenMin,&defuzz,&aggMax, &notMinus1);
    ASSERT_EQ(f.newAgg(&model1,&model2)->evaluate(),model2.evaluate());

}


TEST(FuzzyFactory,newNot){
    ValueModel<float> model1(0.5);
    AndMult<float> andm;
    OrMax<float> orMax;
    ThenMin<float> thenMin;
    MamdaniDeFuzz<float> defuzz(0,10,1);
    AggMax<float> aggMax;
    NotMinus1<float> notMinus1;
    FuzzyFactory<float> f(&andm,&orMax,&thenMin,&defuzz,&aggMax, &notMinus1);
    ASSERT_EQ(f.newNot(&model1)->evaluate(),1-model1.evaluate());

}


TEST(FuzzyFactory,newIs){
    ValueModel<float> model1(7.0f);
    AndMult<float> andm;
    OrMax<float> orMax;
    ThenMin<float> thenMin;
    MamdaniDeFuzz<float> defuzz(0,10,1);
    AggMax<float> aggMax;
    NotMinus1<float> notMinus1;
    FuzzyFactory<float> f(&andm,&orMax,&thenMin,&defuzz,&aggMax, &notMinus1);
    IsTriangle<float> ist(5,10,15);
    std::cout << f.newIs(&ist,&model1)->evaluate() << std::endl;
    ASSERT_EQ(f.newIs(&ist,&model1)->evaluate(),0.4f);

}


TEST(FuzzyFactory,changeAnd){
    ValueModel<float> model1(0.5);
    ValueModel<float> model2(0.6);

    AndMult<float> andm;
    AndMin<float> andMin;
    OrMax<float> orMax;
    ThenMin<float> thenMin;
    MamdaniDeFuzz<float> defuzz(0,10,1);
    AggMax<float> aggMax;
    NotMinus1<float> notMinus1;
    FuzzyFactory<float> f(&andm,&orMax,&thenMin,&defuzz,&aggMax, &notMinus1);
    f.changeAnd(&andMin);
    //TODO getter ?

}


TEST(FuzzyFactory,changeOr){

}



TEST(FuzzyFactory,changeThen){

}


TEST(FuzzyFactory,changeAgg){

}




