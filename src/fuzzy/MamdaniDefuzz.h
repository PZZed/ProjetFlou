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
        virtual ~MamdaniDeFuzz(){}
        virtual  T evaluate(core::Expression<T>* ,core::Expression<T>*)const;
    private:
        T min,max,step;
    };

    template<class T>
    MamdaniDeFuzz<T>::MamdaniDeFuzz(const T &min, const T &max, const T &step) :min(min),max(max),step(step){}

    template<class T>
    T MamdaniDeFuzz<T>::evaluate(core::Expression<T> *, core::Expression<T> *)const {
        return 0;
    }
}


#endif //MAMDANIDEFUZZ_H
