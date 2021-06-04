#include <iostream>
#include <vector>
#include "Horloge.h"
#include "Trajet.h"
#include "Chemin.h"
#include "verif.h"
#include "Personnage.h"
#include "Trublion.h"
#include "combat.h"
#include "lieu1Repaire.h"



using namespace std;

Trajet::Trajet(): m_abscisse(7), m_ordonnee(0)
{

}

void Trajet::initialisation()
{
    Chemin monoHaut(true, false, false, false); Chemin monoDroite(false, true, false, false); Chemin monoBas(false, false, true, false); Chemin monoGauche(false, false, false, true);
    Chemin duoHautBas(true, false, true, false); Chemin duoDroiteGauche(false, true, false, true);
    Chemin duoBasDroite(false, true, true, false); Chemin duoBasGauche(false, false, true, true); Chemin duoHautDroite(true, true, false, false); Chemin duoHautGauche(true, false, false, true);
    Chemin trioHaut(true, true, false, true); Chemin trioDroite(true, true, true, false); Chemin trioBas(false, true, true, true); Chemin trioGauche(true, false, true, true);
    Chemin quatuor(true, true, true, true);

    m_numeroChemins.push_back(monoHaut); //0
    m_numeroChemins.push_back(monoDroite); //1
    m_numeroChemins.push_back(monoBas); //2
    m_numeroChemins.push_back(monoGauche); //3
    m_numeroChemins.push_back(duoHautBas); //4
    m_numeroChemins.push_back(duoDroiteGauche); //5
    m_numeroChemins.push_back(duoBasDroite); //6
    m_numeroChemins.push_back(duoBasGauche); //7
    m_numeroChemins.push_back(duoHautDroite); //8
    m_numeroChemins.push_back(duoHautGauche); //9
    m_numeroChemins.push_back(trioHaut); //10
    m_numeroChemins.push_back(trioDroite); //11
    m_numeroChemins.push_back(trioBas); //12
    m_numeroChemins.push_back(trioGauche); //13
    m_numeroChemins.push_back(quatuor); //14

    m_trajetForet[7][0] = 0;    m_trajetForet[2][4] = 5;    m_trajetForet[6][5] = 8;    m_trajetForet[12][2] = 14;  m_trajetForet[9][2] = 2;
    m_trajetForet[7][1] = 11;   m_trajetForet[1][4] = 8;    m_trajetForet[7][5] = 7;    m_trajetForet[12][3] = 4;   m_trajetForet[8][1] = 5;
    m_trajetForet[7][2] = 4;    m_trajetForet[1][5] = 13;   m_trajetForet[7][4] = 0;    m_trajetForet[12][4] = 4;
    m_trajetForet[7][3] = 7;    m_trajetForet[0][5] = 1;    m_trajetForet[6][8] = 5;    m_trajetForet[12][5] = 4;
    m_trajetForet[6][3] = 5;    m_trajetForet[1][6] = 4;    m_trajetForet[7][8] = 10;   m_trajetForet[12][6] = 4;
    m_trajetForet[5][3] = 5;    m_trajetForet[1][7] = 7;    m_trajetForet[7][9] = 2;    m_trajetForet[12][7] = 4;
    m_trajetForet[4][3] = 5;    m_trajetForet[0][7] = 8;    m_trajetForet[8][8] = 7;    m_trajetForet[12][8] = 4;
    m_trajetForet[3][3] = 11;   m_trajetForet[0][8] = 4;    m_trajetForet[8][7] = 11;   m_trajetForet[12][9] = 7;
    m_trajetForet[3][2] = 14;   m_trajetForet[0][9] = 2;    m_trajetForet[8][6] = 0;    m_trajetForet[11][9] = 5;
    m_trajetForet[2][2] = 5;    m_trajetForet[3][5] = 4;    m_trajetForet[9][7] = 12;   m_trajetForet[10][9] = 5;
    m_trajetForet[1][2] = 6;    m_trajetForet[3][6] = 6;    m_trajetForet[10][7] = 3;   m_trajetForet[9][9] = 5;
    m_trajetForet[1][1] = 8;    m_trajetForet[4][6] = 9;    m_trajetForet[9][6] = 4;    m_trajetForet[8][9] = 1;
    m_trajetForet[2][1] = 5;    m_trajetForet[4][7] = 4;    m_trajetForet[9][5] = 4;    m_trajetForet[13][2] = 3;
    m_trajetForet[3][1] = 10;   m_trajetForet[4][8] = 11;   m_trajetForet[9][4] = 8;    m_trajetForet[12][1] = 13;
    m_trajetForet[4][1] = 9;    m_trajetForet[4][9] = 2;    m_trajetForet[10][4] = 10;  m_trajetForet[11][1] = 1;
    m_trajetForet[4][2] = 12;   m_trajetForet[5][8] = 12;   m_trajetForet[10][5] = 4;   m_trajetForet[12][0] = 9;
    m_trajetForet[5][2] = 5;    m_trajetForet[5][7] = 4;    m_trajetForet[10][6] = 2;   m_trajetForet[11][0] = 5;
    m_trajetForet[6][2] = 3;    m_trajetForet[5][6] = 11;   m_trajetForet[11][4] = 7;   m_trajetForet[10][0] = 8;
    m_trajetForet[3][4] = 14;   m_trajetForet[5][5] = 0;    m_trajetForet[11][3] = 4;   m_trajetForet[10][1] = 7;
    m_trajetForet[4][4] = 3;    m_trajetForet[6][6] = 7;    m_trajetForet[11][2] = 8;   m_trajetForet[9][1] = 10;

}

