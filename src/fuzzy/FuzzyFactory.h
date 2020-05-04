#include "../core/ExpressionFactory.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/UnaryShadowExpression.h"

#include "Is.h"
#include "And.h"
#include "Or.h"
#include "Then.h"
#include "Agg.h"
#include "MamdaniDefuzz.h"
#include "Not.h"

using namespace core;

namespace fuzzy{
    template <class T>
    class FuzzyFactory: protected ExpressionFactory<T>{
        public:
            FuzzyFactory(And<T>*,Or<T>*,Then<T>*,MamdaniDeFuzz<T>*,Agg<T>*,Not<T>*);
            virtual ~FuzzyFactory();
            virtual Expression<T>* newAnd(Expression<T>* l, Expression<T>* r);
            virtual Expression<T>* newOr(Expression<T>* l, Expression<T>* r);
            virtual Expression<T>* newThen(Expression<T>* l, Expression<T>* r);
            virtual Expression<T>* newDefuzz(Expression<T>* l, Expression<T>* r);
            virtual Expression<T>* newAgg(Expression<T>* l, Expression<T>* r);
            virtual Expression<T>* newNot(Expression<T>* o);
            virtual Expression<T>* newIs(Is<T>* is,Expression<T>* o);
            virtual void changeAnd(const And<T>* a);
            virtual void changeOr(const Or<T>* o);
            virtual void changeThen(const Then<T>* t);
            virtual void changeAgg(const Agg<T>* a);

    private:
        BinaryShadowExpression<T> *and_,*or_,*then_, *agg_,*defuzz_;
        UnaryShadowExpression<T> *not_;
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
     and_(new BinaryShadowExpression<T>(_and)),or_(new BinaryShadowExpression<T>(_or)),then_(new BinaryShadowExpression<T>(_then)),defuzz_(new BinaryShadowExpression<T>(_defuzz)),agg_(new BinaryShadowExpression<T>(_agg)),not_(new UnaryShadowExpression<T>(_not))
    {}

    template<class T>
    FuzzyFactory<T>::~FuzzyFactory() {
        delete or_;
        delete and_;
        delete then_;
        delete defuzz_;
        delete agg_;
        delete not_;
    }

}