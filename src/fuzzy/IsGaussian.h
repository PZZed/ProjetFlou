#include <cmath>
#include "Is.h"
#include "../core/Expression.h"
#include <

namespace fuzzy{
    template <class T>
    class IsGaussian : Is<T>{
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
        return (exp(-1*((x-ecartType)*(x-ecartType))/(2*variance*variance))/ ( variance* sqrt(2*M_PI)));
    }

    template<class T>
    IsGaussian<T>::IsGaussian(const T & variance, const T& ecartType) : variance(variance) , ecartType(ecartType) {}
}