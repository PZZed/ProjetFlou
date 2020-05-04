#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include <vector>
#include "../core/NaryExpression.h"

namespace fuzzy{
    template <class T>
    class SugenoConclusion : public core::NaryExpression<T>{
    public:
        SugenoConclusion(std::vector<T>);
        ~SugenoConclusion();
        virtual T evaluate(std::vector<core::Expression<T>*>*)const;
    private:
        std::vector<T> coeff;
    };

    template<class T>
    SugenoConclusion<T>::SugenoConclusion(std::vector<T> tab) : coeff(tab){}

    template<class T>
    SugenoConclusion<T>::~SugenoConclusion() {
        delete[] coeff;
    }

    template <class T>
    T SugenoConclusion<T>::evaluate(std::vector<core::Expression<T>*>* operande) const{
        T z = 0;
        typename std::vector<const core::Expression<T>*>::const_iterator itExp = operande->begin();
        for(typename std::vector<T>::const_iterator it;it !=coeff->end()&&itExp!=operande->end();it++,itExp++){
            T eval = (*it)->evaluate();
            z+=(*itExp)* eval;
        }
        return z;
    }

}
#endif //SUGENOCONCLUSION_H
