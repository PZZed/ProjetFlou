//
// Created by pisel on 29/01/2020.
//

#ifndef AGGPLUS_H
#define AGGPLUS_H

#include "../core/BinaryExpression.h"
#include "Agg.h"
#include "../core/Expression.h"

namespace fuzzy{
    template <class T>
    class AggPlus : public Agg<T> {
    public:
        AggPlus();

    public:
       virtual T evaluate(core::Expression<T>* l,core::Expression<T>* r)const;
    };

    template<class T>
    T AggPlus<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        return l->evaluate() + r->evaluate();
    }

    template<class T>
    AggPlus<T>::AggPlus() {}


}

#endif // AGGPLUS_H
