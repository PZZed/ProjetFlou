#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "Expression.h"

namespace core{
    template <class T>
    class ValueModel : public Expression<T>{
    public:
        ValueModel(){};
        ValueModel(const T&);
        virtual ~ValueModel(){}

        virtual T evaluate()const;
        void setValue(const T&);
    private:
        T value;
    };

    template <class T>
    ValueModel<T>::ValueModel(const T& t) : value(t){}
    template<class T>
    void ValueModel<T>::setValue(const T &t) { this->value = t; }
    template<class T>
    T ValueModel<T>::evaluate() const { return this->value; }
}
#endif //VALUEMODEL_H
