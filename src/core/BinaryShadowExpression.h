#include "BinaryExpression.h"
#include "UnaryExpression.h"

namespace core{
    template <class T>
    class BinaryShadowExpression : public BinaryExpression<T>{
    public:
        BinaryShadowExpression(){};
        virtual ~BinaryShadowExpression(){};
        virtual void setTarget(const BinaryExpression<T>*);
        virtual  BinaryExpression<T>* getTarget();
        virtual T evaluate(Expression<T>* l,Expression<T>* r)const;
    private:
        BinaryExpression<T>* target;

    };

    template<class T>
    void BinaryShadowExpression<T>::setTarget(const BinaryExpression<T> * t) {
        if(t!= nullptr)
            this->target = t;
    }

    template<class T>
    T BinaryShadowExpression<T>::evaluate(Expression<T> *l, Expression<T> *r)const {
        return target->evaluate(l,r);
    }
}