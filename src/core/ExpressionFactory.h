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
        virtual Expression<T>* newUnary( UnaryExpression<T>* ope,  Expression<T> *o );
        virtual Expression<T>* newBinary( BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r);
    private:
        Expression<T>* Hold( Expression<T>*);
        std::set<Expression<T>*> memory;
    };


    template<class T>
    ExpressionFactory<T>::~ExpressionFactory() {
        for(typename std::set<Expression<T>*>::iterator i = memory.begin(); i != memory.end(); i++){
            delete *i;
        }
    }

    template<class T>
    Expression<T> *ExpressionFactory<T>::newUnary(UnaryExpression<T> *ope,  Expression<T>* o) {
        return Hold(new UnaryExpressionModel<T>(o,ope));
    }

    template<class T>
    Expression<T> *
    ExpressionFactory<T>::newBinary( BinaryExpression<T> *ope,  Expression<T> *l,  Expression<T> *r) {
        return Hold(new BinaryExpressionModel<T>(l,r,ope));
    }

    template<class T>
    Expression<T> *ExpressionFactory<T>::Hold(Expression<T> * e) {
        this->memory.insert(e);
        return e;
    }
}