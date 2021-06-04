#ifndef CARACTERISTIQUES_H_INCLUDED
#define CARACTERISTIQUES_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

class Caracteristiques
{
    public :

    Caracteristiques ();
    void changerSexe(int sexe);
    void ajouterCarMonstre(bool carMonstre);
    void resetCarMonstre();
    int getSexe() const;
    std::string getNomMonstre() const;
    bool getCarMonstre(int position) const;

    private :

    int m_sexe;
    std::vector <bool> m_carMonstre;
};



#endif // CARACTERISTIQUES_H_INCLUDED
