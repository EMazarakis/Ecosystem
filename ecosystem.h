#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H

#include "tile.h"
#include "algae.h"
#include "grass.h"
#include "maple.h"
#include "oak.h"
#include "pine.h"

#include "deer.h"
#include "rabbit.h"
#include "groundhog.h"
#include "salmon.h"
#include "wolf.h"
#include "bear.h"
#include "fox.h"

class Ecosystem
{
public:

    //Conctructors (overloading)
    Ecosystem();
    Ecosystem(int terrainSIZE, char *season);

    ~Ecosystem();

    //I have to make a destructor due to double pointer: **

    //setters
    void setTerrainSize(int size);
    void setDayOfYear(char *dOfy);
    void setBreedRepPeriod(int brp);
    void setGrowthPeriodPlant(int prdPlant);
    void setGrowthPeriodAnimal(int prdAnimal);
    void setBreedingRepPeriodPlant(int repPrdPlant);
    void setBreedingRepPeriodAnimalCarnivores(int repPrdAnimalCarnvrs);
    void setBreedingRepPeriodAnimalHerbivores(int repPrdAnimalHerbvrs);

    //getters
    int getTerrainSize(void);
    char* getDayOfYear(void);
    int getBreedRepPeriod(void);
    Tile** getTerrain(void);
    int getGrowthPeriodPlant(void);
    int getGrowthPeriodAnimal(void);
    int getBreedingRepPeriodPlant(void);
    int getBreedingRepPeriodAnimalCarnivores(void);
    int getBreedingRepPeriodAnimalHerbivores(void);

    //printers
    void printMembersEco(void);
    void printTerrainSnapShot(void);
    void printTerrainSnapShotToFile_txt(char *myFileName);
    int deletingFile(char *myFileName);

    //planters
    void PlacePlants(int algaes, int grass, int mapples, int oaks, int pines);
    void plantingAlgaes(int algaes);
    void plantingGrass(int grass);
    void plantingMaples(int maples);
    void plantingPines(int pines);
    void plantingOaks(int oaks);

    //Create Ground
    void MapGenerator(void);
    void GenerateRiver(int N);
    void GenerateLake(int x, int y);
    void GenerateHills(int x, int y, int size);
    void GenerateMeadow(void);

    //breeder
    void PlaceAnimals(int deer, int rabbit, int groundhog, int salmon, int fox, int bear, int wolf);
    void breedingDeer(int deer);
    void breedingRabbit(int rabbit);
    void breedingGroundhog(int groundhog);
    void breedingSalmon(int salmon);
    void breedingFox(int fox);
    void breedingBear(int bear);
    void breedingWolf(int wolf);

    void RunEcosystem(int runDays);
    void ApplySeason(char **season);
    void DailyReset(void);
    void growthAnimals(void);
    void growthPlants(void);
    void AnimaleEating(void);
    void AnimaleEating_V_2(void);
    void AnimalMovement(void);
    void CheckDeadEntities(void);
    void CheckHunger(void);
    void AnimalBreeding(int flag);
    void PlantBreeding(void);
    char FindFreeTile(int x, int y, char kindOfPlant, char searchGround);
    void GiveBirth(char kindPlant, int x, int y);


private:
    Tile **terrain;
    int terrainSize;
    char *dayOfYear;        //FIXME: it means the season of the year
    int breedRepPeriod;     //????????


    int growthPeriodPlant;
    int growthPeriodAnimal;
    int breedingRepPeriodPlant;
    int breedingRepPeriodAnimalCarnivores;
    int breedingRepPeriodAnimalHerbivores;

};

#endif // ECOSYSTEM_H
