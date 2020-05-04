//
// Created by pisel on 29/01/2020.
//

#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include <vector>
#include "MamdaniDeFuzz.h"
#include "../core/BinaryExpression.h"
#include "Shape.h"

namespace fuzzy{
    template <class T>
    class CogDeFuzz : public MamdaniDeFuzz<T> {
    public:
        CogDeFuzz(const T& min,const T& max,const T& step);
        virtual ~CogDeFuzz() {};
        virtual T defuzzification(const Shape<T> &s)const;
        virtual T evaluate(core::Expression<T> * l, core::Expression<T> * r) const;
    };


    template<class T>
    T CogDeFuzz<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        Shape<T> s = Shape<T>::buildShape(this->getMin(),this->getMax(),this->getStep(),l,r);
        return defuzzification(s);
    }

    template<class T>
    T CogDeFuzz<T>::defuzzification(const Shape<T> &s) const {
        std::vector<T> xs = s.getXAxis();
        std::vector<T> ys = s.getYAxis();
        float suma = 0;
        float sumb = 0;
        for (unsigned int i = 0; i< xs.size(); i++){
            suma += xs[i]*ys[i];
            sumb += ys[i];
        }
        return suma/sumb;
    }

    template<class T>
    CogDeFuzz<T>::CogDeFuzz(const T &min, const T &max, const T &step)
    : MamdaniDeFuzz<T>(min, max, step) {}

}


#endif //COGDEFUZZ_H