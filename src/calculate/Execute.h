//
// Created by pisel on 04/05/2020.
//

#ifndef PROJETFLOU_EXECUTE_H
#define PROJETFLOU_EXECUTE_H

#include <string>

namespace calculate{

    class Execute {
    public:
        Execute(std::string instr);
        virtual ~Execute();
        void  exe();

    private:
        std::string instr;


    };
}



bool isOperator(const std::string &c)
{
    return (c == "+" || c == "-" || c == "*" );
}

#endif //PROJETFLOU_EXECUTE_H
