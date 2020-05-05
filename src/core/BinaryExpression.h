//
// Created by pisel on 28/01/2020.
//

#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "Expression.h"

namespace core{
    template <class T>
    class BinaryExpression{
    public:
        virtual T evaluate(const Expression<T>* l, const Expression<T>* r)const = 0;
    };

}


#endif //BINARYEXPRESSION_H
