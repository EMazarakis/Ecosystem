#include "tile.h"

#include<exception>

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


int Tile::setAnimal(Animals *anml){


    if( animals == NULL ){  //First animal of the tile

        try{

            countAnimals = 1;
            animals = new Animals*[countAnimals];   //possible throw
            animals[0] = anml;
        }
        catch(exception& e){

            cout << "Error allocating memory: " << e.what() << endl;
            return EXIT_FAILURE;    //No need to continue
        }
    }
    else{       //Tile is populated by some animals

        try{

            Animals **tmpPtr;
            countAnimals++;
            tmpPtr = new Animals*[countAnimals];    //possible throw

            for(int i=0; i<(countAnimals-1);i++){

                tmpPtr[i] = animals[i];
            }

            tmpPtr[countAnimals-1] = anml;

            delete[] animals;
            animals = tmpPtr;
        }
        catch(exception& e){

            cout << "Error allocating memory: " << e.what() << endl;
            return EXIT_FAILURE;    //No need to continue
        }
    }

    return EXIT_SUCCESS;
}

