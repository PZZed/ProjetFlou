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
    private:
        T cache;
    public:
        SugenoThen(){}
        virtual ~SugenoThen(){}
        T evaluate(core::Expression<T>* l,core::Expression<T>* r);
        T getCache() const;
    };

    template<class T>
    T SugenoThen<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) {
        cache = l->evaluate();
        return cache * r->evaluate();
    }

    template<class T>
    T SugenoThen<T>::getCache() const {
        return cache;
    }

}


#endif //SUGENOTHEN_H
