//
// Created by pisel on 29/01/2020.
//

#ifndef THENMIN_H
#define THENMIN_H


#include "../core/BinaryExpression.h"
#include "Then.h"
#include "../core/Expression.h"

namespace fuzzy{
    template <class T>
    class ThenMin : public Then<T> {
    public:
        ThenMin();

    public:
        virtual T evaluate(const core::Expression<T>* l, const core::Expression<T>* r)const;
    };

    template<class T>
    T ThenMin<T>::evaluate(const core::Expression<T>* l,const core::Expression<T>* r) const{
        return l->evaluate() < r->evaluate() ? l->evaluate() : r->evaluate();
    }

    template<class T>
    ThenMin<T>::ThenMin() {}


}


#endif //THENMIN_H
