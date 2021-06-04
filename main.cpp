#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Personnage.h"
#include "Trublion.h"
#include "Sac.h"
#include "Horloge.h"
#include "NightCity.h"
#include "genre.h"
#include "verif.h"
#include "combat.h"
#include "creationPersonnage.h"
#include "lieu1Repaire.h"
#include "creationTrublion.h"



using namespace std;

int main()
{
    Sac sac; Caracteristiques caracJoueur; Horloge horloge; NightCity ville; srand(time(0));
    Personnage joueur("Mad", 0, 0, "Epee legendaire", 50, 1);
    ville.initialisation();
    cout << endl << endl << endl <<"                                                                                                  ~~~~HALLOWEL~~~~" << endl << endl<< endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << "Le jeu a ete pense pour etre joue en plein ecran. Il ne devrait pas y avoir de bugs tant les talents du cerveau derriere le projet sont dementiels..."
    << endl << "Mais sait-on jamais s'il y en a, veuillez ne pas trop en tenir rigueur au developpeur et informez le du probleme.";

    verif(1, "Etes-vous pret ? Tapez 1 pour commencer !", "");
    cout << endl;



    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
         << "Vous etes ce que l'on appelle un"; genre(1, caracJoueur.getSexe());
    cout << " chasseu"; genre(6, caracJoueur.getSexe());
    cout << " de Voraces ! Comme tout monstre, les Voraces adorent les bonbons, tant et si bien qu'ils en perdent toute raison !" << endl
         << "Ils deviennent completement fous et sont prets a tout pour mettre la main sur le plus de bonbons que possible. La plupart sont tres vite demasques et elimines par les chasseurs comme vous. Mais parfois... "
         << endl << "Parfois ils sont plus coriaces ! Plus malins ! Ils savent se cacher, s'entourer de sbires, et deviennent de plus en plus puissants a force de s'empiffrer quotidiennement."
         << endl << "Vous avez eu vent que l'un d'entre eux se trouvait a Night City. Plusieurs chasseurs s'y etaient frottes avant vous, aucun n'en etait revenu. Desormais cette tache vous incombait. "
         << endl << "Jeune chasseu"; genre(6, caracJoueur.getSexe());
    cout<< " que vous etiez, il etait temps de prouver votre valeur !"
        << endl << endl << "Direction Nightcity !" << endl << endl;

    creationPersonnage(joueur, caracJoueur);
    repaire(joueur, caracJoueur, sac, horloge, ville);


    return 0;
}
