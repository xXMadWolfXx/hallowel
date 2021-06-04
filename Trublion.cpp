#include <iostream>
#include <string>
#include "Trublion.h"
#include "calculCompetence.h"

using namespace std;


Trublion::Trublion(int optionsCombat) : Personnage(optionsCombat)
{

}

void Trublion::option1(Personnage &cible)
{
    cout << endl << m_nom << " attaque avec " << m_arme.getNomArme() << endl;
    m_degats = m_arme.getDegatsArme() + calculCompetence(m_arme.getTypeArme(), m_force, true)/2;
    cible.prendreCoup(m_degats, m_agilite);
}

