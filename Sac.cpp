#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sac.h"
#include "verif.h"
#include "Arme.h"
#include "Personnage.h"


using namespace std;

string nomType(int numeroArme)
{
    string nomArme;

    if (numeroArme == 1 || numeroArme == 4)
    {
        nomArme = "Tranchant";
    }
    else if (numeroArme == 2 || numeroArme == 5)
    {
        nomArme = "Contondant";
    }
    else if (numeroArme == 3 || numeroArme == 6)
    {
        nomArme = "A distance";
    }

    return nomArme;
}



Sac::Sac() : m_potions(0), m_bonbons(0), m_herbes(0)
{

}

void Sac::ajouterArme(Arme nouvelleArme)
{
        m_Armes.push_back(nouvelleArme);
}

void Sac::afficherArmes() const
{
    if (m_Armes.size() != 0)
    {
        cout << "Voila les armes que vous possedez :" << endl << endl;
        vector <int> tri;

        for (int i(0); i < m_Armes.size(); i++)
        {
            tri.push_back(m_Armes[i].getDegatsArme());
        }
        sort(tri.begin(), tri.end());

        for (int duree(0); duree < m_Armes.size(); duree++)
        {
            for (int i(0); i < m_Armes.size(); i++)
            {
                if (m_Armes[i].getDegatsArme() == tri[duree])
                {
                    cout << duree+1 << " : " << nomType(m_Armes[i].getTypeArme()) << "/ " <<  m_Armes[i].getNomArme() << " (" << m_Armes[i].getDegatsArme() << " degats)" << endl;
                }
            }
        }
        cout << m_Armes.size() +1 << " : Annuler" << endl;
    }
    else
    {
        cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
        cout << endl << "Vous n'avez pas d'arme a equiper" << endl;
        cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
    }
}

bool Sac::choisirArme(Personnage &cible)
{
    if (m_Armes.size() != 0)
    {
        m_choix = verif(m_Armes.size()+1, "Quelle arme choisissez vous ?", "") - 1;
        if (cible.getArme().getTypeArme() != 0)
        {
            m_Armes.push_back(cible.getArme());
        }
        if (m_choix != m_Armes.size() +1)
        {
            cible.changerArme(m_Armes[m_choix].getNomArme(), m_Armes[m_choix].getDegatsArme(), m_Armes[m_choix].getTypeArme());
            m_Armes.erase(m_Armes.begin() + m_choix);
        }
    }
    else
    {
        return true;
    }
}

void Sac::ajouterPotions (int potions)
{
    m_potions += potions;
}

void Sac::retirerPotions()
{
    m_potions --;
}

int Sac::getPotions() const
{
    return m_potions;
}

void Sac::ajouterHerbes (int herbes)
{
    m_herbes += herbes;
}

void Sac::retirerHerbes ()
{
    m_herbes -= 5;
}

int Sac::getHerbes() const
{
    return m_herbes;
}

void Sac::ajouterBonbons (int bonbons)
{
    m_bonbons += bonbons;
}

void Sac::retirerBonbons (int bonbons)
{
    m_bonbons -= bonbons;
}

int Sac::getBonbons() const
{
    return m_bonbons;
}

int Sac::getTypeArme(int position) const
{
    return m_Armes[position].getTypeArme();
}

int Sac::getDegatsArme(int position) const
{
    return m_Armes[position].getDegatsArme();
}

int Sac::getTailleListe() const
{
    return m_Armes.size();
}

string Sac::getNomArme(int position) const
{
    return m_Armes[position].getNomArme();
}
