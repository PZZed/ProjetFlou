//
// Created by pisel on 29/01/2020.
//

#ifndef PROJETFLOU_ANDMIN_H
#define PROJETFLOU_ANDMIN_H

#include "../core/BinaryExpression.h"
#include "And.h"
#include "../core/Expression.h"

namespace fuzzy{
    template <class T>
class AndMin : public And<T> {



public:
    AndMin();
    T evaluate(core::Expression<T>* l,core::Expression<T>* r);

};

    template<class T>
    T AndMin<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) {
        return l->evaluate() < r->evaluate() ? l->evaluate() : r->evaluate();
    }

    template<class T>
    AndMin<T>::AndMin() {}


}

#endif //PROJETFLOU_ANDMIN_H
