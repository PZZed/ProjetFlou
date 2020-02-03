//
// Created by balanche on 1/29/20.
//

#ifndef PROJETFLOU_NARYEXPRESSION_H
#define PROJETFLOU_NARYEXPRESSION_H
#include "Expression.h"

namespace core{
    template <class T>
    class NaryExpresssion{
    public:
        virtual T evaluate(Expression<T>[])const =0;
    };
}
#endif //PROJETFLOU_NARYEXPRESSION_H
