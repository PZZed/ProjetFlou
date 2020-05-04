//
// Created by pisel on 04/05/2020.
//

#ifndef PROJETFLOU_VARIABLES_H
#define PROJETFLOU_VARIABLES_H

#include <string>
#include <map>
#include <iostream>

namespace calculate{


    class Variables{


    private:


        std::map<std::string,double>	var;

    public:
        Variables();
        virtual void add(std::string s,double v);
        virtual void printVar();
        virtual double get(std::string s);
        virtual void changeValue(std::string s , double v);
        virtual void equal(std::string s1 , std::string s2);
    };


    Variables::Variables() {
        var.insert(std::make_pair("ANS" , 0));
    }


    void Variables::add(std::string s,double v){
        var.insert(std::make_pair(s,v));
    }


    void Variables::printVar(){
        for (std::pair<std::string, int> element : var) {
            // Accessing KEY from element
            std::string key = element.first;
            // Accessing VALUE from element.
            double value = element.second;
            std::cout << key << " = " << value << std::endl;
        }
    }


    double Variables::get(std::string s){
        double res = INFINITY;
        for (std::pair<std::string, int> element : var) {
            // Accessing KEY from element
            std::string key = element.first;
            if (key == s) {
                res = element.second;
                std::cout<< element.first << " = " << element.second << std::endl;
            }
        }
        if(res=INFINITY){
            std::cout <<  s << " n'existe pas" << std::endl;

        }
        return res;
    }



    void Variables::changeValue(std::string s, double v){
        var.erase(s);
        var.insert(std::make_pair(s,v));
        }

    void Variables::equal(std::string s1 , std::string s2) {
        double d = var.find(s2)->second;
        changeValue(s1 , d);
        std::cout << s1 << " = " << d << std::endl;
        }
    }








#endif //PROJETFLOU_VARIABLES_H
// creer une map , avec des accesseur et des seteur
//creer des variables
//recuperer des variables
// égalité entre variables
//affiche toute les variables