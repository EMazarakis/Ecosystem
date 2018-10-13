#include "seeded.h"

Seeded::Seeded(): Plants(){}

Seeded::Seeded(int FOL,int SEEDS,int SIZE,char TOKEN,int BREED,int ILL,int LIFE,int L_FACT):Plants(TOKEN,BREED,ILL,LIFE,L_FACT){

    foliage = FOL;
    seeds = SEEDS;
    size = SIZE;
}

int Seeded::getFoliage(void){ return foliage; }

int Seeded::getSeeds(void){ return seeds; }

int Seeded::getSize(void){ return size; }

void Seeded::setFoliage(int leafage){ foliage = leafage; }

void Seeded::setSeeds(int semen){ seeds = semen; }

void Seeded::setSize(int dimension){ size = dimension; }


void Seeded::printMembersSeeded(void){

    cout << "Foliage: " << foliage << endl;
    cout << "Seeds: " << seeds << endl;
    cout << "Size: " << size << endl;
}
