#include <iostream>
#include <string>
#include "verif.h"
#include "Personnage.h"
#include "Sac.h"
#include "Caracteristiques.h"
#include "combat.h"
#include "genre.h"
#include <ctime>
#include <cstdlib>


using namespace std;

void pluriel (int nombre)
{
    if (nombre > 1)
    {
        cout << " pvs";
    }
    else
    {
        cout << " pv";
    }
}


void combat(Personnage &joueur, Personnage *&ennemi, Sac &sac, Caracteristiques &caracJoueur)
{

    do
    {
        bool testArme, testPotion;
        int nombreAlea;
        do
        {
            int choix;
            cout << endl << joueur.getNomPerso() << " : " << joueur.getVie();
            pluriel(joueur.getVie());
            cout << "           "  << ennemi->getNomPerso() << " : " << ennemi->getVie();
            pluriel(ennemi->getVie());
            cout << endl << "Potions : " << sac.getPotions() << endl;
            testArme = false;
            testPotion = false;

            choix = verif(4,"Qu'allez vous faire ?", "1- Attaquer           2- Defendre             3- Boire une potion             4- Changer d'arme");

            if (choix == 1)
            {
                cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
                joueur.attaquer(ennemi);
            }

            else if (choix == 2)
            {
                cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
                joueur.defense(true);
                cout << endl << joueur.getNomPerso() << " se met en position defensive" << endl;
            }

            else if (choix == 3)
            {
                if (sac.getPotions() == 0)
                {
                    cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
                    cout << endl << "Vous n'avez pas de potion" << endl;
                    testPotion = true;
                    cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
                }

                else if (joueur.getVie() == joueur.getMaxVie())
                {
                    cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
                    cout << endl << "Votre sante est deja au maximum" << endl;
                    testPotion = true;
                    cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
                }

                else
                {
                    cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
                    joueur.recupPv(50);
                    sac.retirerPotions();
                    cout << endl << joueur.getNomPerso() << " boit une potion" << endl;
                }
            }

            else if (choix == 4)
            {
                cout << endl;
                sac.afficherArmes();
                testArme = sac.choisirArme(joueur);
                if (testArme == false)
                {
                    cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
                    cout << joueur.getNomPerso() << " s'equipe de " << joueur.getNomArme() << endl;
                }
            }

        }while (testArme == true || testPotion == true);

        if (ennemi->enVie())
        {
            nombreAlea = (rand()% ennemi->getOptionsCombat()) + 1;
            if (nombreAlea == 1)
            {
                ennemi->option1(joueur);
                cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
            }
        }
    }
    while (ennemi->enVie() && joueur.enVie());

    delete ennemi;

    if (joueur.enVie())
    {
        cout << endl << "Vous ressortez victorieu"; genre(4, caracJoueur.getSexe());
        cout << " de ce combat";
    }
    else
    {
        cout << endl << "Vous etes trop blesse"; genre(1, caracJoueur.getSexe());
        cout << " pour continuer le combat et fuyez a votre repaire pour vous reposer.";
    }



}
