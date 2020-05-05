//
// Created by maxam on 04/05/2020.
//
#include <iostream>
#include "Commands.h"

namespace fuzzy {
    const int STRSIZE = 256;

    Commands::Commands() {}

    void Commands::running() const {
        while (true) {
            // lire chaine
            char tabInput[STRSIZE];
            std::cin.getline(tabInput, STRSIZE);
            std::string strInput = tabInput;

            if (strInput.find(".txt") == std::string::npos) {
                //ce n'est pas un fichier
                //process(chaine)
                std::cout << "commande" << std::endl;
            } else {
                //c'est un fichier
                //for process sur chaque ligne du fichier
                std::cout << "fichier" << std::endl;
            }
        }
    }

    void Commands::process(std::string pro) const {
        //switch de variable
        //if 1
        //command = new command(chaine.sub())
        //command.execute
        // if 2
        // variable = new variable(chaine.sub())
        // ajouter variable dans la map
        // if 3
        // crrée fonction ? trouver une idée ?
        //ajouter le dernier resultat dans ans qui est une variable
    }
}