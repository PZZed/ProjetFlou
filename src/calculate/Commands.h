//
// Created by pisel on 04/05/2020.
//

#ifndef PROJETFLOU_COMMANDS_H
#define PROJETFLOU_COMMANDS_H

#include <string>

namespace fuzzy {
    class Commands {
    public:
        Commands();
        virtual ~Commands(){}
        void running() const;
        void process(std::string pro)const;
    private:
        // map de variable de type value<T>| name
        // variable ans de type value<T>| name
    };
}
#endif //PROJETFLOU_COMMANDS_H
