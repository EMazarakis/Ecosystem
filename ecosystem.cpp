#include "ecosystem.h"

#include <time.h>   //time functiion
#include <string.h>
#include <fstream>


#define LAKESIZE 3
#define HILLS_NUMBER 3


Ecosystem::Ecosystem(){}

Ecosystem::Ecosystem(int terrainSIZE, char *season){

    terrainSize = terrainSIZE;
    dayOfYear = season;

    terrain = new Tile*[terrainSize];  //arrays  of pointers
//TODO:ERROR EXCEPTION handling

    for(int i=0;i<terrainSize;i++){
//TODO:ERROR EXCEPTION handling
        terrain[i] = new Tile[terrainSize];
    }
}

//Destructor
Ecosystem::~Ecosystem(){
    for(int i=0;i<terrainSize;i++){

        delete[] terrain[i];
    }

    delete[] terrain;
}


void Ecosystem::setTerrainSize(int size){ terrainSize = size; }
void Ecosystem::setDayOfYear(char *dOfy){ dayOfYear = dOfy; }
void Ecosystem::setBreedRepPeriod(int brp){ breedRepPeriod = brp; }
void Ecosystem::setGrowthPeriodPlant(int prdPlant){ growthPeriodPlant = prdPlant; }
void Ecosystem::setGrowthPeriodAnimal(int prdAnimal){ growthPeriodAnimal = prdAnimal; }
void Ecosystem::setBreedingRepPeriodPlant(int repPrdPlant){ breedingRepPeriodPlant = repPrdPlant; }
void Ecosystem::setBreedingRepPeriodAnimalCarnivores(int repPrdAnimalCarnvrs){ breedingRepPeriodAnimalCarnivores = repPrdAnimalCarnvrs; }
void Ecosystem::setBreedingRepPeriodAnimalHerbivores(int repPrdAnimalHerbvrs){ breedingRepPeriodAnimalHerbivores = repPrdAnimalHerbvrs; }

int Ecosystem::getGrowthPeriodPlant(void){ return growthPeriodPlant; }
int Ecosystem::getGrowthPeriodAnimal(void){ return growthPeriodAnimal; }
int Ecosystem::getBreedingRepPeriodPlant(void){ return breedingRepPeriodPlant; }
int Ecosystem::getBreedingRepPeriodAnimalCarnivores(void){ return breedingRepPeriodAnimalCarnivores; }
int Ecosystem::getBreedingRepPeriodAnimalHerbivores(void){ return breedingRepPeriodAnimalHerbivores; }

int Ecosystem::getTerrainSize(void){ return terrainSize; }
char* Ecosystem::getDayOfYear(void){ return dayOfYear; }
int Ecosystem::getBreedRepPeriod(void){ return breedRepPeriod; }
Tile** Ecosystem::getTerrain(void){ return terrain; }


void Ecosystem::printMembersEco(void){

    cout << "TerrainSize: " << terrainSize << endl;
    cout << "BreedRepPeriod: " << breedRepPeriod << endl;
    cout << "Season: " << (*dayOfYear) << endl;
}

void Ecosystem::printTerrainSnapShot(void){

    for(int i=0; i<terrainSize; i++){

        for(int j=0; j<terrainSize; j++){

            cout << terrain[i][j].getEnvironment() << " ";
        }

        cout << endl;
    }
}


