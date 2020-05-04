//
// Created by pisel on 29/01/2020.
//

#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <iosfwd>
#include <iostream>
#include "../core/Expression.h"
#include "../core/ValueModel.h"
using namespace std;
namespace fuzzy{
    template <class T>
    class Shape{
    public:
        Shape(){}
        Shape(std::vector<T>,std::vector<T>);
        virtual ~Shape(){}
        virtual std::vector<T> getXAxis()const;
        virtual std::vector<T> getYAxis()const;
        virtual ostream& printShape(ostream&);
        static Shape<T> buildShape(const T &min, const T &max, const T &step,core::Expression<T>*l, core::Expression<T> *);

    private:
        std::vector<T> xAxis;
        std::vector<T> yAxis;

    };

    template<class T>
    Shape<T> Shape<T>::buildShape(const T &min, const T &max, const T &step, core::Expression<T>*l ,core::Expression<T> *r) {
        std::vector<T> x, y;
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
    ostream& Shape<T>::printShape(ostream &os) {
        os << '[';
        for (auto val : this->xAxis)
            os << val << ' ';
        os << ']';
        os << endl;
        os << '[';
        for (auto val : this->yAxis)
            os << val << ' ';
        os << ']';
        return os;
    }
    template<class T>
    std::vector<T> Shape<T>::getXAxis() const {
        return this->xAxis;
    }

    template<class T>
    std::vector<T> Shape<T>::getYAxis() const {
        return this->yAxis;
    }

    template<class T>
    Shape<T>::Shape(std::vector<T> xAxis, std::vector<T> yAxis) : xAxis(xAxis),yAxis(yAxis) {}
}



#endif //SHAPE_H
