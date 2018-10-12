#include "animals.h"

Animals::Animals(){} //TODO


Animals::Animals(int SIZE, int SPEED, int EAT_COUNT, bool HIBERNATION, char TOK){

    size = SIZE;
    speed = SPEED;
    eatCount = EAT_COUNT;
    hibernates = HIBERNATION;
    animalToken = TOK;

    //TODO: you hane to initialize and the rest of the members with some starting values
}

//Virtual functions
void Animals::printMembersHerbivores(void){ cout << "vitual Herbivore Animal" << endl; }
void Animals::printMembersCarnivores(void){ cout << "vitual Carnivore Animal" << endl; }
char Animals::getToken(void){ return '$';}

void Animals::setAttack(int attck){ cout << "Animals" << endl; }
void Animals::setDefence(int defnce){ cout << "Animals" << endl; }
int Animals::getAttack(void){ cout << "Animals" << endl; }
int Animals::getDefence(void){ cout << "Animals" << endl; }


int Animals::Eat(Animals *animalEaten, Plants *plantEaten){

    cout << "Animals" << endl;
    return 1;
}


//setters
void Animals::setNameAnimal(char *nameAnimal){ name = nameAnimal; }
void Animals::setSizeAnimal(int sizeAnimal){ size = sizeAnimal; }
void Animals::setHungerCountAnimal(int hungerCountAnimal){ hungerCount = hungerCountAnimal; }
void Animals::setEatenFoodAnimal(int eatenFoodAnimal){ eatenFood = eatenFoodAnimal; }
void Animals::setEatCountAnimal(int eatCountAnimal){ eatCount = eatCountAnimal; }
void Animals::setX_Animal(int xAnimal){ x_y[0] = xAnimal; }
void Animals::setY_Animal(int yAnimal){ x_y[1] = yAnimal; }
void Animals::setSpeedAnimal(int speedAnimal){ speed = speedAnimal; }
void Animals::setIsAlive(bool alive){ isAlive = alive; }
void Animals::setIsHungry(bool hungry){ isHungry = hungry; }
void Animals::setInHeat(bool heat){ inHeat = heat; }
void Animals::setInHibernation(bool hibernation){ inHibernation = hibernation; }
void Animals::setHibernates(bool hibernts){ hibernates = hibernts; }
void Animals::setAnimalToken(char tok){ animalToken = tok; }

//getters
char* Animals::getNameAnimal(void){ return name; }
int  Animals::getSizeAnimal(void){ return size; }
int  Animals::getHungerCountAnimal(void){ return hungerCount; }
int  Animals::getEatenFoodAnimal(void){ return eatenFood; }
int  Animals::getEatCountAnimal(void){ return eatCount; }
int  Animals::getX_Animal(void){ return x_y[0]; }
int  Animals::getY_Animal(void){ return x_y[1]; }
int  Animals::getSpeedAnimal(void){ return speed; }
bool Animals::getIsAlive(void){ return isAlive; }
bool Animals::getIsHungry(void){ return isHungry; }
bool Animals::getInHeat(void){ return inHeat; }
bool Animals::getInHibernation(void){ return inHibernation; }
bool Animals::getHibernates(void){ return hibernates; }
char Animals::getAnimalToken(void){ return animalToken; }

void  Animals::printMembersAnimals(void){

    cout << "Size: " <<  size << endl;
    cout << "Speed: " << speed << endl;
    cout << "EatCount: " << eatCount << endl;
}
