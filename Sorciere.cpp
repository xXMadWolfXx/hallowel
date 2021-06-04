#include <iostream>
#include <string>
#include "Sorciere.h"


using namespace std;


Sorciere::Sorciere(int pvsMax, int pvs, std::string nom, int force, int agilite, std::string nomArme, int degatsArme, int typeArme, int optionsCombat) :
Personnage(pvsMax, pvs, nom, force, agilite, nomArme, degatsArme, typeArme, optionsCombat)
{

}

void Sorciere::option1(Personnage &cible)
{

}

bool Sorciere::rencontreSorciere = false;

void Sorciere::setRencontreSorciere()
{
    rencontreSorciere = true;
}

bool Sorciere::getRencontreSorciere()
{
    return rencontreSorciere;
}


