//
// Created by pz on 04/05/2020.
//

#ifndef PROJETFLOU_NARYEXPRESSIONMODEL_H
#define PROJETFLOU_NARYEXPRESSIONMODEL_H

#include <vector>
#include "NaryExpression.h"
#include "UnaryExpression.h"

namespace core{
    template <class T>
    class NaryExpressionModel : public NaryExpression<T>{
    public:
        NaryExpressionModel(){}
        virtual ~NaryExpressionModel(){}
        virtual T evaluate()const;
        virtual T evaluate(const std::vector<Expression<T>*>)const;
    private:
        UnaryExpression<T> *operands;
        NaryExpression<T>* ope;
    };

    template<class T>
    T NaryExpressionModel<T>::evaluate() const {
        if(ope != nullptr){
            return ope->evaluate(operands);
        }
    }

    template<class T>
    T NaryExpressionModel<T>::evaluate(const std::vector<Expression<T>*>) const {
        if(operands!= nullptr){
            return evaluate(operands);
        }
    }
}


#endif //PROJETFLOU_NARYEXPRESSIONMODEL_H
