#ifndef RABBIT_H
#define RABBIT_H

#include "herbivores.h"

class Rabbit : public Herbivores
{
public:
    Rabbit();

    int Eat(Animals *animalEaten, Plants *plantEaten);
};


#endif // RABBIT_H
