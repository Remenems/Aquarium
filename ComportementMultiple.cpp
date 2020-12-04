#include "ComportementMultiple.h"


#include <tuple>

using namespace std;

ComportementMultiple::ComportementMultiple(Bestiole& bestioleAss) : IComportement(bestioleAss)
{
    //Initialisation de la liste des comportements
    comportements = vector<IComportement>();
    comportements.push_back(ComportementPeureuse(bestioleAss));
    comportements.push_back(ComportementGregaire(bestioleAss));
    comportements.push_back(ComportementPrevoyante(bestioleAss));
    comportements.push_back(ComportementKamikaze(bestioleAss));
    //Initialisation du comportement actif
    int choix = rand() % comportements.size();
    comportementActif = &(comportements.at(choix));
    //Initialisation du temps avant changement
    tempsAvantChangementDeComportement = tempsEntreDeuxChangementsDeComportement;
}


tuple<float,float> ComportementMultiple::calculDirection(vector<Bestiole*> voisins)
{
    //Vérifie si le temps avant changement de comportement est écoulé
    tempsAvantChangementDeComportement--;
    if(tempsAvantChangementDeComportement<=0)
    {
        int choix = rand() % comportements.size();
        comportementActif = &(comportements.at(choix));
        tempsAvantChangementDeComportement = tempsEntreDeuxChangementsDeComportement;
    }
    //calcule la direction pour le comportement selectionné
    return comportementActif -> calculDirection(voisins);
}
