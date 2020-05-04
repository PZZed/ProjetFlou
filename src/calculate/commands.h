//
// Created by pisel on 04/05/2020.
//

#ifndef PROJETFLOU_COMMANDS_H
#define PROJETFLOU_COMMANDS_H


#include <string>

namespace fuzzy {
    template <class T>
    class commands {
    public:
        commands();
        virtual ~commands(){}
        void running()const;
        void process(std::string pro)const;
    private:
        // map de variable de type value<T>| name
        // variable ans de type value<T>| name
    };

    template<class T>
    commands<T>::commands() {}

    template<class T>
    int running() {

        while(true){
            // lire chaine
            // chaine file ?
                // si oui for process sur chaque ligne du fichier

                // si non process(chaine)

        }

        return 0;

    }

    int process(std::string pro){
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
        return 0;
    }



}




#endif //PROJETFLOU_COMMANDS_H
