#include <iostream>
#include <string>
#include "Caracteristiques.h"

using namespace std;

Caracteristiques::Caracteristiques() : m_sexe(0)
{

}

void Caracteristiques::changerSexe (int sexe)
{
    m_sexe = sexe;
}

void Caracteristiques::ajouterCarMonstre(bool carMonstre)
{
    m_carMonstre.push_back(carMonstre);
}

void Caracteristiques::resetCarMonstre()
{
    for (int i(0); i < 4; i++)
    {
        m_carMonstre.pop_back();
    }
}

int Caracteristiques::getSexe() const
{
    return m_sexe;
}

bool Caracteristiques::getCarMonstre(int position) const
{
    return m_carMonstre[position];
}
