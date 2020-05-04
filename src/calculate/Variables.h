//
// Created by pisel on 04/05/2020.
//

#ifndef PROJETFLOU_VARIABLES_H
#define PROJETFLOU_VARIABLES_H

#include <string>
#include <map>
#include <iostream>

namespace calculate{

    template<class T>
    class Variable{


    private:
        std::map<std::string,T>	var;

    public:
        virtual void add(std::string s,T v);
        virtual void printVar();
    };

    template<class T>
    void Variable<T>::add(std::string s,T v){
        var.insert(s,v);
    }

    template<class T>
    void Variable<T>::printVar(){
        for (std::pair<std::string, int> element : var) {
            // Accessing KEY from element
            std::string key = element.first;
            // Accessing VALUE from element.
            T value = element.second;
            std::cout << key << " = " << value << std::endl;
        }
    }
}


#endif //PROJETFLOU_VARIABLES_H
// creer une map , avec des accesseur et des seteur
//creer des variables
//recuperer des variables
// égalité entre variables
//affiche toute les variables