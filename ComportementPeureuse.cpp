#include "ComportementPeureuse.h"

#include <tuple>

using namespace std;

ComportementPeureuse::ComportementPeureuse() : IComportement()
{
    cout << "cons comp PEUR" << endl;
}

ComportementPeureuse::~ComportementPeureuse()
{
    cout << "des Comportement PEUR" << endl;
}

tuple<float,float> ComportementPeureuse::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee)
{
    if(voisins.size() >= static_cast<long unsigned int>(ComportementPeureuse::seuilAvantPeur))
    {
        //La bestiole change de direction, va dans la direction opposée aux bestioles voisines, à une vitesse x2
        float moyenneDirection = 0;
        for(long unsigned int i = 0; i<voisins.size(); i++)
        {
            moyenneDirection += voisins.at(i)->getDirection() / voisins.size();
        }
        return make_tuple(moyenneDirection + M_PI/* nouvelle directon*/, 2);
    }
    else
    {
        //Ne change pas de direction
        return make_tuple(bestioleAssociee.getDirection(), 1);
    }
}
