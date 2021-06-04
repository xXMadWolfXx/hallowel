#include <iostream>
#include <string>
#include "Horloge.h"
#include "Personnage.h"
#include "Sac.h"
#include "Caracteristiques.h"
#include "NightCity.h"
#include "lieu1Repaire.h"


using namespace std;

void ajout0 (int temps)
{
    if (temps < 10)
    {
        cout << "0" << temps;
    }
    else
    {
        cout << temps;
    }
}

Horloge::Horloge() : m_minutes(0), m_heures(13), m_jour(0)
{

}

void Horloge::ajoutMinutes(int minutes)
{
    m_minutes += minutes;
    m_heures += m_minutes/60;

    if(m_heures >= 24)
    {
        m_heures -= 24;
        m_jour ++;
    }

    while (m_minutes >= 60)
    {
        m_minutes -= 60;
    }

    if (m_jour < 7 && m_heures >= 3 && m_heures < 13)
    {
        m_heures = 13;
        m_minutes = 0;
        m_epuisement = true;
    }
    else
    {
        m_epuisement = false;
    }

}

void Horloge::ajoutJour()
{
    if (m_heures > 13 && m_heures < 24)
    {
        m_jour ++;
        m_heures = 13;
        m_minutes = 0;
    }
    else
    {
        m_heures = 13;
        m_minutes = 0;
    }
}

void Horloge::afficherTemps()
{
    m_tableauJours[0] = "Lundi";
    m_tableauJours[1] = "Mardi";
    m_tableauJours[2] = "Mercredi";
    m_tableauJours[3] = "Jeudi";
    m_tableauJours[4] = "Vendredi";
    m_tableauJours[5] = "Samedi";
    m_tableauJours[6] = "Dimanche";
    m_tableauJours[7] = "Lundi";

    cout << endl << m_tableauJours[m_jour] << " : "; ajout0(m_heures); cout << "h";  ajout0(m_minutes);

    if (m_jour < 7 && m_heures >= 0 && m_heures < 3)
    {
        cout << " (Attention, l'heure de se coucher approche, il faudrait penser a rentrer au repaire, 3h dernier delai !)";
    }

}

int Horloge::getHeures() const
{
    return m_heures;
}

int Horloge::getMinutes()  const
{
   return m_minutes;
}

string Horloge::getNomJour() const
{
    return m_tableauJours[m_jour];
}

bool Horloge::getEpuisement() const
{
    return m_epuisement;
}

int Horloge::getJour() const
{
    return m_jour;
}

bool Horloge::verifNuit() const
{
    if (m_heures >= 22 || m_heures < 3)
    {
        return true;
    }
    return false;
}


