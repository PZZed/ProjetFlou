#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core{
    template <class T>
    class UnaryExpressionModel : public Expression<T>, public UnaryExpression<T>{
    public:
        UnaryExpressionModel(Expression<T>* operand,  UnaryExpression<T>* ope);
        virtual ~UnaryExpressionModel(){};
        virtual T evaluate()const;
        virtual T evaluate(Expression<T>*)const;

    private:
        Expression<T>* operand;
        UnaryExpression<T>* ope;
    };

    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T>* operand, UnaryExpression<T>* ope): operand(operand), ope(ope) {}

    template<class T>
    T UnaryExpressionModel<T>::evaluate() const {
        if(operand != nullptr)
            return evaluate(operand);
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T> * op) const {
        if(ope != nullptr)
            return ope->evaluate(op);
    }
}

#endif //UNARYEXPRESSIONMODEL_H
