//
// Created by balanche on 1/29/20.
//

#ifndef PROJETFLOU_SUGENODEFUZZ_H
#define PROJETFLOU_SUGENODEFUZZ_H

#include "../core/NaryExpression.h"

namespace fuzzy{
    template <class T>
    class SugenoDefuzz : public core::NaryExpresssion<T>{

        public:
            virtual T evaluate(core::Expression<T>[])const ;
    };

    template <class T>
    T SugenoDefuzz<T>::evaluate(core::Expression<T>[])const{

    }

}


#endif //PROJETFLOU_SUGENODEFUZZ_H
