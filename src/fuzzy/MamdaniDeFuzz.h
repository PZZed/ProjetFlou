//
// Created by pisel on 29/01/2020.
//

#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H


#include "../core/BinaryExpression.h"

namespace fuzzy{
    template <class T>
    class MamdaniDeFuzz : public core::BinaryExpression<T> {
    public:
        MamdaniDeFuzz(const T & min, const T & max, const T & step);
        MamdaniDeFuzz(){}
        virtual ~MamdaniDeFuzz(){}
        virtual  T evaluate(const core::Expression<T>* ,const core::Expression<T>*)const=0;
        virtual T getMin()const;
        virtual T getMax()const;
        virtual T getStep()const;
        virtual void setMin(const T& min);
        virtual void setMax(const T &max);
        virtual void setStep(const T& step);
    protected:
        T min,max,step;
    };



    template<class T>
    MamdaniDeFuzz<T>::MamdaniDeFuzz(const T &min, const T &max, const T &step) :min(min),max(max),step(step){}

    template<class T>
    T MamdaniDeFuzz<T>::getStep() const {
        return this->step;
    }

    template<class T>
    T MamdaniDeFuzz<T>::getMax() const {
        return this->max;
    }

    template<class T>
    T MamdaniDeFuzz<T>::getMin() const {
        return this->min;
    }

    template<class T>
    void MamdaniDeFuzz<T>::setMin(const T &min) {
        this->min = min;
    }

    template<class T>
    void MamdaniDeFuzz<T>::setMax(const T &max) {
        this->max = max;
    }

    template<class T>
    void MamdaniDeFuzz<T>::setStep(const T &step) {
        this->step = step;
    }
}


#endif //MAMDANIDEFUZZ_H
