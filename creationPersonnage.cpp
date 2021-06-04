#include <iostream>
#include <string>
#include "Caracteristiques.h"
#include "Personnage.h"
#include "verif.h"
#include "genre.h"

using namespace std;

void ajoutCarMonstre(int choix, Caracteristiques &caracJoueur)
{
    switch (choix)
    {
    case 1:
        caracJoueur.ajouterCarMonstre(true);
        break;
    case 2:
        caracJoueur.ajouterCarMonstre(false);
        break;
    }
}

void creationPersonnage (Personnage &joueur, Caracteristiques &caracJoueur)
{
    int choix;
    cout << endl << "                   ~~ Creation du Monstre ~~" << endl;

    do
    {
    choix = verif(3, "Votre monstre, est-il un homme ou une femme ?", "1- Homme                2- Femme                3- Autre (ui ui tres inclusif comme jeu)");


    if (choix == 3)
    {

        choix = verif(2, "Ok, j'ai menti, il est pas si inclusif que ca ! Je reformule, a-t-il un penis ou un vagin entre les jambes ?", "1- Penis                    2- Vagin");

    }

    caracJoueur.changerSexe(choix);

    switch (choix)
    {
    case 1 :

        cout << endl << "Votre monstre est donc un monsieur ! On valide ?";
        break;

    case 2 :

        cout << endl << "Votre monstre est donc une madame ! On valide ?";
        break;
    }
    choix = verif(2, "1- Oui               2- Non", "");

    switch (choix)
    {
    case 1 :
        cout << endl << "Tres bon choix ! (Pas la peine de verifier, je dis ca pareil pour les deux ui ui)" << endl;
        break;

    case 2 :
        cout << endl << "Et ben ca commence bien..." << endl;
        break;
    }

    }while (choix == 2);


    string nom;


    do
    {
        cout << endl << "Quel est son nom ?" << endl;
        cin.ignore();
        getline(cin, nom);
        do
        {
            cout << endl << "Ce nom \"" << nom << "\" vous convient-il ?" << endl
                 << "1- Oui              2- Non";
            choix = verif(2, "", "");
        }
        while (choix == 0);

        switch (choix)
        {
        case 1:
            cout << endl << "Tant mieux !" << endl;
            joueur.changerNom(nom);
            break;

        case 2:
            cout << endl << "Ben alors, c'est pas complique comme question pourtant !" << endl;
            break;
        }
    }
    while (choix == 2);

    cout << endl << "Avant de repondre aux prochaines questions, prenez le temps de bien visualiser votre monstre dans la tete." << endl;

    int const tailleTableaux(4);
    string ifTrue[tailleTableaux];
    string ifFalse[tailleTableaux];
    ifTrue[0] = "Votre monstre a de la fourrure";
    ifTrue[1] = "Votre monstre a des ecailles";
    ifTrue[2] = "Votre monstre ressemble de pres ou de loin a un insecte";
    ifTrue[3] = "Votre monstre fiche une frousse pas possible a tout le monde";
    ifFalse[0] = "Votre monstre n'a pas de fourrure";
    ifFalse[1] = "Votre monstre n'a pas d'ecailles";
    ifFalse[2] = "Votre monstre ne ressemble en rien a un insecte";
    ifFalse[3] = "Votre monstre ne fait pas peur a une mouche";

    do
    {
        for (int i(1); i < 5; i++)
        {
            if (i == 1)
            {
                do
                {
                    cout << endl << "A-t-";
                    genre(2, caracJoueur.getSexe());
                    cout <<" de la fourrure ?" << endl
                         << "1- Oui              2- Non";
                    choix = verif(2, "", "");
                }
                while (choix == 0);
                ajoutCarMonstre(choix, caracJoueur);

            }

            else if (i == 2)
            {
                do
                {
                    cout << endl << "A-t-";
                    genre(2, caracJoueur.getSexe());
                    cout <<" des ecailles ?" << endl
                         << "1- Oui              2- Non";
                    choix = verif(2, "", "");
                }
                while (choix == 0);
                ajoutCarMonstre(choix, caracJoueur);
            }

            else if (i == 3)
            {
                do
                {
                    cout << endl << "A-t-";
                    genre(2, caracJoueur.getSexe());
                    cout <<" des caracteristiques d'insecte ?" << endl
                         << "1- Oui              2- Non";
                    choix = verif(2, "", "");
                }
                while (choix == 0);
                ajoutCarMonstre(choix, caracJoueur);
            }

            else if (i == 4)
            {
                do
                {
                    cout << endl << "Est-t-";
                    genre(2, caracJoueur.getSexe());
                    cout <<" effrayant";
                    genre(1, caracJoueur.getSexe());
                    cout << " ?" << endl
                         << "1- Oui              2- Non";
                    choix = verif(2, "", "");
                }
                while (choix == 0);
                ajoutCarMonstre(choix, caracJoueur);
            }
        }

        cout << endl;
        for (int i(0); i < 4; i++)
        {
            if (caracJoueur.getCarMonstre(i))
            {
                cout << ifTrue[i] << endl;
            }
            else
            {
                cout << ifFalse[i] << endl;
            }
        }
        choix = verif(2, "Cela vous convient ?", "1- Oui             2- Non");

        switch (choix)
        {
        case 1 :
            cout << endl << "Bien !" << endl;
            break;

        case 2 :
            cout << endl << "M'enfin ! Faut se concentrer ! On recommence !" << endl;
            caracJoueur.resetCarMonstre();
            break;
        }
    }
    while (choix == 2);


    do
    {
        do
        {
            cout << endl << "Qu'est-ce qui correspond le mieux a votre monstre ?" << endl
                 << "1- ";
            genre(3, caracJoueur.getSexe());
            cout << " fonce dans le tas, et pose les questions ensuite !" << endl
                 << "2- Prendre des coups ? ";
            genre(5, caracJoueur.getSexe());
            cout << " ? Certainement pas !" << endl
                 << "3- ";
            genre(3, caracJoueur.getSexe());
            cout << " donne des coups autant qu'";
            genre(2, caracJoueur.getSexe());
            cout << " en prend, mais pas trop quand meme !";
            choix = verif(3, "", "");
        }
        while (choix == 0);

        switch (choix)
        {
        case 1 :
            cout << endl << "C'est donc une brute, je vois." << endl;
            break;

        case 2 :
            cout << endl << "C'est donc un";
            genre(1, caracJoueur.getSexe());
            cout << " lache, je vois." << endl;
            break;

        case 3 :
            cout << endl << "Trop peur de se mouiller, c'est ca ? Je vois." << endl;
            break;
        }

        switch (verif(2, "Pas de regrets ?", "1- Si... Un peu quand meme...             2- Non !"))
        {
        case 1 :
            cout << endl << "Allons bon ! Un peu de concentration que diable !" << endl;
            choix = 1;
            break;
        case 2 :
            cout << endl << "Eh bien... Moi j'aurai pas fait ca, m'enfin, ok... Pourquoi pas..." << endl;
            switch (choix)
            {
            case 1 :
                choix = 4;
                joueur.foPlus(10);
                joueur.agPlus(0);
                joueur.pvPlus(20);
                joueur.recupPv(20);
                break;

            case 2 :
                joueur.foPlus(0);
                joueur.agPlus(10);
                joueur.pvPlus(-20);
                joueur.recupPv(-20);
                break;

            case 3 :
                joueur.foPlus(5);
                joueur.agPlus(5);
                break;
            }
            break;
        }
    }
    while (choix == 1);

}
