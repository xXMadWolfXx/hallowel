#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Personnage.h"
#include "Caracteristiques.h"
#include "Sac.h"
#include "Horloge.h"
#include "NightCity.h"
#include "Ombre.h"
#include "Marchand.h"
#include "genre.h"
#include "verif.h"
#include "lieu1Repaire.h"
#include "lieu3QuartierPauvre.h"


using namespace std;

void boutique(Personnage &joueur, Caracteristiques &caracJoueur, Sac &sac, Horloge &horloge, NightCity &ville)
{

    bool sortie(false);
    int choix;

    if (ville.verifPassage(3))
    {
        cout << endl << "Vous arrivez dans ce qui semble etre l'endroit le plus anime de Nightcity. Des badauds se pressent de tous les cotes, trop occupes a faire leurs emplettes pour vous remarquer. " << endl
                     << "Quant a vous, vous preferez rester en retrait, attirer l'attention n'est pas vraiment votre objectif. Au final, peu de choses vous interessent dans cette partie de la ville... A moins que..." << endl
                     << "Un peu a l'ecart de toute cette activite vous apercevez une silouhette encapuchonnee sous une arcade. Intrigue"; genre(1, caracJoueur.getSexe()); cout << " vous decidez de la rejoindre." << endl
                     << "Une fois a son niveau, sans un mot elle se retourne et rentre dans une sorte de cour interieure avant de s'y figer dans un coin." << endl
                     << "A cote d'elle se trouve une facade coloree, ressemblant quelque peu a une echoppe." << endl;
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
        choix = verif(3, "Que voulez-vous faire ?", "1- S'approcher de la figure                2- Rentrer dans l'echoppe               3- Sortir");

        if (choix == 1)
        {
            if (Ombre::getVoraciteOmbre() == 0)
            {
                cout << endl << "Vous vous avancez vers cette etrange personne au visage cache. Vous avez beau essayer de regarder son visage vous ne voyez rien, qu'une obscurite intense et irreelle..." << endl
                             << "Pourtant, une voix caverneuse sort soudainement de ce noir profond, vous surprenant." << endl
                             << "\"Salut a toi. Je sais qui tu es, et je sais ce que tu viens faire ici. Il etait temps que quelqu'un vienne mettre un peu d'ordre, cette ville est corrompue jusqu'a la moelle. Je suis pret a t'aider." << endl
                             << "Je n'ai malheureusement pas grand chose a te proposer, a part mon savoir. Des conseils, si tu en veux, je suis pret a t'en echanger... Contre des bonbons." << endl
                             << "Tu ne devrais pas avoir de mal a en trouver, NightCity en est emplie. Mais je vais quand meme t'en donner un, sans rien demander en retour. ";

                if (horloge.getJour() <= 1)
                {
                    cout << "Ta cible est entouree de sbires. A vrai dire, plus que les bonbons," << endl
                         << "c'est de monstres qu'est infestee cette ville. Et je sais ou se trouve l'un d'eux, ou plutot l'une. ";
                }
                Ombre::conseilDonne(horloge.getJour());
                Ombre::setVoraciteOmbre(1);
            }

            else if (Ombre::getVoraciteOmbre() == 7001)
            {
                cout << endl << "Vous vous approchez de l'endroit ou se trouvait la silouhette mais vous ne trouvez plus personne. Un monticule de papiers de bonbons jonche le sol...";
            }

            else
            {
                int prixBonbons(0);
                cout << endl;
                if (Ombre::getVoraciteOmbre() < 1001)
                {
                    prixBonbons = 500;
                    cout << "Vous vous approchez de la silouhette immobile dans le coin." << endl
                         << "\"As-tu des bonbons a m'echanger ? Je ne t'en demanderai que " << prixBonbons << ".\"";
                }
                else if (Ombre::getVoraciteOmbre() < 3001)
                {
                    prixBonbons = 1000;
                    cout << "Vous vous approchez de la silouhette, mais quelque chose semble ne pas aller, sa posture est beaucoup moins droite que d'habitude... " << endl
                         << "\"Tu as des bonbons pour moi ? J'en veux " << prixBonbons << ".\"" << endl
                         << "Quelque chose dans sa voix vous derange...";
                }
                else if (Ombre::getVoraciteOmbre() < 7001)
                {
                    prixBonbons = 2000;
                    cout << "Vous vous approchez de la silouhette, il semble que son etat empire de plus en plus, vous avez meme l'impression de voir deux lueurs rouge au milieu du vide lui faisant office de visage..." << endl
                         << "\"J'ai besoin de " << prixBonbons << " bonbons, tu les as ?!\"" << endl
                         << "Sa voix n'a desormais plus rien a voir, presque eteinte, sans vie...";
                }

                cout << endl;
                choix = verif(2, "Que voulez-vous faire ?", "1- Accepter                2- Refuser");

                if(choix == 1)
                {
                    if (sac.getBonbons() >= prixBonbons)
                    {
                        cout << endl;
                        sac.retirerBonbons(prixBonbons);
                        if (Ombre::getVoraciteOmbre() < 1001)
                        {
                           cout << "Vous lui tendez les bonbons, il les attrape et les jette a l'interieur de sa capuche." << endl
                                << "\"Merci, ecoute bien ce que je vais te dire.\"" << endl;
                        }
                        else if (Ombre::getVoraciteOmbre() < 3001)
                        {
                           cout << "Vous lui tendez les bonbons, il les recupere precipitamment avant de se les envoyer dans sa capuche." << endl
                                << "\"Merci... A mon tour.\"" << endl;
                        }
                        else if (Ombre::getVoraciteOmbre() < 7001)
                        {
                           cout << "Vous lui tendez les bonbons, il vous les arrache des mains pour vite les engloutir." << endl
                                << "\"Merci, j'en avais besoin ! Mais ce n'est pas pour ca que tu es la !\"" << endl;
                        }
                        Ombre::conseilDonne(horloge.getJour());
                        Ombre::setVoraciteOmbre(prixBonbons);
                    }
                    else
                    {
                        cout << endl << "Il semble que vous n'avez pas assez de bonbons malheureusement...";
                    }
                }

                else if (choix == 2)
                {
                    cout << endl << "Vous decidez que vous n'avez pas besoin d'aide et gardez vos bonbons pour vous.";
                }

            }
        }

        else if (choix == 2)
        {
            sac.ajouterBonbons(10000);
            if (Marchand::getRencontreMarchand() == false)
            {
                cout << endl << "Vous entrez dans cette etrange echoppe. Vous n'y voyez pas grand chose a l'interieur, a part ce qui semble etre un homme derriere un comptoir attaque par la moisissure." << endl
                     << "Vous n'avez pas le temps de vous approchez qu'il vous accueille a bras ouverts." << endl
                     << "\"Bienvenue dans ma modeste boutique ! Il ne vaut mieux pas fouler les rues de cette ville sans une bonne arme a la ceinture pour vous les monstres ! Si tu veux de quoi te defendre, tu es au bon endroit !\"" << endl;
            }
            else
            {
                cout << endl << "Vous entrez dans l'echoppe et retrouvez le marchand au sourire force derriere le comptoir." << endl;
            }

            cout << "\"Veux-tu voir ce que j'ai a vendre ? J'ai de tout !\" Vous le voyez deposer tout son attirail devant vous." << endl;

            bool sortieBoutique(false);
            do
            {
                choix = verif(3, "Quel type d'arme souhaitez-vous acheter ?", "1- Tranchantes                2- Contondantes                3- A distance");
                cout << endl;

                Marchand::afficherArmesBoutique(choix);
                int choixArme(0);
                choixArme = verif(7, "Faites votre choix !", "");
                Marchand::acheterArme(sac, choixArme, choix);

                cout << endl << "Le marchand vous lance un regard inquisiteur. \"Autre chose ?\"" << endl;
                choix = verif(2, "Continuer les emplettes ?", "1- Oui                2- Non");

                if (choix == 2)
                {
                    sortieBoutique = true;
                }

            }while (sortieBoutique == false);


        }

        else if (choix == 3)
        {
            choix = verif(2, "Ou voulez-vous aller ?", "1- Quartier pauvre (30min)              2- Annuler");

            if (choix == 1)
            {
                horloge.ajoutMinutes(30);
                if (horloge.getEpuisement())
                {
                    repaire(joueur, caracJoueur, sac, horloge, ville);
                }
                cout << endl << "Vous vous dirigez en direction du quartier pauvre." << endl;
                quartierPauvre(joueur, caracJoueur, sac, horloge, ville);
                sortie = true;
            }
            else
            {
                cout << endl << "Changement d'avis ?" << endl;
            }
        }
    }while (sortie == false);
}
