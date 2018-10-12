#ifndef BEAR_H
#define BEAR_H

#include "carnivores.h"

class Bear : public Carnivores
{
public:
    Bear();
    int Eat(Animals *animalEaten, Plants *plantEaten);
};



#endif // BEAR_H
