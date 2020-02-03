//
// Created by pisel on 29/01/2020.
//

#ifndef AGGMAX_H
#define AGGMAX_H


#include "../core/BinaryExpression.h"
#include "Agg.h"
#include "../core/Expression.h"

namespace fuzzy{
    template <class T>
    class AggMax : public Agg<T> {
    public:
        AggMax();

    public:
        T evaluate(core::Expression<T>* l,core::Expression<T>* r);
    };

    template<class T>
    T AggMax<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) {
        return l->evaluate() > r->evaluate() ? l->evaluate() : r->evaluate();
    }

    template<class T>
    AggMax<T>::AggMax() {}


}


#endif //AGGMAX_H
