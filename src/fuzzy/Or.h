//
// Created by pisel on 29/01/2020.
//

#ifndef OR_H
#define OR_H

#include "../core/BinaryExpression.h"

namespace fuzzy{
    template <class T>
    class Or : public core::BinaryExpression<T> {
    public:
        Or() {}
    };
}

#endif //OR_H
