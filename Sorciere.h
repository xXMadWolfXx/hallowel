#ifndef SORCIERE_H_INCLUDED
#define SORCIERE_H_INCLUDED

#include <iostream>
#include "Personnage.h"


class Sorciere : public Personnage
{
    public :

    Sorciere(int pvsMax, int pvs, std::string nom, int force, int agilite, std::string nomArme, int degatsArme, int typeArme, int optionsCombat);
    void option1(Personnage &cible);
    static void setRencontreSorciere();
    static bool getRencontreSorciere();

    private :

    static bool rencontreSorciere;



};

#endif // SORCIERE_H_INCLUDED
