#ifndef ISGAUSSIAN_H
#define ISGAUSSIAN_H

#include <cmath>
#include "Is.h"
#include "../core/Expression.h"


namespace fuzzy{
    template <class T>
    class IsGaussian : public Is<T>{
    public:
        IsGaussian(const T&, const T&);
        virtual ~IsGaussian(){};
        virtual T evaluate(core::Expression<T>*)const;

    private:
        T variance;
        T ecartType;
    };

    template<class T>
    T IsGaussian<T>::evaluate(core::Expression<T> * e) const {
        T x = e->evaluate();
        return 2.5068 * exp(-1*((x-ecartType)*(x-ecartType)) / (2*variance*variance)) / sqrt(2*3.141592653589793238);
    }

    template<class T>
    IsGaussian<T>::IsGaussian(const T &variance, const T &ecartType) : variance(variance) , ecartType(ecartType) {}
}

#endif