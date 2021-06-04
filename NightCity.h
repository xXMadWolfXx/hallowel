#ifndef NIGHTCITY_H_INCLUDED
#define NIGHTCITY_H_INCLUDED

#include <iostream>
#include "Sac.h"
#include <vector>

class NightCity
{
    public :

    NightCity();
    void initialisation();
    bool verifArme(Sac sac, Personnage joueur, std::string nomNouvelleArme);
    bool verifPassage (int lieu);
    void changerArme(Personnage &joueur, Sac &sac, int arme);
    void ajoutPartiesCostume(std::string partieCostume);
    void getPartiesCostume() const;
    int getCostume() const;
    void amelioRepaire();
    int getAmelioRepaire() const;
    bool jardinInsecte(int partieJardin);
    bool getFourmi() const;
    void sortieForet();
    bool verifSortie() const;
    void setRuelle();
    bool getRuelle() const;

    private :

    std::vector <Arme> m_listeArme;
    std::vector <std::string> m_costume;
    std::vector <bool> m_listeLieux;
    std::vector <Personnage> m_listeBoss;
    int m_amelio;
    int m_jardin;
    bool m_fourmi;
    bool m_premiereFois;
    bool m_ruelle;

};

#endif // NIGHTCITY_H_INCLUDED
