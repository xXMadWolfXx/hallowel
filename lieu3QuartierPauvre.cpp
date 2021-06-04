#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Personnage.h"
#include "Trublion.h"
#include "Caracteristiques.h"
#include "Sac.h"
#include "Horloge.h"
#include "NightCity.h"
#include "Sorciere.h"
#include "genre.h"
#include "verif.h"
#include "lieu1Repaire.h"
#include "lieu2Foret.h"
#include "lieu4Boutique.h"
#include "creationTrublion.h"
#include "combat.h"
#include "alea.h"


using namespace std;

int optionsQuartierPauvre(NightCity &ville)
{
    int choix (0);

    cout << endl << "Que voulez vous faire ?" << endl;
    if (ville.getRuelle())
    {
        choix++;
        cout << choix << "- Emprunter la ruelle (1h)";
        choix++;
        cout << "              " << choix << "- Fouiller le quartier (1h)";
    }
    else
    {
        choix++;
        cout << choix <<"- Inspecter les environs (1h30)";
    }

    choix++;
    cout << "              " << choix << "- Sortir";

    return choix;
}

void quartierPauvre(Personnage &joueur, Caracteristiques &caracJoueur, Sac &sac, Horloge &horloge, NightCity &ville)
{

    bool sortie(false);
    int choix;

    if (ville.verifPassage(2))
    {
        cout << endl << "Vous quittez la foret et vous approchez de Nigthcity. Apres une petite heure de marche vous arrivez aux abords de la ville, qui semble pour le moins pauvre." << endl
                                     << "Des maisons delabrees, des jardins laisses a l'abandon... Tout semble desert, pourtant vous avez l'impression d'etre epie"; genre(1, caracJoueur.getSexe()); cout << "." << endl;
    }

    else
    {
        cout << endl << "Vous y arrivez sans encombre." << endl;
    }

    do
    {
        cout << endl << endl << "                   ~~~~~~~~~~" << endl << endl;
        horloge.afficherTemps();
        cout << "   Bonbons : " << sac.getBonbons() << endl;

        do
        {
            choix = verif(optionsQuartierPauvre(ville), "", "");
        }while (choix == 0);

        if (choix == 1)
        {
            if (ville.getRuelle() == false)
            {
                horloge.ajoutMinutes(90);
                if (horloge.getEpuisement())
                {
                    repaire(joueur, caracJoueur, sac, horloge, ville);
                }

                cout << endl << "Vous faites le tour du quartier. Des bonbons trainent par-ci par-la, devant les portes des maisons, eparpilles sur le sol..." << endl
                             << "Malgre le manque flagrant de richesses, les traditions d'Halloween battent leur plein, meme ici. A la nuit tombee vous devriez pouvoir croiser des groupes d'enfants." << endl
                             << "Une fois revenu"; genre(1, caracJoueur.getSexe()); cout << " sur vos pas, vous remarquez une etrange ruelle, presque empreinte de magie. Pourtant vous jurerez qu'elle n'y etait pas en arrivant !" << endl;
                ville.setRuelle();

                if (Sorciere::getRencontreSorciere() == false)
                {
                    cout << endl << "Vous entendez alors une voix derriere vous !" << endl
                         << "\"Bonjour, je ne m'y risquerai pas si j'etais vous, on ne sait pas sur qui on va tomber dedans, et ce n'est jamais de bonnes rencontres.\"" << endl
                         << "Une sorciere ! A peine eut-elle terminee sa phrase qu'elle s'engouffra dans la ruelle avant de disparaitre dans l'obscurite." << endl;
                    Sorciere::setRencontreSorciere();
                }
            }
            else
            {
                horloge.ajoutMinutes(60);
                if (horloge.getEpuisement())
                {
                    repaire(joueur, caracJoueur, sac, horloge, ville);
                }

                Personnage *ennemiRuelle = new Trublion(1);
                creationTrublion(horloge, ennemiRuelle);
                cout << endl << "Vous entrez dans la ruelle. A mesure que vous avancez vous sentez une presence proche de vous. Vous n'avez pas le temps de vous retournez qu'on vous saute dessus." << endl;
                cout << "Vous faites face a : " << ennemiRuelle->getNomPerso() << endl;
                combat(joueur, ennemiRuelle, sac, caracJoueur);
            }
        }

        else if (choix == 2 && ville.getRuelle())
        {
            horloge.ajoutMinutes(60);
            if (horloge.getEpuisement())
            {
                repaire(joueur, caracJoueur, sac, horloge, ville);
            }
            int nombreAlea;
            cout << endl << "Vous partez en quete d'enfants a terroriser !";
            if (horloge.verifNuit())
            {
                cout << " C'est la nuit, le moment ideal car ils sortent tous chercher leurs bonbons." << endl;
                nombreAlea = alea(70,90);
            }
            else
            {
                cout << " C'est le jour, pas le meilleur moment pour trouver des momes qui cherchent des bonbons..." << endl;
                nombreAlea = alea(20,90);
            }

            if (nombreAlea == 1)
            {
                cout << endl << "Vous tombez sur un petit groupe en train de toquer a une porte. Leurs costumes sont rapieces et ils n'ont que la peau sur les os, a se demander ce qui fait le plus peur." << endl;
                choix = verif(2,"Que voulez-vous faire ?", "1- S'approcher d'eux              2- Les laisser tranquille");

                if (choix == 1)
                {
                    nombreAlea = alea(33);
                    if (caracJoueur.getCarMonstre(3) && nombreAlea == 1)
                    {
                        cout << endl << "Un des enfants vous remarque et laisse echapper un cri de frayeur ! Les autres tetes se tournent vers vous et tous les yeux s'ecarquillent, ils ne demandent pas leur reste et se carapatent en vitesse." << endl
                                     << "Votre physique effrayant ne vous aura pas aide sur ce coup, a moins que c'etait ce que vous souhaitiez ? En tout cas, vous trouvez un petit sac de 500 bonbons sur le sol !" << endl;
                        sac.ajouterBonbons(500);
                    }
                    else
                    {
                        cout << endl << "Vous vous approchez du petit groupe.";
                        if (caracJoueur.getCarMonstre(3))
                        {
                            cout << " Les enfants vous regardent craintivement, il faut dire que vous n'inspirez pas vraiment confiance...";
                        }
                        cout << endl;
                        choix = verif(2, "Voulez-vous prendre leurs bonbons ou leur en donner ?", "1- Prendre les bonbons              2- Donner des bonbons");

                        if (choix == 1)
                        {
                            cout << endl << "Vous prenez une posture menacante et leur ordonnez de vous donner leur recolte." << endl;

                            if (caracJoueur.getCarMonstre(3))
                            {
                                nombreAlea = alea(70);
                            }
                            else
                            {
                                nombreAlea = alea(50);
                            }

                            if (nombreAlea == 1)
                            {
                                cout << endl << "Les enfants vous tendent leurs sacs et vous piochez dedans allegrement, vous obtenez 500 bonbons." << endl;
                                sac.ajouterBonbons(500);
                            }
                            else

                            {
                                cout << endl << "Les enfants partent en courant dans tous les sens, alors que vous en coursez un, ce dernier se faufile dans une fissure." << endl
                                             << "Malheureusement pour vous, pris dans votre elan vous vous prenez le mur de plein fouet (-10pvs)." << endl
                                             << "Vous vous relevez seul au milieu des maisons." << endl;
                                joueur.prendreCoup(10);
                                if (joueur.enVie() == false)
                                {
                                    joueur.recupPv(1);
                                }
                            }
                        }
                        else
                        {
                            choix = verif(3, "Combien voulez-vous leur en donner ?", "1- 500              2- 1000              3- 5000");

                            if (choix == 1)
                            {
                                if (sac.getBonbons() >= 500)
                                {
                                    cout << endl << "Vous fouillez dans votre sac et leur tendez 500 bonbons. D'abord hesitant, ils s'empressent de les prendre un grand sourire aux levres avant de repartir toquer aux maisons." << endl;
                                    sac.retirerBonbons(500);
                                }
                                else
                                {
                                    cout << endl << "Vous n'avez pas assez de bonbons... Vous les regardez tristement et repartez d'ou vous venez." << endl;
                                }
                            }

                            else if (choix == 2)
                            {
                                if (sac.getBonbons() >= 1000)
                                {
                                    cout << endl << "Vous fouillez dans votre sac et leur tendez 100 bonbons. Leurs yeux petillent a la vue de tant de bonbons ! Ils vous les arrachent presque des mains avant de partir en sautillant de joie." << endl;
                                    sac.retirerBonbons(1000);
                                }
                                else
                                {
                                    cout << endl << "Vous n'avez pas assez de bonbons... Vous les regardez tristement et repartez d'ou vous venez." << endl;
                                }
                            }

                            else
                            {
                                if (sac.getBonbons() >= 5000)
                                {
                                    cout << endl << "Vous fouillez dans votre sac et leur tendez 5000 bonbons. Les enfants restent bouche bee, ils n'en croient pas leurs yeux !" << endl
                                                 << "Ils prennent les bonbons de facon presque religieuse, vous remercie mille fois et s'en vont en riant." << endl;
                                    sac.retirerBonbons(5000);
                                }
                                else
                                {
                                    cout << endl << "Vous n'avez pas assez de bonbons... Vous les regardez tristement et repartez d'ou vous venez." << endl;
                                }
                            }
                        }
                    }
                    choix = 10;
                }
                else
                {
                    cout << endl << "Vous preferez ne pas vous approchez d'eux et repartez d'ou vous venez." << endl;
                }
            }

            else if (nombreAlea == 2)
            {
                cout << endl << "Malgre toute votre bonne volonte, vous ne croisez personne..." << endl;
            }

            else
            {
                cout << endl << "Vous trouvez une jolie citrouille en plastique sur le pas d'une porte. Surement oublie par un enfant, vous regardez a l'interieur et trouvez 1000 bonbons !" << endl;
                sac.ajouterBonbons(1000);
            }
        }

        else if (choix == 2)
        {
           choix++;
        }

        if (choix == 3)
        {
            choix = verif(3, "Ou voulez-vous aller ?", "1- Foret (1h30)              2- Centre ville (30min)              3- Annuler");

            if (choix == 1)
            {
                horloge.ajoutMinutes(90);
                if (horloge.getEpuisement())
                {
                    repaire(joueur, caracJoueur, sac, horloge, ville);
                }
                cout << endl << "Vous vous dirigez en direction de la foret." << endl;
                foret(joueur, caracJoueur, sac, horloge, ville);
                sortie = true;
            }
            else if (choix == 2)
            {
                horloge.ajoutMinutes(30);
                if (horloge.getEpuisement())
                {
                    repaire(joueur, caracJoueur, sac, horloge, ville);
                }
                cout << endl << "Vous continuez votre route jusqu'a arriver au centre ville." << endl;
                boutique(joueur, caracJoueur, sac, horloge, ville);
                sortie = true;
            }
            else
            {
                cout << endl << "Changement d'avis ?" << endl;
            }
        }

    }while (sortie == false);
}
