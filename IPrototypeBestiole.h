#ifndef _PROTOTYPE_BEST_H_
#define _PROTOTYPE_BEST_H_

/* interface du design pattern Prototype */

class IPrototypeBestiole
{
    public:
    virtual IPrototypeBestiole* clone() = 0;
};

#endif _PROTOTYPE_BEST_H_