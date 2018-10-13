#include "carnivores.h"
#define TOKEN 'C'

Carnivores::Carnivores(){} //TODO

Carnivores::Carnivores(int SIZE, int ATTACK, int DEFENCE, int SPEED, int NEEDED_FOOD, int HIBERNATION, char TOK) : Animals(SIZE, SPEED, -1, HIBERNATION, TOK)
{
    //HACK: -1 point out an initial value for EAT_COUNT member
    token = TOKEN;
    attack = ATTACK;
    defence = DEFENCE;
    neededFood = NEEDED_FOOD;
}


//setters
void Carnivores::setAttack(int attck){ attack = attck; }
void Carnivores::setDefence(int defnce){ defence = defnce; }
void Carnivores::setToken(char tok){ token = tok; }
void Carnivores::setCanClimb(int climb){ canClimb = climb; }
void Carnivores::setNeededFood(int nFood){ neededFood = nFood; }


//getters
int Carnivores::getAttack(void){ return attack; }
int Carnivores::getDefence(void){ return defence; }
char Carnivores::getToken(void){ return token; }
int Carnivores::getCanClimb(void){ return canClimb; }
int Carnivores::getNeededFood(void){ return neededFood; }



void Carnivores::printMembersCarnivores(void){

    cout << "Attack: " <<  attack << endl;
    cout << "Defence: " <<  defence << endl;
    cout << "NeededFood: " << neededFood << endl;
    cout << "Token: " << token << endl;
}
