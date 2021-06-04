#ifndef HORLOGE_H_INCLUDED
#define HORLOGE_H_INCLUDED

#include <iostream>
#include <string>
#include "Personnage.h"
#include "Caracteristiques.h"
#include "Sac.h"
#include "Horloge.h"
#include "NightCity.h"


class Horloge
{
    public :

    Horloge();
    void ajoutMinutes(int minutes);
    void ajoutJour();
    void afficherTemps();
    int getHeures() const;
    int getMinutes() const;
    std::string getNomJour() const;
    bool getEpuisement() const;
    int getJour() const;
    bool verifNuit() const;


    private :

    int m_minutes;
    int m_heures;
    int m_jour;
    bool m_epuisement;
    std::string m_tableauJours[8];


};

#endif // HORLOGE_H_INCLUDED
