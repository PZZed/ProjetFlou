#include <set>
#include "Expression.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"

namespace core{
    template <class T>
    class ExpressionFactory{
    public:
        ExpressionFactory(){};
        virtual ~ExpressionFactory();
    protected:
        virtual Expression<T>* newUnary(const UnaryExpression<T>* ope, const Expression<T> *o );
        virtual Expression<T>* newBinary(const BinaryExpression<T>* ope,const Expression<T>* l,const Expression<T>* r);
    private:
        Expression<T>* Hold(const Expression<T>*);
        std::set<Expression<T>*> memory;
    };


    template<class T>
    ExpressionFactory<T>::~ExpressionFactory() {
        for(typename std::set<Expression<T>>::iterator i = memory.begin(); i != memory.end(); i++){
            delete i;
        }
    }

    template<class T>
    Expression<T> *ExpressionFactory<T>::newUnary(const UnaryExpression<T> *ope, const Expression<T>* o) {
        return new UnaryExpressionModel<T>(ope,o);
    }

    template<class T>
    Expression<T> *
    ExpressionFactory<T>::newBinary(const BinaryExpression<T> *ope, const Expression<T> *l, const Expression<T> *r) {
        return new BinaryExpressionModel<T>(ope,l,r);
    }

    template<class T>
    Expression<T> *ExpressionFactory<T>::Hold(const Expression<T> * e) {
        this->memory.insert(e);
        return e;
    }
}