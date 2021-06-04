#include <iostream>

using namespace std;

int calculCompetence (int typeArme, double competence, bool force)
{
    int tampon;
    double calcul;
    if (typeArme == 2)
    {
        if (force)
        {
            competence *= 1.2;
            tampon = competence;
            calcul = tampon + 0.5;
            if (competence > calcul)
            {
                competence ++;
            }
        }
        else
        {
            competence *= 0.8;
            tampon = competence;
            calcul = tampon + 0.5;
            if (competence > calcul)
            {
                competence ++;
            }
        }
    }
    else if (typeArme == 3)
    {
        if (force)
        {
            competence *= 0.8;
            tampon = competence;
            calcul = tampon + 0.5;
            if (competence > calcul)
            {
                competence ++;
            }
        }
        else
        {
            competence *= 1.2;
            tampon = competence;
            calcul = tampon + 0.5;
            if (competence > calcul)
            {
                competence ++;
            }
        }
    }
    return competence;
}
