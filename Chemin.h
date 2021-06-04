#ifndef CHEMIN_H_INCLUDED
#define CHEMIN_H_INCLUDED

#include <iostream>

class Chemin
{
    public :

    Chemin(bool haut, bool droite, bool bas, bool gauche);
    bool getHaut() const;
    bool getBas() const;
    bool getGauche() const;
    bool getDroite() const;

    private :

    bool m_haut;
    bool m_bas;
    bool m_gauche;
    bool m_droite;

};

#endif // CHEMIN_H_INCLUDED
