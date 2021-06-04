#include <iostream>
#include <string>
#include "Arme.h"



using namespace std;

Arme::Arme (string nomArme, int degatsArme, int typeArme): m_nomArme(nomArme), m_degatsArme(degatsArme), m_typeArme(typeArme)
{

}

void Arme::changer (string nomNouvelleArme, int degatsNouvelleArme, int typeNouvelleArme)
{
    m_nomArme = nomNouvelleArme;
    m_degatsArme = degatsNouvelleArme;
    m_typeArme = typeNouvelleArme;
}

string Arme::getNomArme() const
{
    return m_nomArme;
}

int Arme::getDegatsArme() const
{
    return m_degatsArme;
}

int Arme::getTypeArme() const
{
    return m_typeArme;
}


