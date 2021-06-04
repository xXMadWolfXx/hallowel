#ifndef MARCHAND_H_INCLUDED
#define MARCHAND_H_INCLUDED

#include <iostream>
#include "Personnage.h"
#include "Sac.h"


class Marchand : public Personnage
{
    public :

    Marchand(int pvsMax, int pvs, std::string nom, int force, int agilite, std::string nomArme, int degatsArme, int typeArme, int optionsCombat);
    void option1(Personnage &cible);
    static void setRencontreMarchand();
    static bool getRencontreMarchand();
    static void afficherArmesBoutique(int choixArmes);
    static void acheterArme(Sac &sac, int choixArme, int choixType);

    private :

    static bool rencontreMarchand;
    static int prixArme;
    static Arme armesTranchantes[6];
    static Arme armesContondantes[6];
    static Arme armesADistance[6];


};

#endif // MARCHAND_H_INCLUDED
