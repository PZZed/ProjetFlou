
#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

#include "Is.h"
namespace fuzzy{
    template <class T>
    class IsTriangle : public Is<T>{
    public:
        IsTriangle(){};
        IsTriangle(const T&, const T&, const T&);
        virtual ~IsTriangle(){};
        virtual T evaluate(core::Expression<T>*)const;
    private:
        T min, mid, max;
    };

    template<class T>
    IsTriangle<T>::IsTriangle(const T & min, const T & mid, const T & max) : min(min), mid(mid), max(max) {}

    template<class T>
    T IsTriangle<T>::evaluate(core::Expression<T> * o) const {
        T tmp = o->evaluate();
        if(tmp  < min) return 0;
        else if (tmp > max) return 0;
        else if(tmp == mid) return 1;
        else if (tmp < mid) return (tmp - min) / (mid -min);
        else return (max -tmp) / (max-mid);
    }


}

#endif //ISTRIANGLE_H
