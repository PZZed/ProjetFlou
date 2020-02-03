//
// Created by pisel on 29/01/2020.
//

#ifndef AND_H
#define AND_H

#include "../core/BinaryExpression.h"

namespace fuzzy{
    template <class T>
    class And : public core::BinaryExpression<T> {
    public:
        And() {}
    };
}


#endif //AND_H
