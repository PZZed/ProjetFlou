#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H
#include "../core/NaryExpression.h"

namespace fuzzy{
    template <class T>
    class SugenoConclusion : public core::NaryExpresssion<T>{
    public:
        T coeff[];
        virtual T evaluate(core::Expression<T>[])const ;
    };

    template <class T>
    T SugenoConclusion<T>::evaluate(core::Expression<T>[])const{

    }

}
#endif //SUGENOCONCLUSION_H
