#include "plants.h"

Plants::Plants(){}

Plants::Plants(char TOKEN, int BREED, int ILL, int LIFE,int L_FACT){

    token = TOKEN;
    breedingProb = BREED;
    illnessProb = ILL;
    life = LIFE;
    lifeFactor = L_FACT;

    //TODO: You have to initialize and the rest of the members with some starting values
}

//-2: Point out virtual function of plants class
int Plants::getFoliage(void){ cout << "plants" << endl; return -2; }
int Plants::getSeeds(void){ cout << "plants" << endl; return -2; }
int Plants::getSize(void){ cout << "plants" << endl; return -2; }

void Plants::setFoliage(int leafage){ cout << "plants" << endl; }
void Plants::setSeeds(int semen){ cout << "plants" << endl; }
void Plants::setSize(int dimension){ cout << "plants" << endl; }
void Plants::loseLife(int eatenLife){ cout << "plants" << endl; }



//Definition of getters
char* Plants::getName(void){ return name; }
int Plants::getX(void){ return x_y[0]; }
int Plants::getY(void){ return x_y[1]; }
int Plants::getBreedProb(void){ return breedingProb; }
int Plants::getIllProb(void){ return illnessProb; }
int Plants::getLife(void){ return life; }
int Plants::getLifeFactor(void){ return lifeFactor; }
char Plants::getToken(void){ return token; }


//Definition of setters
void Plants::setName(char *plantName){ name = plantName; }
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