void Trajet::traverseeForet(Horloge &horloge, Sac &sac, Personnage &joueur, Caracteristiques &caracJoueur, NightCity &ville)
{

    int choix(0); bool sortie(false); int direction[5]; int option;
    cout << endl << "Vous entrez dans la foret" << endl;
    do
    {
        do
        {
            cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
            horloge.afficherTemps();
            for (int i(0); i < 5; i++)
            {
                direction[i] = 0;
            }
            choix = 0;

            if(m_abscisse == 6 && m_ordonnee == 2)
            {
                Personnage *cornet = new Trublion(1);
                cout << endl << "Vous arrivez devant une jolie petite cabane, perdue au milieu de la foret. Devant elle se trouve un vieux tour a bois." << endl;
                if (horloge.getJour() == 2 && horloge.getHeures() >= 22)
                {
                    cout << endl << "Alors qu'il fait nuit noire, vous apercevez une grande silhouette, tres mince. Elle se retourne doucement vers vous, vous savez que vous avez trouve votre cible." << endl
                         << "Le combat est inevitable !" << endl;
                    combat(joueur, cornet, sac, caracJoueur);
                    cout << endl << "Vous ramassez un gros sac de bonbons et vous vous preparez a repartir." << endl;
                }
                else if (horloge.getJour() == 3 && horloge.getHeures() <= 3)
                {
                    cout << endl << "Alors qu'il fait nuit noire, vous apercevez une grande silhouette, tres mince. Elle se retourne doucement vers vous, vous savez que vous avez trouve votre cible." << endl
                         << "Le combat est inevitable !" << endl;
                    combat(joueur, cornet, sac, caracJoueur);
                    cout << endl << "Vous ramassez un gros sac de bonbons et vous vous preparez a repartir." << endl;
                }
                else
                {
                    delete cornet;
                    cout << "Elle semble habitee mais la personne qui y vit semble absente pour le moment." << endl;
                }
            }

            else if (m_abscisse == 0 && m_ordonnee == 9)
            {
                cout << endl << "Vous arrivez dans une clairiere et y trouvez un renne, que peut-il bien faire ici ? A cote se trouve un mannequin, mais il semble lui manquer des choses..." << endl;
                if (ville.getCostume() == 1)
                {
                    cout << "Bravo ! Le pere Noel arrive !" << endl;
                }
                else
                {
                    cout << "Vous regardez dans votre sac et sortez tout ce qui pourrait correspondre";
                    if (ville.getCostume() == 2)
                    {
                        cout << ", malheureusement vous ne trouvez rien..." << endl;
                    }
                    else
                    {
                        cout << ", voila ce que vous avez :" << endl <<endl;
                        ville.getPartiesCostume();
                        cout << "L'attirail n'est pas encore complet..." << endl;
                    }
                }
            }

            else if (m_abscisse == 7 && m_ordonnee == 9)
            {
                cout << endl << "Vous etes a l'oree de la foret, la sortie est toute proche !" << endl;
                ville.sortieForet();
            }

            else if (m_abscisse == 7 && m_ordonnee == 0)
            {
                cout << endl << "Vous etes a l'entree de la foret, un long chemin cache par la cime des arbres se trouve devant vos pieds !" << endl;
            }

            else
            {
                cout << endl << "Partout ou vous regardez, vous ne voyez que des arbres." << endl;
            }

            cout << endl << "Quelle direction prenez-vous ?" << endl << endl;
            if(m_numeroChemins[m_trajetForet[m_abscisse][m_ordonnee]].getHaut())
            {
                choix ++;
                direction[0] = choix ;
                cout << choix << "- Nord   ";
            }
            if(m_numeroChemins[m_trajetForet[m_abscisse][m_ordonnee]].getGauche())
            {
                choix ++;
                direction[1] = choix;
                cout << choix << "- Ouest    ";
            }
            if(m_numeroChemins[m_trajetForet[m_abscisse][m_ordonnee]].getDroite())
            {
                choix ++;
                direction[2] = choix;
                cout << choix << "- Est    ";
            }
            if(m_numeroChemins[m_trajetForet[m_abscisse][m_ordonnee]].getBas())
            {
                choix ++;
                direction[3] = choix;
                cout << choix << "- Sud    ";
            }
            if(m_abscisse == 7 && m_ordonnee == 0)
            {
                choix ++;
                direction[4] = choix;
                cout << choix << " - Sortir de la foret";
            }
            if(m_abscisse == 7 && m_ordonnee == 9)
            {
                choix ++;
                direction[4] = choix;
                cout << choix << " - Sortir de la foret";
            }
            option = verif(choix, "", "");
        }while (option == 0);

        horloge.ajoutMinutes(5);
        if (horloge.getEpuisement())
        {
            repaire(joueur, caracJoueur, sac, horloge, ville);
        }

        for (int i(0); i<5; i++)
        {
            if (option == direction[i])
            {
                if (i == 0)
                {
                    cout << endl << "Vous allez au nord." << endl;
                    m_ordonnee++;
                }
                else if (i == 1)
                {
                    cout << endl << "Vous allez a l'ouest." << endl;
                    m_abscisse--;
                }
                else if (i == 2)
                {
                    cout << endl << "Vous allez a l'est." << endl;
                    m_abscisse++;
                }
                else if (i == 3)
                {
                    cout << endl << "Vous allez au sud." << endl;
                    m_ordonnee--;
                }
                else if (i == 4)
                {
                    cout << endl << "Vous ressortez de la foret." << endl;
                    m_ordonnee = 0;
                    sortie = true;
                }
            }
        }

    }while (sortie == false);
}



