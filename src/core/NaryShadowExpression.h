//
// Created by pz on 04/05/2020.
//

#ifndef PROJETFLOU_NARYSHADOWEXPRESSION_H
#define PROJETFLOU_NARYSHADOWEXPRESSION_H

#include <vector>
#include "NaryExpression.h"

namespace core{
    template <class T>
    class NaryShadowExpression : public NaryExpression<T>{
    public:
        NaryShadowExpression(){}
        NaryShadowExpression(const NaryExpression<T>*);
        virtual ~NaryShadowExpression(){}
        virtual void setTarget(const NaryExpression<T>*);
        virtual  const NaryExpression<T>* getTarget()const;
        virtual T evaluate(const std::vector<Expression<T>*>*)const;
    private:
        const NaryExpression<T>* target;
    };

    template<class T>
    NaryShadowExpression<T>::NaryShadowExpression(const NaryExpression<T> * t) : target(t) {}

    template<class T>
    void NaryShadowExpression<T>::setTarget(const NaryExpression<T> * t) {
        if(t!= nullptr)
            this->target = t;
    }

    template<class T>
    const NaryExpression<T> *NaryShadowExpression<T>::getTarget() const {
        return this->target;
    }

    template<class T>
    T NaryShadowExpression<T>::evaluate(const std::vector<Expression<T> *>*expr) const {
        return this->target->evaluate(expr);
    }


}

#endif //PROJETFLOU_NARYSHADOWEXPRESSION_H
