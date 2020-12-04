#include "ComportementPeureuse.h"

#include <tuple>

using namespace std;

tuple<float,float> ComportementPeureuse::calculDirection(vector<Bestiole*> voisins)
{
    //TODO Implémentation de caculDirection
    if(voisins.size() >= ComportementPeureuse::seuilAvantPeur)
    {
        //La bestiole change de direction, va dans la direction opposée aux bestioles voisines, à une vitesse x2
        return make_tuple(0 /* nvelle directon*/, 2);
    }
    else
    {
        //Ne change pas de direction
        return make_tuple(0 /*meme direction*/, 1);
    }
    
    return make_tuple(0,0);
}
