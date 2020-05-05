#include "BinaryExpression.h"
#include "UnaryExpression.h"

namespace core{
    template <class T>
    class BinaryShadowExpression : public BinaryExpression<T>{
    public:
        BinaryShadowExpression(){};
        BinaryShadowExpression(const BinaryExpression<T> *);
        virtual ~BinaryShadowExpression(){};
        virtual void setTarget(const BinaryExpression<T>*);
        virtual const BinaryExpression<T>* getTarget()const;
        virtual T evaluate(const Expression<T>* l,const Expression<T>* r)const;
    private:
        const BinaryExpression<T>* target;

    };

    template<class T>
    void BinaryShadowExpression<T>::setTarget(const BinaryExpression<T> * t) {
        if(t!= nullptr)
            this->target = t;
    }

    template<class T>
    T BinaryShadowExpression<T>::evaluate(const Expression<T> *l, const Expression<T> *r)const {
        return target->evaluate(l,r);
    }

    template<class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(const BinaryExpression<T> *be):target(be) {}

    template<class T>
    const BinaryExpression <T> *BinaryShadowExpression<T>::getTarget()const {
        return this->target;
    }
}