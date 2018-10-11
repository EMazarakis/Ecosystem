#include "tile.h"

Tile::Tile(){

    endemicPlant= NULL;
    animals = NULL;
    countAnimals = 0;
    environment = '-';
}


void Tile::setEnvironment(char envrmnt){ environment = envrmnt; }

void Tile::setEndemicPlant(Plants *endmcPlnt){ endemicPlant = endmcPlnt; }

void Tile::setCountAnimals(int count){ countAnimals = count; }

void Tile::setAnimalsArray(Animals **anmlPtr){ animals = anmlPtr; }

char Tile::getEnvironment(void){ return environment; }

Plants *Tile::getEndemicPlant(void){ return endemicPlant; }

Animals **Tile::getAnimal(void){ return animals; }

int Tile::getCountAnimals(void){ return countAnimals; }


void Tile::setAnimal(Animals *anml){


    if( animals == NULL ){  //First animal of the tile

        countAnimals = 1;
        animals = new Animals*[countAnimals];
        animals[0] = anml;
    }
    else{       //Tile is populated by some animals

        countAnimals++;

        Animals **tmpPtr;
        tmpPtr = new Animals*[countAnimals];

        for(int i=0; i<(countAnimals-1);i++){

            tmpPtr[i] = animals[i];
        }

        tmpPtr[countAnimals-1] = anml;

        delete[] animals;
        animals = tmpPtr;
    }
}

