//
// Created by pisel on 29/01/2020.
//

#ifndef ORPLUS_H
#define ORPLUS_H

#include "../core/BinaryExpression.h"

#include "../core/BinaryExpression.h"
#include "Or.h"
#include "../core/Expression.h"

namespace fuzzy{
    template <class T>
    class OrPlus : public Or<T> {
    public:
        OrPlus();

    public:
        virtual T evaluate(core::Expression<T>* l,core::Expression<T>* r) const;
    };

    template<class T>
    T OrPlus<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        return l->evaluate() + r->evaluate() ;
    }

    template<class T>
    OrPlus<T>::OrPlus() {}


}


#endif //ORPLUS_H
