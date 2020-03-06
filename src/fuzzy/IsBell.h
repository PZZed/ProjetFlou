//
// Created by lesli on 18/02/2020.
//

#ifndef PROJETFLOU_ISBELL_H
#define PROJETFLOU_ISBELL_H

#include <cmath>
#include "Is.h"
#include "../core/Expression.h"


namespace fuzzy {
    template <class T>
    class IsBell : Is<T>{
    public:
        IsBell(const T&, const T& , const T&);
        virtual ~IsBell(){};
        virtual T evaluate(core::Expression<T>*)const;

    private:
        T a;
        T b;
        T c;
    };


    template<class T>
    T IsBell<T>::evaluate(core::Expression<T> * e) const {
        T x = e->evaluate();
        return (1/pow(1+ abs(x-c/a),2*b));
    }

    template<class T>
    IsBell<T>::IsBell(const T & a, const T & b, const T &):a(a) , b(b), c(c)  {
    }
}

#endif //PROJETFLOU_ISBELL_H
