//
// Created by pisel on 29/01/2020.
//

#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H


#include "../core/BinaryExpression.h"
#include "Then.h"
#include "../core/Expression.h"

namespace fuzzy{
    template <class T>
    class SugenoThen : public Then<T> {

        T evaluate(core::Expression<T>* l,core::Expression<T>* r);
    };

    template<class T>
    T SugenoThen<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) {
        return nullptr;
    }


}


#endif //SUGENOTHEN_H
