#ifndef TRAJET_H_INCLUDED
#define TRAJET_H_INCLUDED

#include <iostream>
#include <vector>
#include "Chemin.h"
#include "Horloge.h"



class Trajet
{
    public :

    Trajet();
    void initialisation();
    void traverseeForet(Horloge &horloge, Sac &sac, Personnage &joueur, Caracteristiques &caracJoueur, NightCity &ville);

    private :

    std::vector <Chemin> m_numeroChemins;
    int m_trajetForet [14][10];
    int m_abscisse;
    int m_ordonnee;

};

#endif // TRAJET_H_INCLUDED
