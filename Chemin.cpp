#include <iostream>
#include "Chemin.h"

using namespace std;

Chemin::Chemin(bool haut, bool droite, bool bas, bool gauche):
m_haut(haut), m_droite(droite), m_bas(bas), m_gauche(gauche)
{

}

bool Chemin::getHaut() const
{
    return m_haut;
}

bool Chemin::getDroite() const
{
    return m_droite;
}

bool Chemin::getBas() const
{
    return m_bas;
}

bool Chemin::getGauche() const
{
    return m_gauche;
}
