#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Personnage.h"
#include "Caracteristiques.h"
#include "Sac.h"
#include "Horloge.h"
#include "NightCity.h"
#include "genre.h"
#include "verif.h"


using namespace std;

void parc(Personnage &joueur, Caracteristiques &caracJoueur, Sac &sac, Horloge &horloge, NightCity &ville)
{

    bool sortie(false);
    int choix;

    if (ville.verifPassage(1))
    {
        cout << endl << "" << endl;
    }

    else if (horloge.getEpuisement())
    {
        cout << endl << "Vous tombez de fatigue et abandonnez ce que vous faites pour aller vous coucher a votre repaire. De ce fait, vous passez une nuit terrible tres peu reposante." << endl;
    }

    else
    {
        cout << endl << "" << endl;
    }

    do
    {
        cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
        horloge.afficherTemps();
        cout << "   Bonbons : " << sac.getBonbons();

    }while (sortie == false);
}
