#include "deer.h"

#define DEER_SIZE 2
#define DEER_SPEED 4
#define DEER_NEEDED_FOOD 4    //per day

#define ADULT_DEER_SIZE 5
#define ADULT_DEER_SPEED 8
#define ADULT_DEER_NEEDED_FOOD 8    //per day

#define DEER_CAN_CLIMB  false
#define DEER_EAT_COUNT 2

Deer::Deer() : Herbivores(DEER_SIZE, DEER_SPEED, DEER_NEEDED_FOOD, DEER_CAN_CLIMB, DEER_EAT_COUNT, 'D')
{
//HACK:You can pass the arguments through the setters
}


//EXIT_SUCCESS = 0:Animal ate
//EXIT_FAILURE = value different of zero: Animal did not eat
int Deer::Eat(Animals *animalEaten, Plants *plantEaten){

    char plantToken = plantEaten->getToken();

    if( plantToken == 'G' ){    //Grass: Seedless

        setEatenFoodAnimal( getEatenFoodAnimal() + getEatCountAnimal() );

        //UNDONE: Check if neededFood is completed

        plantEaten->loseLife( getEatCountAnimal() );

        cout << "Deer ate." << endl;
        return EXIT_SUCCESS;
    }
    else if( plantToken == 'O' || plantToken == 'M' ){  //Oak & Maple: Seeded

        if(  abs( getSizeAnimal() - plantEaten->getSize() )  <= 4 ){    //sizePlant  = sizeAnimal + 4

            setEatenFoodAnimal( getEatenFoodAnimal() + getEatCountAnimal());

            //UNDONE: Check if neededFood is completed

            if( plantEaten->getSeeds() > 0 ){   //There are some seeds

                plantEaten->setSeeds( plantEaten->getSeeds() - getEatCountAnimal() );
            }
            else{

                plantEaten->setFoliage( plantEaten->getFoliage() - getEatCountAnimal() );
                plantEaten->loseLife( getEatCountAnimal() );
            }

            cout << "Deer ate." << endl;
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}
