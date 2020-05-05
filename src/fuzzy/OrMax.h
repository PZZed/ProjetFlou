//
// Created by pisel on 29/01/2020.
//

#ifndef ORMAX_H
#define ORMAX_H


#include "../core/BinaryExpression.h"
#include "Or.h"
#include "../core/Expression.h"

namespace fuzzy{
    template <class T>
    class OrMax : public Or<T> {
    public:
        OrMax();

    public:
       virtual T evaluate(const core::Expression<T>* l,const core::Expression<T>* r)const;
    };

    template<class T>
    T OrMax<T>::evaluate(const core::Expression<T>* l, const core::Expression<T>* r)const {
        return l->evaluate() > r->evaluate() ? l->evaluate() : r->evaluate();
    }

    template<class T>
    OrMax<T>::OrMax() {}


}

#endif //ORMAX_H
