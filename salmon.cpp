#include "salmon.h"

#define SALMON_SIZE 1
#define SALMON_SPEED 5
#define SALMON_NEEDED_FOOD 1
#define SALMON_CAN_CLIMB false
#define SALMON_EAT_COUNT 1

Salmon::Salmon() : Herbivores(SALMON_SIZE, SALMON_SPEED, SALMON_NEEDED_FOOD, SALMON_CAN_CLIMB, SALMON_EAT_COUNT, 'S')
{
//HACK:You can pass the arguments through the setters methods
}

int Salmon::Eat(Animals *animalEaten, Plants *plantEaten){

    char plantToken = plantEaten->getToken();

    if( plantToken == 'A' ){     //Algae: Seedless

        setEatenFoodAnimal( getEatenFoodAnimal() + getEatCountAnimal() );

        //UNDONE: Check if neededFood is completed
        plantEaten->loseLife( getEatCountAnimal() );
        cout << "Salmon ate." << endl;
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
