#include <iostream>
#include <string>
#include "Marchand.h"
#include "Arme.h"
#include "Sac.h"


using namespace std;

int calculPrix(int numeroArme)
{
    int prixArme(0);
    switch(numeroArme)
    {
        case 1:
            prixArme = 1000;
            break;
        case 2:
            prixArme = 2000;
            break;
        case 3:
            prixArme = 5000;
            break;
        case 4:
            prixArme = 10000;
            break;
        case 5:
            prixArme = 25000;
            break;
        case 6:
            prixArme = 50000;
            break;
    }

    return prixArme;
}

bool ajoutArme(Arme &armeAchetee, Sac &sac, int numeroArme)
{
    if (armeAchetee.getTypeArme() != 0)
    {
        if (calculPrix(numeroArme) <= sac.getBonbons())
        {
            sac.ajouterArme(armeAchetee);
            sac.retirerBonbons(calculPrix(numeroArme));
            cout << endl << "Vous placez " << armeAchetee.getNomArme() << " dans votre sac et tendez les bonbons au marchand." << endl;
            return true;
        }
        else
        {
            cout << endl << "Vous n'avez pas assez de bonbons pour acheter cette arme." << endl;
            return false;
        }
    }
    else
    {
        cout << endl << "\"Malheureusement je ne peux pas vendre ce que je n'ai plus...\"" << endl;
        return false;
    }
}

Marchand::Marchand(int pvsMax, int pvs, std::string nom, int force, int agilite, std::string nomArme, int degatsArme, int typeArme, int optionsCombat) :
Personnage(pvsMax, pvs, nom, force, agilite, nomArme, degatsArme, typeArme, optionsCombat)
{

}

void Marchand::option1(Personnage &cible)
{

}

bool Marchand::rencontreMarchand = false;

void Marchand::setRencontreMarchand()
{
    rencontreMarchand = true;
}

bool Marchand::getRencontreMarchand()
{
    return rencontreMarchand;
}

Arme epee("Epee", 10, 1); Arme cimeterre("Cimeterre", 20, 1); Arme grandeEpee("Grande epee", 40, 1); Arme epeeDouble("Epee double", 80, 1); Arme hache("Hache", 150, 1); Arme epeeDoree("Epee doree", 300, 1);
Arme Marchand::armesTranchantes[6] = {epee, cimeterre, grandeEpee, epeeDouble, hache, epeeDoree};

Arme gourdin("Gourdin", 15, 2); Arme massue("Massue", 30, 2); Arme marteauFer("Marteau en fer", 60, 2); Arme etoileMatin("Etoile du matin", 120, 2); Arme fleau("Fleau", 200, 2); Arme marteauDore("Marteau dore", 400, 2);
Arme Marchand::armesContondantes[6] = {gourdin, massue, marteauFer, etoileMatin, fleau, marteauDore};

Arme daguesLancer("Dagues de lancer", 5, 3); Arme arcCourt("Arc court", 10, 3); Arme arbalete("Arbalete", 20, 3); Arme arcLong("Arc long", 40, 3); Arme arbaleteOrnee("Arbalete ornee", 100, 3); Arme arcDore("Arc dore", 200, 3);
Arme Marchand::armesADistance[6] = {daguesLancer, arcCourt, arbalete, arcLong, arbaleteOrnee, arcDore};

void Marchand::afficherArmesBoutique(int choixType)
{
    for (int i(0); i<6; i++)
    {
        if (choixType == 1)
        {
            cout << i+1;
            if (armesTranchantes[i].getTypeArme() != 0)
            {
                cout << "- " << armesTranchantes[i].getNomArme() << "(" << armesTranchantes[i].getDegatsArme() << ") - " << calculPrix(i+1) << " bonbons" << endl;
            }
            else
            {
                cout << "- Epuisee" << endl;
            }
        }
        if (choixType == 2)
        {
            cout << i+1;
            if (armesContondantes[i].getTypeArme() != 0)
            {
                cout << "- " << armesContondantes[i].getNomArme() << "(" << armesContondantes[i].getDegatsArme() << ") - " << calculPrix(i+1) << " bonbons" << endl;
            }
            else
            {
                cout << "- Epuisee" << endl;
            }
        }
        if (choixType == 3)
        {
            cout << i+1;
            if (armesADistance[i].getTypeArme() != 0)
            {
                 cout << "- " << armesADistance[i].getNomArme() << "(" << armesADistance[i].getDegatsArme() << ") - " << calculPrix(i+1) << " bonbons" << endl;
            }
            else
            {
                cout << "- Epuisee" << endl;
            }
        }
    }
    cout << "7- Annuler" << endl;
}

void Marchand::acheterArme(Sac &sac, int choixArme, int choixType)
{
    Arme null("", 0, 0);

    if (choixArme == 7)
    {
        cout << endl << "Apres hesitation vous preferez ne rien acheter." << endl;
    }

    else
    {
        if (choixType == 1)
        {
            if(ajoutArme(armesTranchantes[choixArme-1], sac, choixArme))
            {
                armesTranchantes[choixArme-1] = null;
            }
            sac.ajouterArme(armesTranchantes[choixArme-1]);
        }

        if (choixType == 2)
        {
            if(ajoutArme(armesContondantes[choixArme-1], sac, choixArme))
            {
                armesContondantes[choixArme-1] = null;
            }
            sac.ajouterArme(armesContondantes[choixArme-1]);
        }

        if (choixType == 3)
        {
            if(ajoutArme(armesADistance[choixArme-1], sac, choixArme))
            {
                armesADistance[choixArme-1] = null;
            }
            sac.ajouterArme(armesADistance[choixArme-1]);
        }
    }
}
