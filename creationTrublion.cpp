#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Horloge.h"
#include "Personnage.h"
#include "Trublion.h"
#include "creationTrublion.h"

using namespace std;

void finalisation(string nom, int pvs, string nomArme, int degatsArme, int typeArme, Personnage *&nouveauTrublion, Horloge &horloge)
{
    nouveauTrublion->changerNom(nom);
    if (pvs == 80)
    {
        nouveauTrublion->pvPlus(pvs + horloge.getJour()*5);
    }
    else
    {
        nouveauTrublion->pvPlus(pvs + horloge.getJour()*10);
    }
    nouveauTrublion->recupPv(nouveauTrublion->getMaxVie());
    nouveauTrublion->changerArme(nomArme, degatsArme, typeArme);
}

void creationTrublion(Horloge &horloge, Personnage *&nouveauTrublion)
{
    nouveauTrublion = new Trublion(1);

    int jours[7]; int scoreCompetence;
    jours[0] = 8;
    for (int i(1); i<7; i++)
    {
        jours[i] = jours[i-1] + 4;
    }

    for (int i(0); i<2; i++)
    {
        scoreCompetence = rand()% jours[horloge.getJour()]+1;

        if (i == 0)
        {
            nouveauTrublion->foPlus(scoreCompetence);
        }
        else if (i == 1)
        {
            nouveauTrublion->agPlus(scoreCompetence);
        }
    }

    if (nouveauTrublion->getForce()<jours[horloge.getJour()]/2 && nouveauTrublion->getAgilite()<jours[horloge.getJour()]/2)
    {
        finalisation("Squelette", 80, "Epee rouillee", 5, 1, nouveauTrublion, horloge);
    }
    else if (nouveauTrublion->getForce()<jours[horloge.getJour()]/2 && nouveauTrublion->getAgilite()>=jours[horloge.getJour()]/2)
    {
        finalisation("Homme a tete de serpent", 80, "Fouet", 5, 3, nouveauTrublion, horloge);
    }
    else if (nouveauTrublion->getForce()>=jours[horloge.getJour()]/2 && nouveauTrublion->getAgilite()<jours[horloge.getJour()]/2)
    {
        finalisation("Ogre", 100, "Gourdin", 10, 2, nouveauTrublion, horloge);
    }
    else
    {
        finalisation("Chevalier demoniaque", 100, "Epee maudite", 10, 1, nouveauTrublion, horloge);
    }
}


