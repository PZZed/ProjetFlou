#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H

#include "Is.h"

namespace fuzzy{
    template <class T>
    class IsTrapeze : public Is<T>{
    public:
        IsTrapeze(){};
        IsTrapeze(const T&, const T&, const T&, const T&);
        virtual ~IsTrapeze(){};
        virtual T evaluate(core::Expression<T>*)const;
    private:
        T lowMin, highMin, highMax, lowMax;
    };

    template<class T>
    IsTrapeze<T>::IsTrapeze(const T &lowMin_, const T &highMin_, const T &highMax_, const T &lowMax_) : lowMin(lowMin_), highMin(highMin_), highMax(highMax_), lowMax(lowMax_) {}

    template<class T>
    T IsTrapeze<T>::evaluate(core::Expression<T> * o) const {
        T tmp = o->evaluate();
        if(tmp < highMin) {
            if(lowMin == highMin) {
                // '''''''''\....
                return 1;
            } else {
                // ..../''''\....
                if(tmp < lowMin) return 0;
                else return (tmp - lowMin) / (highMin - lowMin);
            }
        } else if(tmp > highMax) {
            if(highMax == lowMax) {
                // ..../'''''''''
                return 1;
            } else {
                // ..../''''\....
                if (tmp < lowMax) return (lowMax - tmp) / (lowMax - highMax);
                else return 0;
            }
        } else {
            return 1;
        }
    }
}
#endif //ISTRAPEZE_H
