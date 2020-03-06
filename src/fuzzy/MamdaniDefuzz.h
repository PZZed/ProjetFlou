//
// Created by pisel on 29/01/2020.
//

#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H


#include "../core/BinaryExpression.h"

namespace fuzzy{
    template <class T>
    class MamdaniDeFuzz : public core::BinaryExpression<T> {

    public:
        virtual T evaluate(core::Expression<T>[])const ;

    };


    template <class T>
    T MamdaniDeFuzz<T>::evaluate(core::Expression<T>[])const{

    }
}


#endif //MAMDANIDEFUZZ_H
