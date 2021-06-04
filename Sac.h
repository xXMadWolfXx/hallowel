#ifndef SAC_H_INCLUDED
#define SAC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Arme.h"
#include "Personnage.h"


class Sac
{
    public:

    Sac();
    void ajouterArme(Arme nouvelleArme);
    void afficherArmes() const;
    bool choisirArme(Personnage &cible);
    void ajouterPotions(int potion);
    void retirerPotions();
    int getPotions() const;
    void ajouterHerbes(int herbes);
    void retirerHerbes();
    int getHerbes() const;
    void ajouterBonbons(int bonbons);
    void retirerBonbons(int bonbons);
    int getBonbons() const;
    int getTypeArme(int position) const;
    int getDegatsArme(int position) const;
    std::string getNomArme(int position) const;
    int getTailleListe() const;

    private:

    std::vector <Arme> m_Armes;
    int m_choix;
    int m_potions;
    int m_bonbons;
    int m_herbes;

};


#endif // SAC_H_INCLUDED
