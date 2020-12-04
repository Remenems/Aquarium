#include "ComportementGregaire.h"

#include <tuple>

using namespace std;

tuple<float,float> ComportementGregaire::calculDirection(vector<Bestiole*> voisins)
{
    //TODO Implémentation de caculDirection
    // Calcul des directions moyennes (moyenne pondérée par les vitesses) des bestioles voisines
    
    // Retourne la direction moyenne, et une vitesse x1
    return make_tuple(0 /*Direction moyenne*/,1);
}
