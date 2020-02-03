//
// Created by pisel on 29/01/2020.
//

#ifndef THENMULT_H
#define THENMULT_H


#include "../core/BinaryExpression.h"
#include "Then.h"
#include "../core/Expression.h"

namespace fuzzy{
    template <class T>
    class ThenMult : public Then<T> {
    public:
        ThenMult();

    public:
        virtual T evaluate(core::Expression<T>* l,core::Expression<T>* r)const;
    };

    template<class T>
    T ThenMult<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const{
        return l->evaluate() * r->evaluate() ;
    }

    template<class T>
    ThenMult<T>::ThenMult() {}


}


#endif //THENMULT_H
