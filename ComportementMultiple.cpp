#include "ComportementMultiple.h"


#include <tuple>

using namespace std;

ComportementMultiple::ComportementMultiple(Bestiole& bestioleAss) : IComportement(bestioleAss)
{
    
    int choix = rand() % comportements.size();
    comportementActif = &(comportements.at(choix));
}


tuple<float,float> ComportementMultiple::calculDirection(vector<Bestiole*> voisins)
{
    //TODO Implémentation de caculDirection
    
    //calcule la direction pour le comportement selectionné
    return comportementActif -> calculDirection(voisins);
}
