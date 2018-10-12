#ifndef SALMON_H
#define SALMON_H

#include "herbivores.h"

class Salmon : public Herbivores
{
public:
    Salmon();

    int Eat(Animals *animalEaten, Plants *plantEaten);
};


#endif // SALMON_H
