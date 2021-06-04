#ifndef HEROS_H_INCLUDED
#define HEROS_H_INCLUDED

#include <iostream>
#include <string>
#include "Personnage.h"

class Heros : public Personnage
{
    public :

    Heros(std::string nom, int force, int agilite, std::string nomArme, int degatsArme, int typeArme);
    void attaquer(Personnage *&cible);

};

#endif // HEROS_H_INCLUDED
