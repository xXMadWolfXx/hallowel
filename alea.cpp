#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int alea(int option1, int option2)
{
    int resultat; int nombreAlea;
    nombreAlea = (rand()% 100) + 1;

    if (nombreAlea <= option1)
    {
        resultat = 1;
    }
    else if (nombreAlea <= option2)
    {
        resultat = 2;
    }
    else
    {
        resultat = 3;
    }

     return resultat;
}
