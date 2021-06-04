#ifndef OMBRE_H_INCLUDED
#define OMBRE_H_INCLUDED

#include <iostream>
#include "Personnage.h"


class Ombre : public Personnage
{
    public :

    Ombre(int pvsMax, int pvs, std::string nom, int force, int agilite, std::string nomArme, int degatsArme, int typeArme, int optionsCombat);
    void option1(Personnage &cible);
    static void conseilDonne(int jour);
    static int getNombreConseils();
    static void setVoraciteOmbre(int bonbons);
    static int getVoraciteOmbre();

    private :

    static std::string conseilsBoss[7];
    static std::string conseils[6];
    static int voraciteOmbre;


};

#endif // OMBRE_H_INCLUDED
