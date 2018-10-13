#include "groundhog.h"

#define GROUNDHOG_SIZE 2
#define GROUNDHOG_SPEED 3
#define GROUNDHOG_NEEDED_FOOD 3    //per day

#define ADULT_GROUNDHOG_SIZE 3
#define ADULT_GROUNDHOG_SPEED 5
#define ADULT_GROUNDHOG_NEEDED_FOOD 5    //per day

#define GROUNDHOG_CAN_CLIMB  true
#define GROUNDHOG_EAT_COUNT 1


Groundhog::Groundhog() : Herbivores(GROUNDHOG_SIZE, GROUNDHOG_SPEED, GROUNDHOG_NEEDED_FOOD, GROUNDHOG_CAN_CLIMB, GROUNDHOG_EAT_COUNT, 'G')
{
//HACK:You can pass the arguments through the setters methods
}


int Groundhog::Eat(Animals *animalEaten, Plants *plantEaten){

    char plantToken = plantEaten->getToken();

    if( plantToken == 'G' ){    //Grass: Seedless

        setEatenFoodAnimal( getEatenFoodAnimal() + getEatCountAnimal() );

        //UNDONE: Check if neededFood is completed

        plantEaten->loseLife( getEatCountAnimal() );
        cout << "Groundhog ate." << endl;
        return EXIT_SUCCESS;
    }
    else if( plantToken == 'O' || plantToken == 'M' ){  //Oak & Maple: Seeded

        //UNDONE: also eats pine ???
        //UNDONE: fixing the climbing

        if(  getSizeAnimal() - plantEaten->getSize() >= 0 ){    //sizePlant <= sizeAnimal

            setEatenFoodAnimal( getEatenFoodAnimal() + getEatCountAnimal());

            //UNDONE: Check if needeFood is complete

            if( plantEaten->getSeeds() > 0 ){   //There are some seeds

                plantEaten->setSeeds( plantEaten->getSeeds() - getEatCountAnimal() );
            }
            else{

                plantEaten->setFoliage( plantEaten->getFoliage() - getEatCountAnimal() );
                plantEaten->loseLife( getEatCountAnimal() );
            }

            cout << "Groundhog ate." << endl;
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}
