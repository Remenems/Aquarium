#include "ComportementMultiple.h"


#include <tuple>

using namespace std;

ComportementMultiple::ComportementMultiple() : IComportement()
{
    //Initialisation de la liste des comportements
    comportements = vector<IComportement*>();
    comportements.push_back(new ComportementPeureuse());
    comportements.push_back(new ComportementGregaire());
    comportements.push_back(new ComportementPrevoyante());
    comportements.push_back(new ComportementKamikaze());
    //Initialisation du comportement actif
    int choix = rand() % comportements.size();
    comportementActif = comportements.at(choix);
    //Initialisation du temps avant changement
    tempsAvantChangementDeComportement = tempsEntreDeuxChangementsDeComportement;
}

ComportementMultiple::~ComportementMultiple()
{
    int s = comportements.size();
    for(int i = 0; i<s;i++)
    {
        delete comportements.at(i);
    }
    //comportementActif est déjà détruit
}


tuple<float,float> ComportementMultiple::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee)
{
    //Vérifie si le temps avant changement de comportement est écoulé
    tempsAvantChangementDeComportement--;
    if(tempsAvantChangementDeComportement<=0)
    {
        int choix = rand() % comportements.size();
        comportementActif = comportements.at(choix);
        tempsAvantChangementDeComportement = tempsEntreDeuxChangementsDeComportement;
    }
    //calcule la direction pour le comportement selectionné
    return comportementActif -> calculDirection(voisins, bestioleAssociee);
}
