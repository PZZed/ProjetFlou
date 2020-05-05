#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H


#include "../core/ExpressionFactory.h"
#include "../core/UnaryShadowExpression.h"



#include "Is.h"
#include "And.h"
#include "Or.h"
#include "Then.h"
#include "Agg.h"
#include "MamdaniDeFuzz.h"
#include "Not.h"
#include "../core/NaryShadowExpression.h"
#include "SugenoConclusion.h"
#include "SugenoDefuzz.h"

using namespace core;

namespace fuzzy{
    template <class T>
    class FuzzyFactory: protected ExpressionFactory<T>{
        public:
            FuzzyFactory(And<T>*,Or<T>*,Then<T>*,MamdaniDeFuzz<T>*,Agg<T>*,Not<T>*);
            FuzzyFactory(And<T>*,Or<T>*,Then<T>*,SugenoDefuzz<T>*,SugenoConclusion<T>*,Agg<T>*,Not<T>*);
            virtual ~FuzzyFactory();
            virtual Expression<T>* newAnd(Expression<T>* l, Expression<T>* r);
            virtual Expression<T>* newOr(Expression<T>* l, Expression<T>* r);
            virtual Expression<T>* newThen(Expression<T>* l, Expression<T>* r);
            virtual Expression<T>* newDefuzz(Expression<T>* l, Expression<T>* r);
            virtual Expression<T>* newDefuzz(Expression<T>* l, Expression<T>* r,const T& min,const T&max,const T&step);
            virtual Expression<T>* newAgg(Expression<T>* l, Expression<T>* r);
            virtual Expression<T>* newNot(Expression<T>* o);
            virtual Expression<T>* newIs(Is<T>* is,Expression<T>* o);
            virtual Expression<T>* newSugenoDefuzz(std::vector<Expression<T>*>*);
            virtual Expression<T>* newSugenoConclusion(std::vector<Expression<T>*>*);
            virtual void changeAnd(const And<T>* a);
            virtual void changeOr(const Or<T>* o);
            virtual void changeThen(const Then<T>* t);
            virtual void changeAgg(const Agg<T>* a);
            virtual void changeCcl(const SugenoConclusion<T>* sc);
            virtual void changeSugenoDeffuz(const SugenoDefuzz<T>* sdf);


    private:
        BinaryShadowExpression<T> *and_,*or_,*then_, *agg_,*defuzz_;
        UnaryShadowExpression<T> *not_;
        NaryShadowExpression<T> *sugenoDefuzz,*sugenoCcl;
};
    template<class T>
    Expression<T> *FuzzyFactory<T>::newAnd(Expression<T> *l, Expression<T> *r) {
        return this->newBinary(and_,l,r);
    }

    template<class T>
    void FuzzyFactory<T>::changeAnd(const And<T> *a) {
        this->and_->setTarget(a);
    }

    template<class T>
    void FuzzyFactory<T>::changeOr(const Or<T> *o) {
        this->or_->setTarget(o);
    }

    template<class T>
    void FuzzyFactory<T>::changeThen(const Then<T> *t) {
        this->then_->setTarget(t);
    }

    template<class T>
    void FuzzyFactory<T>::changeAgg(const Agg<T>* a) {
        this->agg_->setTarget(a);
    }

    template<class T>
    Expression<T> *FuzzyFactory<T>::newOr(Expression<T> *l, Expression<T> *r) {
        std::cout << or_->getTarget()<<std::endl;
        return this->newBinary(or_,l,r);
    }

    template<class T>
    Expression<T> *FuzzyFactory<T>::newThen(Expression<T> *l, Expression<T> *r) {
        return this->newBinary(then_,l,r);
    }

    template<class T>
    Expression<T> *FuzzyFactory<T>::newDefuzz(Expression<T> *l, Expression<T> *r) {
        return this->newBinary(defuzz_,l,r);
    }

    template<class T>
    Expression<T> *FuzzyFactory<T>::newAgg(Expression<T> *l, Expression<T> *r) {
        return this->newBinary(agg_,l,r);
    }

    template<class T>
    Expression<T> *FuzzyFactory<T>::newNot(Expression<T> *o) {
        return this->newUnary(not_,o);
    }

    template<class T>
    Expression<T> *FuzzyFactory<T>::newIs(Is<T> *is, Expression<T> *o) {
        return this->newUnary(is,o);
    }

    template<class T>
    FuzzyFactory<T>::FuzzyFactory(And<T> *_and, Or<T> *_or, Then<T> *_then, MamdaniDeFuzz<T> *_defuzz, Agg<T> *_agg, Not<T> *_not) :
     and_(new BinaryShadowExpression<T>(_and)),or_(new BinaryShadowExpression<T>(_or)),then_(new BinaryShadowExpression<T>(_then)),defuzz_(new BinaryShadowExpression<T>(_defuzz)),agg_(new BinaryShadowExpression<T>(_agg)),not_(new UnaryShadowExpression<T>(_not)),sugenoCcl(nullptr),sugenoDefuzz(
            nullptr)
    {}

    template<class T>
    FuzzyFactory<T>::~FuzzyFactory() {
        delete or_;
        delete and_;
        delete then_;
        if(defuzz_!= nullptr)
            delete defuzz_;
        delete agg_;
        delete not_;
        if(sugenoCcl!= nullptr)
        delete sugenoCcl;
        if(sugenoDefuzz!=nullptr)
        delete sugenoDefuzz;
    }

    template<class T>
    Expression<T> *FuzzyFactory<T>::newDefuzz(Expression<T> *l, Expression<T> *r, const T &min,const T &max,const T &step) {
        auto* t = (MamdaniDeFuzz<T>*) defuzz_->getTarget();
        t->setMin(min);
        t->setMax(max);
        t->setStep(step);
        return this->newBinary(defuzz_,l,r);
    }

    template<class T>
    Expression<T> *FuzzyFactory<T>::newSugenoDefuzz(std::vector<Expression<T> *> *operands) {
        return this->newNary(sugenoDefuzz,operands);
    }

    template<class T>
    Expression<T> *FuzzyFactory<T>::newSugenoConclusion(std::vector<Expression<T> *> *operands) {
        return this->newNary(sugenoCcl,operands);
    }

    template<class T>
    void FuzzyFactory<T>::changeCcl(const SugenoConclusion<T> *sc) {
        this->sugenoCcl->setTarget(sc);
    }

    template<class T>
    void FuzzyFactory<T>::changeSugenoDeffuz(const SugenoDefuzz<T> *sdf) {
        this->sugenoDefuzz->setTarget(sdf);
    }

    template<class T>
    FuzzyFactory<T>::FuzzyFactory(And<T> *_and, Or<T> *_or, Then<T> *_then, SugenoDefuzz<T> *_sugDefuzz, SugenoConclusion<T> *_sugCcl, Agg<T> *_agg,
                                  Not<T> *_not) : and_(new BinaryShadowExpression<T>(_and)),or_(new BinaryShadowExpression<T>(_or)),then_(new BinaryShadowExpression<T>(_then)),sugenoDefuzz(new NaryShadowExpression<T>(_sugDefuzz)),sugenoCcl(new NaryShadowExpression<T>(_sugCcl)),agg_(new BinaryShadowExpression<T>(_agg)),not_(new UnaryShadowExpression<T>(_not)),defuzz_(
            nullptr) {}

}

#endif