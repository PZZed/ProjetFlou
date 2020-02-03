#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core{
    template <class T>
    class UnaryExpressionModel : public Expression<T>, public UnaryExpresssion<T>{
    public:
        UnaryExpressionModel(const Expression<T>& operand, const UnaryExpresssion<T>&ope);
        virtual ~UnaryExpressionModel(){};
        virtual T evaluate()const;
        virtual T evaluate(Expression<T>*)const;

    private:
        Expression<T> operand;
        UnaryExpresssion<T> ope;
    };

    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(const Expression<T>& operand, const UnaryExpresssion<T>& ope): operand(operand), ope(ope) {}

    template<class T>
    T UnaryExpressionModel<T>::evaluate() const {
        if(operand != nullptr)
            return evaluate(operand);
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T> * op) const {
        if(ope != nullptr)
            return ope.evaluate(op);
    }
}

#endif //UNARYEXPRESSIONMODEL_H
