#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <iostream>
#include <string>
#include "Arme.h"

class Personnage
{
    public :

    Personnage(int optionsCombat);
    Personnage(std::string nom, int force, int agilite, std::string nomArme, int degatsArme, int typeArme);
    Personnage(int pvsMax, int pvs, std::string nom, int force, int agilite, std::string nomArme, int degatsArme, int typeArme, int optionsCombat);
    void attaquer (Personnage *&cible);
    virtual void option1 (Personnage &cible);
    void prendreCoup (int degats, int agiliteAdverse = 1000);
    void defense (bool defense);
    int recupPv (int pvRecus);
    void changerArme(std::string nomArme, int degatsArme, int typeArme);
    void changerNom (std::string nom);
    void pvPlus (int pvSupp);
    void foPlus (int foSupp);
    void agPlus (int agSupp);
    bool enVie();
    std::string getNomPerso() const;
    int getVie() const;
    int getMaxVie() const;
    int getForce() const;
    int getAgilite() const;
    Arme getArme() const;
    std::string getNomArme() const;
    int getDegatsArme() const;
    int getOptionsCombat() const;

    protected :

    int m_vie;
    int m_maxVie;
    int m_force;
    int m_agilite;
    Arme m_arme;
    int m_degats;
    int m_esquive;
    std::string m_nom;
    int m_alea;
    bool m_defense;
    int m_optionsCombat;

};


#endif // PERSONNAGE_H_INCLUDED
