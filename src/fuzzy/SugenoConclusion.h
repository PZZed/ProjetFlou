#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include <vector>
#include "../core/NaryExpression.h"

namespace fuzzy{
    template <class T>
    class SugenoConclusion : public core::NaryExpression<T>{
    public:
        SugenoConclusion(const std::vector<T>*);
        ~SugenoConclusion();
        virtual T evaluate(const std::vector<core::Expression<T>*>*)const;
    private:
       const std::vector<T>* coeff;
    };

    template<class T>
    SugenoConclusion<T>::SugenoConclusion(const std::vector<T>* tab) : coeff(tab){}

    template<class T>
    SugenoConclusion<T>::~SugenoConclusion() { }

    template <class T>
    T SugenoConclusion<T>::evaluate(const std::vector<core::Expression<T>*>* operande) const{
        T z = 0;
        typename std::vector<core::Expression<T>*>::const_iterator itExp = operande->begin();
        for(typename std::vector<T>::const_iterator it=coeff->begin();it !=coeff->end()&&itExp!=operande->end();it++,itExp++){
            T eval = (*itExp)->evaluate();
            z+=(*it) * eval;
        }
        return z;
    }

}
#endif //SUGENOCONCLUSION_H
