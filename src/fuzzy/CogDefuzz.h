//
// Created by pisel on 29/01/2020.
//

#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include <vector>
#include "MamdaniDefuzz.h"
#include "../core/BinaryExpression.h"

namespace fuzzy{
    template <class T>
class CogDeFuzz : public MamdaniDeFuzz<T> {
    public:
        CogDeFuzz();
        virtual ~CogDeFuzz() {};

        virtual T evaluate(core::Expression<T> * l, core::Expression<T> * r) const;
    };
    template <class T>
    CogDeFuzz<T>::CogDeFuzz()
    {

    }

    template<class T>
    T CogDeFuzz<T>::defuzz(const Shape<T> &s) const {
        std::vector<T> xs =  s.getXs();
        std::vector<T> ys = s.getYs();
        float suma = 0;
        float sumb = 0;
        for (unsigned int i = 0; i< xs.size(); i++){
            suma += xs[i]*ys[i];
            sumb += ys[i];
        }
        return suma/sumb;
    }


}


#endif //COGDEFUZZ_H
