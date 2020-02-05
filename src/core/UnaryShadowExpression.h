#include "UnaryExpression.h"

namespace core{
    template <class T>
    class UnaryShadowExpression : UnaryExpression<T>{
    public:
        UnaryShadowExpression(){};
        virtual ~UnaryShadowExpression(){};
        virtual T evaluate(Expression<T>*)const;
        virtual void setTarget(const Expression<T> *);
    private:
        UnaryExpression<T>* target;
    };

    template<class T>
    T UnaryShadowExpression<T>::evaluate(Expression<T> *o) const{
        return target->evaluate(o);
    }

    template<class T>
    void UnaryShadowExpression<T>::setTarget(const Expression<T> * t) {
        this->target=  t;
    }
}