#ifndef TILE_H
#define TILE_H

#include "animals.h"

//structural material of the terrain
class Tile
{
public:
    Tile();

    //setters
    void setEnvironment(char envrmnt);
    void setEndemicPlant(Plants *endmcPlnt);
    void setAnimal(Animals *anml);
    void setCountAnimals(int count);
    void setAnimalsArray(Animals **anmlPtr);

    //getters
    char getEnvironment(void);
    int getCountAnimals(void);

    Plants *getEndemicPlant(void);
    Animals ** getAnimal(void);

private:
    char environment;
    Plants *endemicPlant;
    Animals **animals;
    int countAnimals;   //How many animals populate at the tile
};

#endif // TILE_H
