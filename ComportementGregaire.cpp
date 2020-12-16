#include "ComportementGregaire.h"

#include <tuple>

using namespace std;

ComportementGregaire::ComportementGregaire() : IComportement()
{
    cout << "cons comp GREG" << endl;
}

ComportementGregaire::~ComportementGregaire()
{
    cout << "dest Comportement GREG" << endl;
}

tuple<float,float> ComportementGregaire::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee)
{
    //si on a pas de voisins, on ne change pas la direction ou la vitesse 
    if(voisins.size() == 0)
    {
        float direction = bestioleAssociee.getDirection();
        return make_tuple(direction,1);
    }
    else
    {
        // Calcul des directions moyennes (moyenne pondérée par les vitesses) des bestioles voisines
        float sommeDirect = 0;
        float sommeVitess = 0;
        // pour toutes les bestioles voisines
        for(long unsigned int i = 0; i<voisins.size(); i++)
        {
            sommeDirect += (voisins.at(i)->getDirection() * voisins.at(i)->getVitesse());
            sommeVitess += voisins.at(i)->getVitesse();
        }
        float moyenne = sommeDirect / sommeVitess;
        // Retourne la direction moyenne, et une vitesse x1
        return make_tuple(moyenne,1);
    }
    
    
}
