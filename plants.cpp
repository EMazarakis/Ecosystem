#include "plants.h"

Plants::Plants(){}

Plants::Plants(char TOKEN, int BREED, int ILL, int LIFE,int L_FACT){

    token = TOKEN;
    breedingProb = BREED;
    illnessProb = ILL;
    life = LIFE;
    lifeFactor = L_FACT;

    //TODO: you hane to initialize and the rest of the members with some starting values
}

int Plants::getFoliage(void){ cout <<"plants" << endl; }
int Plants::getSeeds(void){ cout <<"plants" << endl; }
int Plants::getSize(void){ cout <<"plants" << endl; }
void Plants::setFoliage(int leafage){ cout <<"plants" << endl; }
void Plants::setSeeds(int semen){ cout <<"plants" << endl; }
void Plants::setSize(int dimension){ cout <<"plants" << endl; }

void Plants::loseLife(int eatenLife){ cout <<"plants" << endl; }



//Definition of getters
char* Plants::getName(){ return name; }
int Plants::getX(){ return x_y[0]; }
int Plants::getY(){ return x_y[1]; }
int Plants::getBreedProb(){ return breedingProb; }
int Plants::getIllProb(){ return illnessProb; }
int Plants::getLife(){ return life; }
int Plants::getLifeFactor(){ return lifeFactor; }
char Plants::getToken(){ return token; }


//Definition of setters
void Plants::setName(char *plantName){ name=plantName; }
void Plants::setX(int x){ x_y[0] = x; }
void Plants::setY(int y){ x_y[1] = y; }
void Plants::setBreedProb(int Bprob){ breedingProb = Bprob; }
void Plants::setIllProb(int Iprob){ illnessProb = Iprob; }
void Plants::setLife(int plantLife){ life = plantLife; }
void Plants::setLifeFactor(int changeLife){ lifeFactor = changeLife; }
void Plants::setToken(char plantSymbol){ token = plantSymbol; }


void Plants::printMembersPlants(void){

    cout << "Token: " << token << endl;
    cout << "Breed: " << breedingProb << endl;
    cout << "Illness: " << illnessProb << endl;
    cout << "Life: " << life << endl;
}
