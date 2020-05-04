//
// Created by pz on 04/05/2020.
//

#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include <utility>
#include <iosfwd>
#include <iostream>
#include "../core/Expression.h"
#include "../core/ValueModel.h"
#include "Shape.h"

using namespace std;
namespace fuzzy {
    template<class T>
    class Evaluator {
    public:
        static Shape<T> buildShape(const T &min, const T &max, const T &step,core::Expression<T>*l, core::Expression<T> *);
        static ostream &printShape(ostream &, const Shape<T> &s);
    };

    template<class T>
    Shape<T> Evaluator<T>::buildShape(const T &min, const T &max, const T &step, core::Expression<T>*l ,core::Expression<T> *r) {
        vector<T> x, y;
        T toSetAgain = l->evaluate();
        auto tmp = (core::ValueModel<T>*)l;

        for (T i = min; i <= max; i += step) {
            tmp->setValue(i);
            y.push_back(r->evaluate());
            x.push_back(i);
        }
        tmp->setValue(toSetAgain);
        return Shape<T>(x, y);
    }

    template<class T>
    ostream &Evaluator<T>::printShape(ostream &os, const Shape<T> &s) {
        os << '[';
        for (auto val : s.first)
            os << val << ' ';
        os << ']';
        os << endl;
        os << '[';
        for (auto val : s.second)
            os << val << ' ';
        os << ']';
        return os;
    }
}
#endif //EVALUATOR_H
