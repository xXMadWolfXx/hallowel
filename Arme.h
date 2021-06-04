#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED

#include <iostream>
#include <string>


class Arme
{
    public :

    Arme (std::string nomArme, int degatsArme, int typeArme);
    void changer (std::string nomNouvelleArme, int degatsNouvelleArme, int typeNouvelleArme);
    std::string getNomArme() const;
    int getDegatsArme() const;
    int getTypeArme() const;

    private :

    std::string m_nomArme;
    int m_degatsArme;
    int m_typeArme;

};

#endif // ARME_H_INCLUDED
