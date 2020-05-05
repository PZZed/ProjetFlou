//
// Created by balanche on 1/29/20.
//

#ifndef PROJETFLOU_NARYEXPRESSION_H
#define PROJETFLOU_NARYEXPRESSION_H
#include "Expression.h"

namespace core{
    template <class T>
    class NaryExpression{
    public:
        virtual T evaluate(const std::vector<Expression<T>*>*)const =0;
    };
}
#endif //PROJETFLOU_NARYEXPRESSION_H
