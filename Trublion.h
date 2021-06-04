#ifndef TRUBLION_H_INCLUDED
#define TRUBLION_H_INCLUDED

#include <iostream>
#include "Personnage.h"


class Trublion : public Personnage
{
    public :

    Trublion(int optionsCombat);
    void option1(Personnage &cible);

};


#endif // TRUBLION_H_INCLUDED
