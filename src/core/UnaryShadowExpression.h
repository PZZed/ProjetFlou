#include "UnaryExpression.h"

namespace core{
    template <class T>
    class UnaryShadowExpression : public UnaryExpression<T>{
    public:
        UnaryShadowExpression(){};
        UnaryShadowExpression(const UnaryExpression<T>*);
        virtual ~UnaryShadowExpression(){};
        virtual T evaluate(Expression<T>*)const;
        virtual void setTarget(const UnaryExpression<T> *);
        virtual const UnaryExpression<T>* getTarget()const;
    private:
        const UnaryExpression<T>* target;
    };

    template<class T>
    T UnaryShadowExpression<T>::evaluate(Expression<T> *o) const{
        return this->target->evaluate(o);
    }

    template<class T>
    void UnaryShadowExpression<T>::setTarget(const UnaryExpression<T> * t) {
        if(t!= nullptr)
            this->target = t;
    }

    template<class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(const UnaryExpression<T>*ue):target(ue) {}

    template<class T>
    const UnaryExpression <T> *UnaryShadowExpression<T>::getTarget() const {
        return this->target;
    }
}