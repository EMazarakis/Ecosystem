#include "herbivores.h"
#define TOKEN 'H'

#include <iostream>
using namespace std;

Herbivores::Herbivores(){} //TODO

Herbivores::Herbivores(int SIZE, int SPEED, int NEEDED_FOOD, int CAN_CLIMB, int EAT_COUNT, char TOK) : Animals(SIZE, SPEED, EAT_COUNT, false, TOK)
{
    canClimb = CAN_CLIMB;
    neededFood = NEEDED_FOOD;
    token = TOKEN;
}

//setters
void Herbivores::setToken(char tok){ token = tok; }
void Herbivores::setCanClimb(int climb){ canClimb = climb; }
void Herbivores::setNeededFood(int nFood){ neededFood = nFood; }

//getters
char Herbivores::getToken(void){ return token; }
int Herbivores::getCanClimb(void){ return canClimb; }
int Herbivores::getNeededFood(void){ return neededFood; }


void Herbivores::printMembersHerbivores(void){

    cout << "CanClimb: " <<  canClimb << endl;
    cout << "NeededFood: " << neededFood << endl;
    cout << "Token: " << token << endl;
}

