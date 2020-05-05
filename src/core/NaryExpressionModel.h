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
    class NaryExpressionModel : public NaryExpression<T>, public Expression<T>{
    public:
        NaryExpressionModel(std::vector<Expression<T>* >*,NaryExpression<T>*);
        virtual ~NaryExpressionModel();
        virtual T evaluate()const;
        virtual T evaluate(const std::vector<Expression<T>*>* )const;
    private:
        std::vector<Expression<T>*>* operands;
        NaryExpression<T>* ope;
    };

    template<class T>
    NaryExpressionModel<T>::~NaryExpressionModel() {
        delete operands;
        delete ope;
    }
    template<class T>
    T NaryExpressionModel<T>::evaluate() const {
        if(ope != nullptr){
            return ope->evaluate(operands);
        }
    }

    template<class T>
    T NaryExpressionModel<T>::evaluate(const std::vector<Expression<T>*>* oper) const {
        if(oper!= nullptr){
            return evaluate(oper);
        }
    }
    template <class T>
    NaryExpressionModel<T>::NaryExpressionModel(std::vector<Expression<T>* >* oper,NaryExpression<T>* ope) : operands(oper),ope(ope){}


}


#endif //NARYEXPRESSIONMODEL_H
