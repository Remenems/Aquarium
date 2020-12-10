#include "ComportementPrevoyante.h"

#include <tuple>

using namespace std;

tuple<float,float> ComportementPrevoyante::calculDirection(vector<Bestiole*> voisins)
{
    //TODO Implémentation de caculDirection
    //Evite les trajectoires ???
    return make_tuple(bestioleAssociee.getDirection(),1);
}
