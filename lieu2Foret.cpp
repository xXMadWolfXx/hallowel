#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Trajet.h"
#include "Horloge.h"
#include "Personnage.h"
#include "Caracteristiques.h"
#include "Sac.h"
#include "NightCity.h"
#include "genre.h"
#include "verif.h"
#include "lieu1Repaire.h"
#include "lieu3QuartierPauvre.h"
#include "alea.h"


using namespace std;

int accesVille(bool sortieForet)
{
    int choix(1);

    if (sortieForet == false)
    {
        choix ++;
        cout << choix << "- Ville (1h)              ";
    }

    choix ++;
    cout << choix << "- Annuler";

    return choix;
}

void foret(Personnage &joueur, Caracteristiques &caracJoueur, Sac &sac, Horloge &horloge, NightCity &ville)
{

    bool sortie(false);
    int choix;
    Trajet foret;
    foret.initialisation();

    if (ville.verifPassage(1))
    {
        cout << endl << endl << endl << "Apres etre descendu"; genre(1, caracJoueur.getSexe()); cout << " de la colline ou se trouve votre repaire, vous arrivez aux abords de la foret qui entoure Nigthcity. Elle semble impenetrable." << endl
                     << "Cependant vous reperez une petite ouverture ou s'y engouffre un tortueux chemin. Il semblerait que vous n'ayez pas le choix, vous vous y engouffrez egalement." << endl;
    }
    else
    {
        cout << "Vous arrivez a ses abords sans encombre." << endl;

    }

    do
    {
        cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
        horloge.afficherTemps();
        cout << "   Bonbons : " << sac.getBonbons() << endl;
        choix = verif(3, "Que voulez-vous faire ?", "1- S'aventurer plus profondement dans la foret                2- Fouiller (1h)               3- Sortir");

        if (choix == 1)
        {
            foret.traverseeForet(horloge, sac, joueur, caracJoueur, ville);
        }

        else if (choix == 2)
        {
            int nombreAlea;
            nombreAlea = alea(30, 60);

            horloge.ajoutMinutes(60);
            if (horloge.getEpuisement())
            {
                repaire(joueur, caracJoueur, sac, horloge, ville);
            }

            cout << endl << "Vous decidez de fouiller les environs";
            if (nombreAlea == 1)
            {
                cout << " et tombez sur une grosse branche bien solide." << endl;
                if (ville.verifArme(sac, joueur, "Branche"))
                {
                    cout << "Mais vous en avez deja une alors vous la rejetez au loin." << endl;
                }
                else
                {
                    ville.changerArme(joueur, sac, 1);
                }
            }
            else if (nombreAlea == 2)
            {
                cout << " mais malheureusement vous ne trouvez rien d'interessant." << endl;
            }
            else
            {
                int nombreHerbes;
                nombreHerbes = (rand()% 4) + 1;
                sac.ajouterHerbes(nombreHerbes);
                cout << " et tombez sur un de l'herbe medicinale." << endl;
                cout << "Vous en ramassez " << nombreHerbes << " brin";
                if (nombreHerbes > 1)
                {
                    cout << "s";
                }
                cout << "." << endl;
            }
        }

        else if (choix == 3)
        {
            if (ville.verifSortie())
            {
                cout << endl << "Vous n'avez pas encore trouve la sortie pour rejoindre la ville." << endl;
            }

            do
            {
                cout << endl << "Ou voulez-vous aller ?" << endl << "1- Repaire (1h30)              ";
                choix = verif(accesVille(ville.verifSortie()), "", "");
            }while (choix == 0);

            if (choix == 1)
            {
                horloge.ajoutMinutes(90);
                if (horloge.getEpuisement())
                {
                    repaire(joueur, caracJoueur, sac, horloge, ville);
                }

                cout << endl << "Vous vous dirigez en direction de votre repaire." << endl;
                repaire(joueur, caracJoueur, sac, horloge, ville);
                sortie = true;
            }

            if (choix == 2 && ville.verifSortie() == false)
            {
                horloge.ajoutMinutes(60);
                if (horloge.getEpuisement())
                {
                    repaire(joueur, caracJoueur, sac, horloge, ville);
                }

                cout << endl << "Vous vous dirigez en direction de la ville." << endl;
                quartierPauvre(joueur, caracJoueur, sac, horloge, ville);
                sortie = true;
            }
            else
            {
                choix++;
            }

            if (choix == 3)
            {
                cout << endl << "Changement d'avis ?" << endl;
            }

        }

    }while (sortie == false);
}
