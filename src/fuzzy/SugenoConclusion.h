#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H
#include "../core/NaryExpression.h"

namespace fuzzy{
    template <class T>
    class SugenoConclusion : public core::NaryExpresssion<T>{
    public:
        T coeff[];
        SugenoConclusion(T coeff[]);
        T* allocate(T coeff[]);
        ~SugenoConclusion();
        virtual T evaluate(core::Expression<T>[])const;
    };

    template<class T>
    SugenoConclusion<T>::SugenoConclusion(T coeff[]) : coeff(allocate(coeff)){

    }

    template<class T>
    SugenoConclusion<T>::~SugenoConclusion() {
        delete[] coeff;
    }

    template <class T>
    T SugenoConclusion<T>::evaluate(core::Expression<T> tab[]) const{
        std::cout << (sizeof(tab)/ sizeof(*tab));
    }

    template<class T>
    T *SugenoConclusion<T>::allocate(T *coeff) {
        this->coeff = new T[sizeof(coeff)/ sizeof(*coeff)];
        for(size_t i = 0 ; i < sizeof(coeff)/ sizeof(*coeff);i++){
            this->coeff[i] = coeff[i];
        }
    }

}
#endif //SUGENOCONCLUSION_H
