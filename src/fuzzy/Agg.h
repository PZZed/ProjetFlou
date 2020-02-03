//
// Created by pisel on 29/01/2020.
//

#ifndef AGG_H
#define AGG_H


#include "../core/BinaryExpression.h"

namespace fuzzy{
    template <class T>
    class Agg : public core::BinaryExpression<T> {
    public:
        Agg() {}
    };


}

#endif //AGG_H
