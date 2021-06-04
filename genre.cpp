#include <iostream>
#include <string>
#include "verif.h"

using namespace std;

void genre(int choix, int sexe)
{
    string reponse;

    if (choix == 1)
    {
        if (sexe == 1)
        {
            reponse = "";
        }
        else if (sexe == 2)
        {
            reponse = "e";
        }
    }

    else if (choix == 2)
    {
        if (sexe == 1)
        {
            reponse = "il";
        }

        else if (sexe == 2)
        {
            reponse = "elle";
        }
    }

    else if (choix == 3)
    {
        if (sexe == 1)
        {
            reponse = "Il";
        }
        else if (sexe == 2)
        {
            reponse = "Elle";
        }
    }

    else if (choix == 4)
    {
        if (sexe == 1)
        {
            reponse = "x";
        }
        else if (sexe == 2)
        {
            reponse = "se";
        }

    }

    else if (choix == 5)
    {
        if (sexe == 1)
        {
            reponse = "Lui";
        }
        else if (sexe == 2)
        {
            reponse = "Elle";
        }
    }

    else if (choix == 6)
    {
        if (sexe == 1)
        {
            reponse = "r";
        }
        else if (sexe == 2)
        {
            reponse = "se";
        }
    }

    else if (choix == 7)
    {
        if (sexe == 1)
        {
            reponse = "homme";
        }
        else if (sexe == 2)
        {
            reponse = "femme";
        }
    }


    cout << reponse;

}
