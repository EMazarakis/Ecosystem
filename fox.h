#ifndef FOX_H
#define FOX_H

#include "carnivores.h"

class Fox : public Carnivores
{
public:
    Fox();
    int Eat(Animals *animalEaten, Plants *plantEaten);

};

#endif // FOX_H
