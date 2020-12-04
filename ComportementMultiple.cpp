#include "ComportementMultiple.h"


#include <tuple>

using namespace std;

ComportementMultiple::ComportementMultiple(Bestiole& bestioleAss) : IComportement(bestioleAss)
{
    comportements = vector<IComportement>();
    comportements.push_back(ComportementPeureuse(bestioleAss));
    comportements.push_back(ComportementGregaire(bestioleAss));
    comportements.push_back(ComportementPrevoyante(bestioleAss));
    comportements.push_back(ComportementKamikaze(bestioleAss));
    int choix = rand() % comportements.size();
    comportementActif = &(comportements.at(choix));
}


tuple<float,float> ComportementMultiple::calculDirection(vector<Bestiole*> voisins)
{
    if(tempsAvantChangementDeComportement<=0)
    {
        int choix = rand() % comportements.size();
        comportementActif = &(comportements.at(choix));
    }
    //calcule la direction pour le comportement selectionné
    return comportementActif -> calculDirection(voisins);
}
