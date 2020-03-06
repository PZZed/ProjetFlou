#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H
#include "../core/NaryExpression.h"

namespace fuzzy{
    template <class T>
    class SugenoConclusion : public core::NaryExpresssion<T>{
    public:
        SugenoConclusion();
        virtual ~SugenoConclusion();

        virtual T evaluate(core::Expression<T>[])const ;
    private:
        T coeff[];
    };

    template <class T>
    SugenoConclusion:<T>:SugenoConclusion() : coeff(new T[10]){}
    template <class T>

    SugenoConclusion<T>::~SugenoConclusion(){
        delete[] coeff;
    }

    template <class T>
    T SugenoConclusion<T>::evaluate(core::Expression<T>[] expr)const{
        //TODO changer le 10.
        T num = coeff[0] * expr[0].evaluate();
        T den = expr[0];
        for(unsigned int i = 1 ; i < 10 ; i++){
            num += coeff[i]*expr[i].evaluate();
            den + = expr[i];
        }
        return num / den;
    }
}
#endif //SUGENOCONCLUSION_H
