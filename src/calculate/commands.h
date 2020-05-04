//
// Created by pisel on 04/05/2020.
//

#ifndef PROJETFLOU_COMMANDS_H
#define PROJETFLOU_COMMANDS_H



namespace fuzzy {
    template <class T>
    class commands {
    public:
        commands();
        virtual ~commands(){}
        void running()const;
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
            //switch de variable
                //if 1
                    //command = new command(chaine.sub())
                    //command.execute
                // if 2
                    // creeer un lecteur de fichier
                    //liste de commande
                    //boucle for et execution de chaque commande
                // if 3
                    // variable = new variable(chaine.sub())
                    // ajouter variable dans la map
               // if 4
                    // crrée fonction ? trouver une idée ?
            //ajouter le dernier resultat dans ans qui est une variable
        }

        return 0;

    }

}




#endif //PROJETFLOU_COMMANDS_H
