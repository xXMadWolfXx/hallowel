#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Ombre.h"



using namespace std;


Ombre::Ombre(int pvsMax, int pvs, std::string nom, int force, int agilite, std::string nomArme, int degatsArme, int typeArme, int optionsCombat) :
Personnage(pvsMax, pvs, nom, force, agilite, nomArme, degatsArme, typeArme, optionsCombat)
{

}

void Ombre::option1(Personnage &cible)
{

}

string Ombre::conseilsBoss[7] =
{"Tu la trouveras demain soir, dans le pub de la ville. Tu la reconnaitras tout de suite.",
 "Tu la trouveras ce soir, dans le pub de la ville. Tu la reconnaitras tout de suite. Je te conseille de ne pas trop tarder d'ailleurs.",
 "Boss 3", "Boss 4", "Boss 5", "Boss 6", "Boss 7"};

string Ombre::conseils[6] =
{"Fais attention a ne pas trop manger de bonbons, tu ne voudrais pas terminer comme ceux que tu chasses n'est-ce pas ?",
 "Il semblerait que dans ton jardin se trouve une colonie de fourmis geantes, mais elles ne se montrent qu'a ceux qui leur ressemblent.",
 "Prends bien garde au temps, il passe vite... Trop vite...",
 "Tu as surement remarque cette etrange ruelle dans le quartier pauvre, plus les jours avancent et plus les monstres qui y vivent deviennent puissants.",
 "Si tu cherches a voler des bonbons aux enfants, y aller le soir t'apportera plus de chances.",
 "Il est facile de se perdre dans la foret, mais il est possible de trouver un renne egalement. Que fait-il la-bas ? Meme moi je l'ignore, peut-etre attend-il son proprietaire ?"};

int Ombre::voraciteOmbre = 0;

void Ombre::conseilDonne(int jour)
{
    int nombreAlea;
    if(conseilsBoss[jour] != "")
    {
        cout << conseilsBoss[jour];
        conseilsBoss[jour] = "";
    }

    else
    {
        bool nouveauConseil(false);
        do
        {
            nombreAlea = (rand()% 6);
            if (conseils[nombreAlea] != "")
            {
                cout << conseils[nombreAlea];
                conseils[nombreAlea] = "";
                nouveauConseil = true;
            }
        }while(nouveauConseil == false);
    }
}

void Ombre::setVoraciteOmbre(int bonbons)
{
    voraciteOmbre += bonbons;
}

int Ombre::getVoraciteOmbre()
{
    return voraciteOmbre;
}





