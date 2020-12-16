#include "ComportementPrevoyante.h"

#include <tuple>

using namespace std;

ComportementPrevoyante::ComportementPrevoyante() : IComportement()
{
    cout << "cons comp PREV" << endl;
}

tuple<float,float> ComportementPrevoyante::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee)
{
    //TODO Implémentation de caculDirection
    //Evite les trajectoires ???
    return make_tuple(bestioleAssociee.getDirection(),1);
}

ComportementPrevoyante::~ComportementPrevoyante()
{
    cout << "des Comportement PREV" << endl;
}
