#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Personnage.h"
#include "genre.h"
#include "verif.h"
#include "Arme.h"
#include "Horloge.h"
#include "calculCompetence.h"

using namespace std;

void plurielAttaque (int attaque)
{
    if (attaque > 1)
    {
        cout << "s";
    }
    else
    {
        cout << "";
    }
}

Personnage::Personnage (string nom, int force, int agilite, string nomArme, int degatsArme, int typeArme):
m_vie(100), m_maxVie(100), m_defense(false), m_nom(nom), m_force(force), m_agilite(agilite), m_arme(nomArme, degatsArme, typeArme)
{

}

Personnage::Personnage(int optionsCombat):
m_vie(0), m_maxVie(0), m_defense(false), m_nom("No name"), m_force(0), m_agilite(0), m_arme("Dague rouillee", 1, 1), m_optionsCombat(optionsCombat)
{

}

Personnage::Personnage (int pvsMax, int pvs, string nom, int force, int agilite, string nomArme, int degatsArme, int typeArme, int optionsCombat):
m_vie(pvsMax), m_maxVie(pvs), m_defense(false), m_nom(nom), m_force(force), m_agilite(agilite), m_arme(nomArme, degatsArme, typeArme), m_optionsCombat(optionsCombat)
{

}

void Personnage::attaquer (Personnage *&cible)
{
    cout << endl << m_nom << " attaque avec " << m_arme.getNomArme() << endl;
    m_degats = m_arme.getDegatsArme() + calculCompetence(m_arme.getTypeArme(), m_force, true)/2;
    cible->prendreCoup(m_degats, m_agilite);
}

void Personnage::option1(Personnage &cible){}

void Personnage::prendreCoup (int degats, int agiliteAdverse)
{
    if (m_defense)
    {
        degats /= 2;
        m_defense = false;
    }

    if (degats < 1)
    {
        degats = 1;
    }

     m_esquive = calculCompetence(m_arme.getTypeArme(), m_agilite, false) - agiliteAdverse;

     if (m_esquive == 0 || m_esquive < 0)
     {
         m_vie -= degats;
         cout << m_nom << " a recu " << degats << " degat"; plurielAttaque(degats); cout << endl;
     }

     else
     {

        if (m_esquive > 5)
        {
            m_esquive = 5;
        }
        m_alea = (rand()% 10) + 1;

        if (m_alea > m_esquive)
        {
            m_vie -= degats;
            cout << m_nom << " a recu " << degats << " degat"; plurielAttaque(degats); cout << endl;
        }
        else
        {
            cout << m_nom << " esquive le coup avec brio !" << endl;
        }

     }
}

void Personnage::defense (bool defense)
{
    m_defense = defense;
}

int Personnage::recupPv(int pvRecu)
{
    if (m_vie == m_maxVie)
    {
        pvRecu = 0;
    }
    m_vie += pvRecu;

    if (m_vie > m_maxVie)
    {
        m_vie = m_maxVie;
        pvRecu = 666;
    }

    return pvRecu;

}

void Personnage::changerArme(string nomArme, int degatsArme, int typeArme)
{
    m_arme.changer(nomArme, degatsArme, typeArme);
}

void Personnage::changerNom(string nom)
{
    m_nom = nom;
}

void Personnage::pvPlus(int pvSupp)
{
    m_maxVie += pvSupp;
}

void Personnage::foPlus(int foSupp)
{
    m_force += foSupp;
}

void Personnage::agPlus(int agSupp)
{
    m_agilite += agSupp;
}

bool Personnage::enVie()
{
    if (m_vie < 0)
    {
        m_vie = 0;
    }
    return m_vie > 0;
}

string Personnage::getNomPerso() const
{
    return m_nom;
}

int Personnage::getVie() const
{
    return m_vie;
}

int Personnage::getMaxVie() const
{
    return m_maxVie;
}

int Personnage::getForce() const
{
    return m_force;
}

int Personnage::getAgilite() const
{
    return m_agilite;
}

Arme Personnage::getArme() const
{
    return m_arme;
}

string Personnage::getNomArme() const
{
    return m_arme.getNomArme();
}

int Personnage::getDegatsArme() const
{
    return m_arme.getDegatsArme();
}

int Personnage::getOptionsCombat() const
{
    return m_optionsCombat;
}









