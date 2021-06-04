#include <iostream>
#include <string>
#include <vector>
#include "NightCity.h"
#include "Arme.h"
#include "Personnage.h"
#include "Sac.h"
#include "verif.h"
#include "Trajet.h"
#include "Horloge.h"
#include "Sorciere.h"
#include "Marchand.h"
#include "Ombre.h"

using namespace std;

NightCity::NightCity() : m_amelio(-1), m_jardin(0), m_fourmi(false), m_premiereFois(false), m_ruelle(false)
{

}

void NightCity::initialisation()
{
    Arme dague ("Dague", 5, 1); Arme branche("Branche", 10, 2); Arme epeeFourmi("Epee legendaire", 50, 1);
    m_listeArme.push_back(dague);
    m_listeArme.push_back(branche);
    m_listeArme.push_back(epeeFourmi);

    for (int i(0); i<9; i++)
    {
        m_listeLieux.push_back(true);
    }

    for (int i(0); i<8; i++)
    {
        m_costume.push_back("");
    }


}

bool NightCity::verifArme(Sac sac, Personnage joueur, string nomNouvelleArme)
{
    bool doublon;
    if (sac.getTailleListe() != 0)
    {
        for (int i(0); i < sac.getTailleListe(); i++)
        {
            if (sac.getNomArme(i) == nomNouvelleArme || joueur.getNomArme() == nomNouvelleArme)
            {
                i = 100;
                doublon = true;
            }
            else
            {
                doublon = false;
            }
        }
    }
    else
    {
        if (joueur.getNomArme() == nomNouvelleArme)
        {
            doublon = true;
        }
        else
        {
            doublon = false;
        }
    }
    return doublon;

}

bool NightCity::verifPassage (int lieu)
{
    if (m_listeLieux[lieu])
    {
        m_listeLieux[lieu] = false;
        return true;
    }
        return false;
}

void NightCity::changerArme (Personnage &joueur, Sac &sac, int arme)
{
    Arme null("null", 0, 0);

     if (verif(2, "Voulez-vous vous equiper de l'arme ?", "1- Oui                2- Non") == 1)
        {
            cout << endl << "Vous vous equipez de " << m_listeArme[arme].getNomArme() << endl;
             if (joueur.getArme().getTypeArme() != 0)
             {
                 sac.ajouterArme(joueur.getArme());
             }
            joueur.changerArme(m_listeArme[arme].getNomArme(), m_listeArme[arme].getDegatsArme(), m_listeArme[arme].getTypeArme());
        }
        else
        {
            cout << endl << "Vous rangez " << m_listeArme[arme].getNomArme() << " dans votre sac" << endl;
            sac.ajouterArme(m_listeArme[arme]);
        }

        m_listeArme[arme] = null;
}

void NightCity::ajoutPartiesCostume(string partieCostume)
{
    bool nouveau(true);

    for (int i(0); i < 8; i++)
    {
        if (m_costume[i] == partieCostume)
        {
            nouveau = false;
        }
    }

    if (nouveau)
    {
        for (int i(0); i < 8; i++)
        {
            if (m_costume[i] == "")
            {
                m_costume[i] = partieCostume;
                i = 100;
            }
        }
    }
}

void NightCity::getPartiesCostume () const
{
    for (int i(0); i < 8; i++)
    {
        if (m_costume[i] != "")
        {
            cout << m_costume[i] << endl;
        }
    }
}

int NightCity::getCostume () const
{
    int tampon(0);

    for (int i(0); i < 8; i++)
    {
        if (m_costume[i] != "")
        {
            tampon ++;
        }
    }

    if (tampon == 8)
    {
        return 1;
    }
    else if (tampon == 0)
    {
        return 2;
    }
    else
    {
        return 3;
    }

}

void NightCity::amelioRepaire()
{
    m_amelio ++;
}


int NightCity::getAmelioRepaire() const
{
    return m_amelio;
}

bool NightCity::jardinInsecte (int partieJardin)
{
    if (partieJardin == 1)
    {
        if (m_jardin == 0)
        {
            cout << endl << "Une fourmi de la taille d'une main vient a votre rencontre. Peut-etre se reconnait-elle en vous ? Elle vous dit qu'une fourmilliere geante se trouve dans le jardin, mais que c'est a vous de la trouver." << endl
                 << "Sans attendre une reponse de votre part elle s'enfuit dans un buisson." << endl;
            m_jardin++;
        }
    }
    else if (partieJardin == 2)
    {
        if (m_fourmi)
        {
            return true;
        }
        else
        {
            m_fourmi = true;
            cout << "Au detour d'un arbre, vous tombez sur un monticule de terre faisant deux fois votre taille. Alors que vous vous en approchez, la fourmi que vous aviez croise un peu plus tot vient vers vous." << endl
                 << "\"Je vois que tu nous as trouve ! Nous avons une arme a te proposer, mais avant ca tu dois faire quelque chose pour nous !\"" << endl;

        }
        return false;
    }

}

void NightCity::sortieForet()
{
    m_premiereFois = false;
}

bool NightCity::verifSortie() const
{
    return m_premiereFois;
}

void NightCity::setRuelle()
{
    m_ruelle = true;
}

bool NightCity::getRuelle() const
{
    return m_ruelle;
}





