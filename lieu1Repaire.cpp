#include <iostream>
#include "Personnage.h"
#include "Caracteristiques.h"
#include "Sac.h"
#include "Horloge.h"
#include "NightCity.h"
#include "genre.h"
#include "verif.h"
#include "lieu2Foret.h"
#include "alea.h"


using namespace std;

bool verifEpuisement(Horloge &horloge)
{
    if (horloge.getEpuisement())
    {
        cout << endl << "Vous tombez de fatigue et abandonnez ce que vous faites pour aller vous coucher a votre repaire. De ce fait, vous passez une nuit terrible tres peu reposante." << endl;
        return false;
    }

    return true;
}

int optionsRepaire(NightCity &ville)
{
    int choix (3);
    if (ville.getAmelioRepaire() == 9)
    {
        choix++;
        cout << "              " << choix << "- Entrer dans le jardin";
    }

    choix++;
    cout << "              " << choix << "- Se regarder dans le miroir";
    choix ++;
    cout << "              " << choix << "- Sortir";

    return choix;
}

void repaire(Personnage &joueur, Caracteristiques &caracJoueur, Sac &sac, Horloge &horloge, NightCity &ville)
{
    bool sortie(false);
    int choix;

    if (ville.verifPassage(0))
    {
        cout << endl << endl << endl << "Vous arrivez dans le repaire du chasseur qui vous a precede. Une vieille barraque completement delabree sur une colline, separee de la ville par une foret." << endl
             << "C'etait... atypique... M'enfin ce n'est pas comme si vous aviez l'habitude du grand luxe. Un matelas, des murs, un morceau de toit pour s'abriter, pas besoin de plus !" << endl
             << "Puis vous etiez la pour traquer le Vorace, pas profiter de vacances !" << endl;
    }

    else if (horloge.getEpuisement())
    {
        cout << endl << endl << endl << "Vous tombez de fatigue et abandonnez ce que vous faites pour aller vous coucher a votre repaire. De ce fait, vous passez une nuit terrible tres peu reposante." << endl;
    }

    else
    {
        cout << "Vous y arrivez sans encombre." << endl;
    }

    do
    {
        cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
        horloge.afficherTemps();
        cout << "   Bonbons : " << sac.getBonbons() << endl;
        do
        {
            cout << endl << "Que voulez vous faire ?" << endl
                 << "1- Dormir              2- Fouiller le repaire (1h)              3- Ameliorer le repaire (2h)";
        choix = verif(optionsRepaire(ville), "", "");
        }while (choix == 0);

        if(choix == 1)
        {
            if (horloge.getHeures() == 13)
            {
                cout << endl << "Vous n'etes pas fatigue";
                genre(1, caracJoueur.getSexe());
                cout << " !" << endl;
            }

            else
            {
                do
                {
                    cout << endl << "Etes-vous certain";
                    genre(1, caracJoueur.getSexe());
                    cout << " ? Cela vous fera passer de jour !" << endl
                         << "1- Oui             2- Non";
                    choix = verif(2, "", "");
                }
                while (choix == 0);

                if (choix == 1)
                {
                    cout << endl << "Vous vous endormez jusqu'au matin suivant, 13h." << endl;
                    horloge.ajoutJour();
                    joueur.recupPv(joueur.getMaxVie());
                }

                else if (choix == 2)
                {
                    cout << endl << "Une petite insomnie ?" << endl;
                }
            }
            choix = 10;
        }

        else if (choix == 2)
        {
            if (ville.verifArme(sac, joueur, "Dague") == false)
            {
                horloge.ajoutMinutes(60);
                if (verifEpuisement(horloge))
                {
                    cout << endl << "Apres une heure de fouille intensive vous tombez sur un coffre. Il appartenait surement au dernier chasseur. Dedans se trouve une dague et une potion." << endl;
                    ville.changerArme(joueur, sac, 0);
                    sac.ajouterPotions(1);
                }
            }
            else
            {
                cout << endl << "Apres un rapide coup d'oeil vous vous dites que vous ne trouverez plus rien." << endl;
            }
            choix = 10;
        }

        else if (choix == 3)
        {
            if (ville.getAmelioRepaire() < 9)
            {
                int const tailleTableau(10); string amelioRepaire[tailleTableau];
                amelioRepaire[0] = "Vous remettez tous les meubles en place, du moins la ou vous pensez qu'ils devaient se trouver.";
                amelioRepaire[1] = "Vous enlevez les toiles d'arraignee dans les coins et chassez les rats des murs.";
                amelioRepaire[2] = "Vous vous debarassez de la poussiere qui tapisse les meubles.";
                amelioRepaire[3] = "Vous passez un coup de balai sur le sol, puis vous y jeter des seaux d'eau pour le laver.";
                amelioRepaire[4] = "Vous nettoyez la cheminee. Alors que vous avez votre bras dans le conduit, vous sentez quelque chose d'etrange. C'est un pantalon rouge, bizarre, mais vous le prenez quand meme.";
                amelioRepaire[5] = "Vous remettez la porte d'entree sur ses gonds.";
                amelioRepaire[6] = "Vous remplacez les carreaux brises des fenetres.";
                amelioRepaire[7] = "Vous refixez le lustre au plafond.";
                amelioRepaire[8] = "Vous vous occupez du jardin qui entoure la maison en enlevant les branches et feuilles mortes qui trainent.";
                amelioRepaire[9] = "Finalement, vous vous debarassez des mauvaises herbes et des ronces. Voila un bel endroit ou se promener.";

                horloge.ajoutMinutes(120);
                if (verifEpuisement(horloge))
                {
                    ville.amelioRepaire();
                    cout << endl << amelioRepaire[ville.getAmelioRepaire()] << endl << "Cela vous a pris deux heures." << endl;
                    if (ville.getAmelioRepaire() == 4)
                    {
                        ville.ajoutPartiesCostume("Pantalon");
                    }
                }
            }
            else
            {
                cout << endl << "Vous avez ameliore votre repaire au maximum, il est plutot temps de traquer les Voraces !" << endl;
            }
            choix = 10;
        }

        if (ville.getAmelioRepaire() != 9)
        {
            choix ++;
        }

        if (choix == 4)
        {
            cout << endl << "Vous entrez dans le jardin." << endl;
            if (caracJoueur.getCarMonstre(2))
            {
                ville.jardinInsecte(1);
            }
            choix = verif(3, "Que voulez vous faire ?", "1- Se balader (1h)              2- Se prelasser pres d'un arbre (1h)            3- Sortir");
            cout << endl;

            if (choix == 1)
            {
                horloge.ajoutMinutes(60);
                if (verifEpuisement(horloge))
                {
                    int nombreAlea;
                    nombreAlea = alea(20, 60);

                    if (nombreAlea == 1)
                    {
                        cout << "Apres une heure de marche, vous revenez a l'entree du jardin en n'ayant rien vu de remarquable." << endl;
                    }

                    else if (nombreAlea == 2)
                    {
                        nombreAlea = alea(50, 85);
                        if (nombreAlea == 1)
                        {
                            sac.ajouterBonbons(500);
                            cout << "Pendant la balade vous tombez sur un petit sachet de bonbons au sol." << endl
                                 << "Vous gagnez 500 bonbons" << endl;
                        }
                        else if (nombreAlea == 2)
                        {
                            sac.ajouterBonbons(1500);
                            cout << "Alors que vous suivez un chemin etrange, vous tombez sur un gros sac de bonbons cache derriere un buisson." << endl
                                 << "Vous gagnez 1500 bonbons" << endl;
                        }
                        else if (nombreAlea == 3)
                        {
                            sac.ajouterBonbons(5000);
                            cout << "Vous n'en revenez pas vos yeux ! Une montagne de bonbons ! Ca valait le coup d'escalader cette colline !" << endl
                                 << "Vous gagnez 5000 bonbons" << endl;
                        }
                    }

                    else if (nombreAlea == 3)
                    {
                        if (caracJoueur.getCarMonstre(2))
                        {
                            if (ville.jardinInsecte(2))
                            {
                                 if (ville.verifArme(sac, joueur, "Epee legendaire") == false)
                                 {
                                     cout << "\"Bravo chasseu";
                                     genre(6, caracJoueur.getSexe());
                                     cout << ", vous avez bien merite votre recompense !\"" << endl;
                                     ville.changerArme(joueur, sac, 2);
                                 }
                                 else
                                 {
                                     cout << "\"Et bien le bonjour chasseu";
                                     genre(6, caracJoueur.getSexe());
                                     cout << ", vous voulez vous reposer avec nous ?" << endl;
                                 }
                            }
                        }
                        else
                        {
                            cout << "Apres une heure de marche, vous revenez a l'entree du jardin en n'ayant rien vu de remarquable." << endl;

                        }
                    }
                }
            }

            else if (choix == 2)
            {
                horloge.ajoutMinutes(60);
                if (verifEpuisement(horloge))
                {
                    int pvs;
                    pvs = joueur.recupPv(joueur.getMaxVie()/20);
                    cout << "Vous decidez de vous allongez une petite heure sous un arbre";
                    if (pvs == 0)
                    {
                        cout << " mais vous etes deja en pleine forme, cela ne vous fait pas regagner plus de vie." << endl;
                    }
                    else if (pvs == 666)
                    {
                        cout << ", vous voila revigorer au maximum !" << endl;
                    }
                    else
                    {
                        cout << " et vous recuperez " << joueur.getMaxVie()/20 << " pv ";
                        if (joueur.getMaxVie()/20 > 1)
                        {
                            cout << "s";
                        }
                        cout << endl;
                    }
                }
            }

            else if (choix == 3)
            {
                cout << "Vous ressortez du jardin aussitot." << endl;
            }
        }

        if (choix == 5)
        {
            cout << endl << "Vous vous approchez du miroir et vous observez un moment." << endl;
            cout << endl << "Vous vous appelez " << joueur.getNomPerso() << endl;
            cout << "Vous etes un"; genre(1, caracJoueur.getSexe()); cout << " "; genre(7, caracJoueur.getSexe()); cout << "." << endl << endl;

            if (caracJoueur.getCarMonstre(0))
            {
                cout << "Vous avez une jolie fourrure." << endl;
            }
            if (caracJoueur.getCarMonstre(1))
            {
                cout << "Vous avez de jolies ecailles" << endl;
            }
            if (caracJoueur.getCarMonstre(2))
            {
                cout << "Vous avez de jolies caracteristiques d'insecte." << endl;
            }
            if (caracJoueur.getCarMonstre(3))
            {
                cout << "Vous avez un air menacant qui en fait trembler plus d'un." << endl ;
            }

            cout << endl << "Stats :" << endl << "Pvs : " << joueur.getVie() << "/" << joueur.getMaxVie() << endl
                                              << "Force : " << joueur.getForce() << endl
                                              << "Agilite : " << joueur.getAgilite() << endl;

            if (joueur.getDegatsArme() == 1)
            {
                cout << endl << "Vous n'avez pas d'arme." << endl;
            }
            else
            {
                cout << endl << "Vous etes equipe"; genre(1, caracJoueur.getSexe()); cout << " de " << joueur.getNomArme() << "." <<  endl;
            }

            cout << "Vous avez " << sac.getPotions() << " potion"; if(sac.getPotions()>1){cout << "s";} cout << "." << endl;
            cout << "Vous avez " << sac.getHerbes() << " brin"; if(sac.getHerbes()>1){cout << "s";} cout << " d'herbe medicinale." << endl;
        }

        if (choix == 6)
        {
            choix = verif(2, "Ou voulez-vous aller ?", "1- Foret (1h30)              2- Annuler");
            if (choix == 1)
            {
                horloge.ajoutMinutes(90);
                if (verifEpuisement(horloge))
                {
                    cout << endl << "Vous vous dirigez en direction de la foret." << endl;
                    foret(joueur, caracJoueur, sac, horloge, ville);
                    sortie = true;
                }
            }
            else
            {
                cout << endl << "Changement d'avis ?" << endl;
            }
        }
    }while (sortie == false);
}
