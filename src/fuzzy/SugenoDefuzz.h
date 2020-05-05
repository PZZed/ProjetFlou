//
// Created by balanche on 1/29/20.
//

#ifndef PROJETFLOU_SUGENODEFUZZ_H
#define PROJETFLOU_SUGENODEFUZZ_H

#include <vector>
#include "../core/NaryExpression.h"
#include "../core/BinaryExpression.h"
#include "../core/BinaryExpressionModel.h"
#include "../core/BinaryShadowExpression.h"
#include "SugenoThen.h"

namespace fuzzy{
    template <class T>
    class SugenoDefuzz : public core::NaryExpression<T>{

        public:
            SugenoDefuzz();
            virtual ~SugenoDefuzz();
            virtual T evaluate(const std::vector<core::Expression<T>*>*)const ;
        private:
            const std::vector<T> *coeff;
    };

    template <class T>
    T SugenoDefuzz<T>::evaluate(const std::vector< core::Expression<T>*>*operandes)const{
        typename std::vector<const core::Expression<T>*>::const_iterator it;
        T numerateur = 0;
        T denumerateur = 0;

        for (it = operandes->begin(); it != operandes->end(); it++){
            core::BinaryExpressionModel<T> bem = (core::BinaryExpressionModel<T>*)(*it);
            core::BinaryShadowExpression<T> bse = (core::BinaryShadowExpression<T>*)bem.getOperateur();
            SugenoThen<T>* sugthen = (SugenoThen<T>*)bse.getTarget();
            numerateur+=bem->evaluate();
            denumerateur+=sugthen->evaluate();
        }

        if(denumerateur==0) //Division par 0 impossible.
            return 0;
        else
            return numerateur/denumerateur;

    }

    template<class T>
    SugenoDefuzz<T>::SugenoDefuzz() {}

    template<class T>
    SugenoDefuzz<T>::~SugenoDefuzz() {
        delete coeff;
    }

}


#endif //PROJETFLOU_SUGENODEFUZZ_H