int Ecosystem::deletingFile(char *myFileName){

    ifstream check_exist_file(myFileName);      //Stream class to read from files

    if ( check_exist_file ) {                   //checking if the file exists

        check_exist_file.close();

        if( remove(myFileName) != 0 ){    //there was sth wrong when we tried to delete the file

            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}


void Ecosystem::printTerrainSnapShotToFile_txt(char *myFileName){

    ofstream myfile;       // Stream class to write on files
    myfile.open (myFileName, ios::out | ios::app);

    for(int i=0; i<terrainSize; i++){

        for(int j=0; j<terrainSize; j++){

            myfile << terrain[i][j].getEnvironment() << "  ";
        }

        myfile << endl;
    }

    myfile << endl;
    myfile << endl;
    myfile << endl;

    myfile.close();
}


void Ecosystem::GenerateRiver(int N){

    terrain[5][terrainSize-5].setEnvironment('#');

    for(int i=1; i <= N; i++){

        terrain[5][(terrainSize-5)+i].setEnvironment('#');
    }

    //TODO :Missing the probalility of deflection
}


void Ecosystem::GenerateLake(int x, int y){

    for(int i=x; i < (x+LAKESIZE); i++){

        for(int j=y; j < (y+LAKESIZE); j++){

            terrain[i][j].setEnvironment('#');  //# :represent water
        }
    }
}


void Ecosystem::GenerateHills(int x, int y, int size){

    for(int i=x; i < (x+size); i++){

        for(int j=y; j < (y+size); j++){

            terrain[i][j].setEnvironment('^');  //^ :represent hill
        }
    }
}


void Ecosystem::GenerateMeadow(void){

    for(int i=0; i < terrainSize; i++){

        for(int j=0; j < terrainSize; j++){

            terrain[i][j].setEnvironment('"');  //" : represent meadow
        }
    }
}


//Create Ground
void Ecosystem::MapGenerator(void){
    //check x,y for GenerateHills
    int xLake, yLake, size;
    int x,y;

//1
    GenerateMeadow();   //first put the meadow, tricky initialization

    //GenerateRiver();

    srand (time(NULL));     //initialize random seed
    xLake = rand()%(terrainSize-LAKESIZE);  //mod --> [0, (terrainSize-LAKESIZE)-1]
    yLake = rand()%(terrainSize-LAKESIZE);

//3
    GenerateLake(xLake,yLake);     //thirdly put the lake

    for(int i=0; i < HILLS_NUMBER; i++){    //count the number of hills where we create

        size = ( rand()%3 ) + 2;    //random size of the hill: [0,2]+2 --> [2,4]

        x = rand()%(terrainSize-size);  //should be outside the lake grid

        while( (x >= xLake) && (x <= (xLake+LAKESIZE)) ){ //till x should be outside the lake grid

            x = rand()%(terrainSize-size);
        }


        y = rand()%(terrainSize-size);  //should be outside the lake grid

        while( (y >= yLake) && (y <= (yLake+LAKESIZE)) ){ //till y should be outside the lake grid

            y = rand()%(terrainSize-size);
        }

//4
        cout << x << "----" << y << "-----" << size << endl;
        GenerateHills(x,y,size);    //fourthly put the hills
    }
}



//Place Plants
void Ecosystem::PlacePlants(int algaes, int grass, int mapples, int oaks, int pines){

    //planting algaes
    plantingAlgaes(algaes);

    //planting grass
    plantingGrass(grass);

    //planting maples
    plantingMaples(mapples);

    //planting pines
    plantingPines(pines);

    //planting oakes
    plantingOaks(oaks);

}


void Ecosystem::plantingOaks(int oaks){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=oaks; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( terrain[x][y].getEnvironment() != '"'){  //till we find meadows

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setEnvironment('O');  //planting pines
        terrain[x][y].setEndemicPlant(new Oak);
    }
}


void Ecosystem::plantingPines(int pines){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=pines; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( terrain[x][y].getEnvironment() != '^'){  //till we find hills/mountains

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setEnvironment('P');  //planting pines
        terrain[x][y].setEndemicPlant(new Pine);
    }
}


void Ecosystem::plantingMaples(int maples){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=maples; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( (terrain[x][y].getEnvironment() != '"') && (terrain[x][y].getEnvironment() != '^') ){  //till we find solid ground

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setEnvironment('M');  //planting grass
        terrain[x][y].setEndemicPlant(new Maple);
    }
}


void Ecosystem::plantingGrass(int grass){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=grass; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( terrain[x][y].getEnvironment() != '"'){  //till we find meadow

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setEnvironment('G');  //planting grass
        terrain[x][y].setEndemicPlant(new Grass);
    }
}


void Ecosystem::plantingAlgaes(int algaes){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=algaes; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( terrain[x][y].getEnvironment() != '#'){  //till we find water

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setEnvironment('A');  //planting algaes
        terrain[x][y].setEndemicPlant(new Algae);
    }
}



//breeder
void Ecosystem::PlaceAnimals(int deer, int rabbit, int groundhog, int salmon, int fox, int bear, int wolf){

    breedingDeer(deer);

    breedingRabbit(rabbit);

    breedingGroundhog(groundhog);

    breedingSalmon(salmon);

    breedingFox(fox);

    breedingBear(bear);

    breedingWolf(wolf);
}


void Ecosystem::breedingDeer(int deer){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=deer; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( terrain[x][y].getEnvironment() != '"'){  //till we find meadows

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setAnimal(new Deer);
    }
}


void Ecosystem::breedingRabbit(int rabbit){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=rabbit; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( terrain[x][y].getEnvironment() != '"'){  //till we find meadows

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setAnimal(new Rabbit);
    }
}


void Ecosystem::breedingGroundhog(int groundhog){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=groundhog; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( terrain[x][y].getEnvironment() != '"'){  //till we find meadows

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setAnimal(new Groundhog);
    }
}


void Ecosystem::breedingSalmon(int salmon){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=salmon; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( terrain[x][y].getEnvironment() != '#'){  //till we find water

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setAnimal(new Salmon);
    }
}


void Ecosystem::breedingFox(int fox){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=fox; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( terrain[x][y].getEnvironment() != '"'){  //till we find meadow

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setAnimal(new Fox);
    }
}


void Ecosystem::breedingBear(int bear){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=bear; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( terrain[x][y].getEnvironment() != '^'){  //till we find hill

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setAnimal(new Bear);
    }
}


void Ecosystem::breedingWolf(int wolf){

    int x, y;

    srand (time(NULL));

    for(int i=1; i<=wolf; i++){

        x = rand()%terrainSize;
        y = rand()%terrainSize;

        while( (terrain[x][y].getEnvironment() != '"') && (terrain[x][y].getEnvironment() != '^') ){  //till we find meadow OR hill

            x = rand()%terrainSize;
            y = rand()%terrainSize;
        }

        terrain[x][y].setAnimal(new Wolf);
    }
}


void Ecosystem::RunEcosystem(int runDays){


    ApplySeason(&dayOfYear);       //Initialize the season of the Eco

    for(int d=1; d<=runDays; d++){                  //Counter of the days

        if( d%90 == 0 ){ ApplySeason(&dayOfYear); }    //every 90 days change season

        DailyReset();

        //dayOfYear%growthPeriod: growth_Animals_Plants();

        //It's time for plants to growth
        if( d%growthPeriodPlant == 0 ){ growthPlants(); }

        //It's time for animals to growth
        if( d%growthPeriodAnimal == 0 ){ growthAnimals(); }

        for(int hours=1; hours<=24; hours++){       //Counter of the days


            AnimalMovement();

            AnimaleEating();
        }

        CheckHunger();

        CheckDeadEntities();    //Perhaps I have to put it inside the above for

        //It's time for Carnivore animals to reproduce
        if( d%breedingRepPeriodAnimalCarnivores == 0 ){ AnimalBreeding(1); }

        //It's time for Herbivore animals to reproduce
        if( d%breedingRepPeriodAnimalHerbivores == 0 ){ AnimalBreeding(0); }

        //It's time for plants to reproduce
        if( d%breedingRepPeriodPlant == 0 ){ PlantBreeding(); }
    }
}


void Ecosystem::ApplySeason(char **season){

    if( strcmp("Summer",*season) == 0 ){

        growthPeriodPlant = 10;
        growthPeriodAnimal = 30;
        breedingRepPeriodPlant = 10;
        breedingRepPeriodAnimalHerbivores = 8;
        breedingRepPeriodAnimalCarnivores = 9;
        //No Hibernate Animals

        (*season) = "Autumn";
    }
    else if( strcmp("Autumn",*season) == 0 ){

        growthPeriodPlant = 0;      //EXTRA CHECK FOR THAT
        growthPeriodAnimal = 15;
        breedingRepPeriodPlant = 20;
        breedingRepPeriodAnimalHerbivores = 5;
        breedingRepPeriodAnimalCarnivores = 9;
        //No Hibernate Animals

         (*season) = "Winter";
    }
    else if( strcmp("Winter",*season) == 0 ){

        growthPeriodPlant = 10;
        growthPeriodAnimal = 30;
        breedingRepPeriodPlant = 0;   //EXTRA CHECK FOR THAT
        breedingRepPeriodAnimalHerbivores = 18;
        breedingRepPeriodAnimalCarnivores = 10;
        //UNDONE: Hibernate some Animals

        (*season) = "Spring";
    }
    else{       //The current is spring

        growthPeriodPlant = 5;
        growthPeriodAnimal = 20;
        breedingRepPeriodPlant = 10;
        breedingRepPeriodAnimalHerbivores = 12;
        breedingRepPeriodAnimalCarnivores = 11;

        //UNDONE: Hibernate Animals some wake up
        (*season) = "Summer";
    }
}

//Initialize the hunger of the animals
void Ecosystem::DailyReset(void){

    for(int i=0; i<terrainSize; i++)
        for(int j=0; j<terrainSize; j++){

            if( terrain[i][j].getAnimal() != NULL ){    //Found Animal

                int counter = terrain[i][j].getCountAnimals();

                for(int q=0; q<counter; q++){

                    terrain[i][j].getAnimal()[q]->setEatenFoodAnimal(0);
                    terrain[i][j].getAnimal()[q]->setIsHungry(true);
                }
            }
        }
}


void Ecosystem::growthAnimals(void){

    for(int i=0; i<terrainSize; i++)
        for(int j=0; j<terrainSize; j++){

            if( terrain[i][j].getAnimal() != NULL ){    //There animals at this tile

                int counter = terrain[i][j].getCountAnimals();  //How many animals

                for(int q=0; q<counter; q++){   //For every animal

                    char token = terrain[i][j].getAnimal()[q]->getAnimalToken();
                    int size = terrain[i][j].getAnimal()[q]->getSizeAnimal();
                    int speed = terrain[i][j].getAnimal()[q]->getSpeedAnimal();
                    //int neededFood = terrain[i][j].getAnimal()[q]

                    switch (token) {
                    case 'D':           //DEER

                        if( size < 5 ){ terrain[i][j].getAnimal()[q]->setSizeAnimal(size+1); }
                        if( speed < 8 ){ terrain[i][j].getAnimal()[q]->setSpeedAnimal(speed+2); }
                        //TODO:Needed food must be added, perhaps as virtual function
                        break;
                    case 'R':           //RABBIT

                        if( size < 2 ){ terrain[i][j].getAnimal()[q]->setSizeAnimal(size+1); }
                        if( speed < 6 ){ terrain[i][j].getAnimal()[q]->setSpeedAnimal(speed+2); }
                        //TODO:Needed food must be added, perhaps as virtual function
                        break;
                    case 'G':           //GROUNDHOG

                        if( size < 3 ){ terrain[i][j].getAnimal()[q]->setSizeAnimal(size+1); }
                        if( speed < 5 ){ terrain[i][j].getAnimal()[q]->setSpeedAnimal(speed+1); }
                        //TODO:Needed food must be added, perhaps as virtual function
                        break;
                    case 'F':           //FOX

                        if( size < 4 ){ terrain[i][j].getAnimal()[q]->setSizeAnimal(size+1); }
                        if( speed < 6 ){ terrain[i][j].getAnimal()[q]->setSpeedAnimal(speed+1); }
                        //TODO:Needed food must be added, perhaps as virtual function
                        //TODO:Attack must be added, perhaps as virtual function
                        //TODO:Defence must be added, perhaps as virtual function

                        break;
                    case 'B':            //BEAR

                        if( size < 10 ){ terrain[i][j].getAnimal()[q]->setSizeAnimal(size+2); }
                        //TODO:Needed food must be added, perhaps as virtual function
                        //TODO:Attack must be added, perhaps as virtual function
                        //TODO:Defence must be added, perhaps as virtual function
                        break;
                    case 'W':            //WOLF

                        if( size < 7 ){ terrain[i][j].getAnimal()[q]->setSizeAnimal(size+1); }
                        if( speed < 8 ){ terrain[i][j].getAnimal()[q]->setSpeedAnimal(speed+2); }
                        //TODO:Needed food must be added, perhaps as virtual function
                        //TODO:Attack must be added, perhaps as virtual function
                        //TODO:Defence must be added, perhaps as virtual function
                        break;
                    default:
                        cout << "Salmon does not grow up." << endl;
                        break;
                    }
                }
            }
        }
}


void Ecosystem::growthPlants(void){

    for(int i=0; i<terrainSize; i++)
        for(int j=0; j<terrainSize; j++){

            if( terrain[i][j].getEndemicPlant() != NULL ){

                srand (time(NULL));
                char token = terrain[i][j].getEndemicPlant()->getToken();
                int ILL = terrain[i][j].getEndemicPlant()->getIllProb();
                int l_factor = terrain[i][j].getEndemicPlant()->getLifeFactor();
                int prob = (rand()%100) + 1;

                if( token == 'A' || token == 'G' ){

                    int life = terrain[i][j].getEndemicPlant()->getLife();


                    if(  prob > ILL ){  //Growing

                        terrain[i][j].getEndemicPlant()->setLife(life + l_factor);
                        cout << token << " is growing." << endl;
                    }
                    else{               //Not growing

                        terrain[i][j].getEndemicPlant()->setLife(life - l_factor);
                        cout << token << " is not growing nowadays." << endl;
                    }
                }
                else if( token == 'M' || token == 'O' || token == 'P' ){

                    int foliage = terrain[i][j].getEndemicPlant()->getFoliage();
                    int seed = terrain[i][j].getEndemicPlant()->getSeeds();

                    if(  prob > ILL ){  //Growing

                        terrain[i][j].getEndemicPlant()->setFoliage(foliage + l_factor);
                        terrain[i][j].getEndemicPlant()->setSeeds(seed + (2*l_factor));

                        if(foliage%l_factor == 0){

                            terrain[i][j].getEndemicPlant()->setSize(terrain[i][j].getEndemicPlant()->getSize()+1);
                        }
                        cout << token << " is growing." << endl;
                    }
                    else{   //Not Growing

                        terrain[i][j].getEndemicPlant()->setFoliage(foliage - l_factor);
                        terrain[i][j].getEndemicPlant()->setSeeds(seed - (2*l_factor));
                        terrain[i][j].getEndemicPlant()->setSize(terrain[i][j].getEndemicPlant()->getSize()-1);
                        cout << token << " is not growing nowadays." << endl;
                    }
                }
            }
        }
}



void Ecosystem::AnimalMovement(void){
    //TODO: Move animal around the terrain
}


void Ecosystem::AnimaleEating_V_2(void){

    for(int i=0; i<terrainSize; i++)
        for(int j=0; j<terrainSize; j++){

            if( terrain[i][j].getAnimal() != NULL ){    //Animal must eat

                int counter = terrain[i][j].getCountAnimals();

                for(int q=0; q<counter; q++){  //Check every animal at the tile

                     char token = terrain[i][j].getAnimal()[q]->getAnimalToken();

                     //(rabbit OR deer OR groundhog OR salmon) AND plantExist ---> Eat_Animal
                     if( (token == 'D' || token == 'R' || token == 'G' ) && terrain[i][j].getEndemicPlant() != NULL ){

                        //Ground is Meadow so Oak, Maple, Grass
                        //TODO: Perhaps you have to return sth?????
                        terrain[i][j].getAnimal()[q]->Eat(NULL, terrain[i][j].getEndemicPlant());
                     }
                     else if( token == 'S' && terrain[i][j].getEndemicPlant() != NULL ){

                        //Ground is Water so Algae
                        //TODO: Perhaps you have to return sth?????
                        terrain[i][j].getAnimal()[q]->Eat(NULL, terrain[i][j].getEndemicPlant());
                     }

                     if( token == 'B' || token == 'W' || token == 'F' ){    //Carnivores

                        for(int a=0; a<counter; a++){     //Check every animal at the tile if it is eatable ?????

                            //1 = animal has eaten, no need to check further at the tile
                            if( terrain[i][j].getAnimal()[q]->Eat( terrain[i][j].getAnimal()[a], NULL) == 1 ){ break; }
                        }
                    }
                }
            }
        }
}

//----------------------------------------------------------------------------------------------
//XXX: problematic code
void Ecosystem::AnimaleEating(void){

    for(int i=0; i<terrainSize; i++)
        for(int j=0; j<terrainSize; j++){

            if( terrain[i][j].getAnimal() != NULL ){    //Animal must eat

                int counter = terrain[i][j].getCountAnimals();

                for(int q=0; q<counter; q++){  //Check every animal at the tile

                    //eatenFood = eatenFood + eatCount
                    int eatenFood = terrain[i][j].getAnimal()[q]->getEatenFoodAnimal();
                    int eatCount = terrain[i][j].getAnimal()[q]->getEatCountAnimal();
                    char token = terrain[i][j].getAnimal()[q]->getAnimalToken();

                    if( token == 'D' ){  //Deer

                        if( terrain[i][j].getEndemicPlant() != NULL ){  //There is a plant at this tile

                            char plantToken = terrain[i][j].getEndemicPlant()->getToken();

                            if( plantToken == 'G' ){   //Grass: Seedeles

                                    terrain[i][j].getAnimal()[q]->setEatenFoodAnimal( eatenFood  + eatCount );
                                    //UNDONE: Check if needeFood is complete ???

                                    terrain[i][j].getEndemicPlant()->loseLife(eatCount);
                            }
                            else if( plantToken == 'O' || plantToken == 'M' ){  //Oak & Maple: Seeded

                                //absVALUE = | sizeAnimal - sizePlant | <=4
                                int abs_Value = abs( terrain[i][j].getAnimal()[q]->getSizeAnimal() - terrain[i][j].getEndemicPlant()->getSize() );
                                if( abs_Value <= 4 ){   //sizePlant  = sizeAnimal + 4

                                    terrain[i][j].getAnimal()[q]->setEatenFoodAnimal( eatenFood  + eatCount );
                                    //UNDONE: Check if needeFood is complete ???
                                    //UNDONE:SEEDS & FOLIAGE & LOSE LIFE
                                }
                            }
                        }
                    }
                    else if( token == 'R' ){    //Rabbit

                        if( terrain[i][j].getEndemicPlant() != NULL ){  //There is a plant at this tile

                            char plantToken = terrain[i][j].getEndemicPlant()->getToken();

                            if( plantToken == 'G' ){   //Grass: Seedeles

                                    terrain[i][j].getAnimal()[q]->setEatenFoodAnimal( eatenFood  + eatCount );
                                    //UNDONE: Check if needeFood is complete ???

                                    terrain[i][j].getEndemicPlant()->loseLife(eatCount);
                            }
                            else if( plantToken == 'O' || plantToken == 'M' ){  //Oak & Maple: Seeded

                                //absVALUE = | sizeAnimal - sizePlant | <=4
                                int abs_Value = abs( terrain[i][j].getAnimal()[q]->getSizeAnimal() - terrain[i][j].getEndemicPlant()->getSize() );
                                if( abs_Value == 0 ){   //sizePlant  = sizeAnimal

                                    terrain[i][j].getAnimal()[q]->setEatenFoodAnimal( eatenFood  + eatCount );
                                    //UNDONE: Check if needeFood is complete ???
                                    //UNDONE:SEEDS & FOLIAGE & LOSE LIFE
                                }
                            }
                        }
                    }



                }//for of the animals
            }

        }
}
//XXX: problematic code
//----------------------------------------------------------------------------------------------



void Ecosystem::CheckHunger(void){

    for(int i=0; i<terrainSize; i++)
        for(int j=0; j<terrainSize; j++){

            if( terrain[i][j].getAnimal() != NULL ){

                int counter = terrain[i][j].getCountAnimals();

                for(int q=0; q<counter; q++){   //For all the animals

                    if( terrain[i][j].getAnimal()[q]->getIsHungry() ){  //true means that is hungry

                        terrain[i][j].getAnimal()[q]->setHungerCountAnimal( terrain[i][j].getAnimal()[q]->getHungerCountAnimal() + 1 );

                        if( terrain[i][j].getAnimal()[q]->getHungerCountAnimal() == 10 ){   //Animal must die

                            terrain[i][j].getAnimal()[q]->setIsAlive(false);
                        }
                    }
                    else{ terrain[i][j].getAnimal()[q]->setHungerCountAnimal(0); }
                }
            }
        }
}

void Ecosystem::CheckDeadEntities(void){


    for(int i=0; i<terrainSize; i++)
        for(int j=0; j<terrainSize; j++){

            //Remove plant
            if( (terrain[i][j].getEndemicPlant() != NULL) && (terrain[i][j].getEndemicPlant()->getLife() == 0) ){  //Plant exist at this tile & is also dead

                    //You must change the environment
                    terrain[i][j].setEnvironment('D');       //D stands for Dead
                    delete terrain[i][j].getEndemicPlant();
            }

            //Remove Animal
            if( terrain[i][j].getAnimal() != NULL ){            //Animal exists at the tile

                int counter = terrain[i][j].getCountAnimals();  //How many animals exist at the tile
                bool flag = false;

                for(int anml=0; anml<counter; anml++){  //Checking every animal at the tile

                    if( terrain[i][j].getAnimal()[anml]->getIsAlive() == false ){

                        flag = true;    //Removed at least 1 animal
                        delete terrain[i][j].getAnimal()[anml];
                        terrain[i][j].getAnimal()[anml] = NULL;
                        terrain[i][j].setCountAnimals(terrain[i][j].getCountAnimals()-1);
                    }
                }

                if( flag ){     //Re-organize the array of the animals

                    int thesi = 0;              //Indexing for the new array
                    Animals **tmpAnimalsPtr;

                    tmpAnimalsPtr = new Animals*[terrain[i][j].getCountAnimals()];

                    for(int q=0; q<counter; q++){

                        if( terrain[i][j].getAnimal()[q] != NULL ){ //indicate removal of a dead animal

                            tmpAnimalsPtr[thesi] = terrain[i][j].getAnimal()[q];
                            thesi++;
                        }

                        delete[] terrain[i][j].getAnimal();
                        terrain[i][j].setAnimalsArray(tmpAnimalsPtr);   //Set the new array of animal
                    }
                }
            }
        }
}


void Ecosystem::AnimalBreeding(int flag){

    char token;
    int size, counter;

    for(int i=0; i<terrainSize; i++)
        for(int j=0; j<terrainSize; j++){

            if( terrain[i][j].getAnimal() != NULL ){    //There animals at the tile

                counter = terrain[i][j].getCountAnimals();

                for(int q=0; q<counter; q++){   //For all the animals of the tile

                    token = terrain[i][j].getAnimal()[q]->getAnimalToken();
                    size = terrain[i][j].getAnimal()[q]->getSizeAnimal();

                    if( flag == 1 ){    //Carnivores give birth

                        if((token == 'F') & (size == 4)){     //Adult Fox gives birth

                            terrain[i][j].setAnimal(new Fox);
                        }
                        else if((token == 'W') & (size == 7)){    //Adult Wolf gives birth

                            terrain[i][j].setAnimal(new Wolf);
                        }
                        else if((token == 'B') & (size == 10)){     //Adult Bear gives birth

                            terrain[i][j].setAnimal(new Bear);
                        }
                    }
                    else{       //Herbivores give birth

                        if((token == 'D') & (size == 5)){     //Adult Deer gives birth

                            terrain[i][j].setAnimal(new Deer);
                        }
                        else if((token == 'R') & (size == 2)){    //Adult Rabbit gives birth

                            terrain[i][j].setAnimal(new Rabbit);
                        }
                        else if((token == 'G') & (size == 3)){     //Adult Groundhog gives birth

                            terrain[i][j].setAnimal(new Groundhog);
                        }
                        else if((token == 'S') & (size == 1)){ //Adult Salmon gives birth

                            //Salmon does not give birth eventually
                        }
                    }
                }
            }
        }
}


char Ecosystem::FindFreeTile(int x, int y, char kindOfPlant, char searchGround){

    if( kindOfPlant != 'M' ){   //Searching for suitable ground for a plant which is not Maple

        if( -1 < (y-1) ){       //Check LEFT first for free planting ground

            if( terrain[x][y-1].getEnvironment() == searchGround ){ return 'L'; }
        }
        else if( (y+1) < terrainSize ){  //Check RIGHT secondly for free planting ground

            if( terrain[x][y+1].getEnvironment() == searchGround ){ return 'R'; }
        }
        else if( (x+1) < terrainSize ){  //Check DOWN thirdly for free planting ground

             if( terrain[x+1][y].getEnvironment() == searchGround ){ return 'D'; }
        }
        else if( -1 < (x-1) ){   //Check UP fourthly for free planting ground

             if( terrain[x-1][y].getEnvironment() == searchGround ){ return 'U'; }
        }
    }
    else if( kindOfPlant == 'M' ){  //Let's see where we can plant the Maple

        if( -1 < (y-1) ){       //Check LEFT first for free planting ground

            if( (terrain[x][y-1].getEnvironment() == '^') || (terrain[x][y-1].getEnvironment() == '#') ){ return 'L'; }
        }
        else if( (y+1) < terrainSize ){  //Check RIGHT secondly for free planting ground

            if( (terrain[x][y-1].getEnvironment() == '^') || (terrain[x][y-1].getEnvironment() == '#') ){ return 'R'; }
        }
        else if( (x+1) < terrainSize ){  //Check DOWN thirdly for free planting ground

             if( (terrain[x][y-1].getEnvironment() == '^') || (terrain[x][y-1].getEnvironment() == '#') ){ return 'D'; }
        }
        else if( -1 < (x-1) ){   //Check UP fourthly for free planting ground

             if( (terrain[x][y-1].getEnvironment() == '^') || (terrain[x][y-1].getEnvironment() == '#') ){ return 'U'; }
        }
    }

    return 'N'; //Nowhere, there isn't any free tile for the  new planting
}

void Ecosystem::GiveBirth(char kindPlant, int x, int y){

    if( kindPlant == 'G'){  //Grass
        terrain[x][y].setEndemicPlant(new Grass);
        terrain[x][y].setEnvironment('G');
    }
    else if( kindPlant == 'A' ){    //Algae
        terrain[x][y].setEndemicPlant(new Algae);
        terrain[x][y].setEnvironment('A');
    }
    else if( kindPlant == 'M' ){    //Maple
        terrain[x][y].setEndemicPlant(new Maple);
        terrain[x][y].setEnvironment('M');
    }
    else if( kindPlant == 'O' ){    //Oak
        terrain[x][y].setEndemicPlant(new Oak);
        terrain[x][y].setEnvironment('O');
    }
    else if( kindPlant == 'P' ){    //Pine
        terrain[x][y].setEndemicPlant(new Pine);
        terrain[x][y].setEnvironment('P');
    }
}


void Ecosystem::PlantBreeding(void){

    int prob;
    char plantToken, site, ground;

    srand (time(NULL));     //initialize random seed

    prob = (rand()%100) + 1;  //mod --> [1,100],    General prob for all the plants

    for(int i=0; i<terrainSize; i++)
        for(int j=0; j<terrainSize; j++){

            if( terrain[i][j].getEndemicPlant() !=NULL ){   //This tile is occupied by a plant

                //There is a chance for the plant to reproduce due to probabillities
                if( prob <= terrain[i][j].getEndemicPlant()->getBreedProb() ){

                    plantToken = terrain[i][j].getEndemicPlant()->getToken();   //What kind of plant

                    switch (plantToken) {
                    case 'G':

                        ground = '"';   //plant grass, at the Meadow
                        break;
                    case 'A':

                        ground = '#';   //plant algae, at Water
                        break;
                    case 'P':

                        ground = '^';   //plant Pine, at Hill
                        break;
                    case 'O':

                        ground = '"';   //plant Oak, at Meadow
                        break;
                    case 'M':

                        ground = '"'; //plant Maple, at Meadow or Hill.Doesn't matter for the next check
                        break;
                    }

                    //Let's find a free tile for the new plant
                    site = FindFreeTile(j,i, plantToken, ground);

                    switch (site) {
                    case 'L':       //L: left

                        GiveBirth(plantToken, i, j-1);
                        break;
                    case 'R':       //R: right

                        GiveBirth(plantToken, i, j+1);
                        break;
                    case 'D':       //D: down

                        GiveBirth(plantToken, i-1, j);
                        break;
                    case 'U':       //U: up

                        GiveBirth(plantToken, i+1, j);
                        break;
                     case 'N':      //Nowhere

                        cout << "There isn't any free tile for the plant: " << plantToken << endl;
                        break;      //No need for break at the default case
                    }
                }
            }
        }

}

