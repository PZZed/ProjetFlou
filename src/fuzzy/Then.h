//
// Created by pisel on 29/01/2020.
//

#ifndef THEN_H
#define THEN_H

#include "../core/BinaryExpression.h"

namespace fuzzy{
    template <class T>
    class Then : public core::BinaryExpression<T> {
    public:
        Then() {}
    };
}

#endif //THEN_H
