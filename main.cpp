#include <QApplication>
#include <QCoreApplication>
#include <QPainter>
#include <QImage>
#include <assert.h>

#include "mainwindow.h"
#include "ecosystem.h"

#define HOW_MANY_ALGAES 4
#define HOW_MANY_GRASS  4
#define HOW_MANY_MAPLES 3
#define HOW_MANY_OAKS 3
#define HOW_MANY_PINES 3


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //return a.exec();

    int TerrainSize = 12;

     //assert(TerrainSize > 9);
     if( TerrainSize < 10 ){
         cout << "Terrain must have at least 10 tiles." << endl;
         return EXIT_FAILURE;
     }

     Oak var1;
     Pine var2;
     Maple var3;

     Algae var0;
     Grass var01;


     cout << endl;
     cout << "---------- Plants ---------------" << endl;

     var0.printMembersPlants();
     cout << endl;

     var01.printMembersPlants();
     cout << endl;

     var1.printMembersPlants();
     var1.printMembersSeeded();
     cout << endl;

     var2.printMembersPlants();
     var2.printMembersSeeded();
     cout << endl;

     var3.printMembersPlants();
     var3.printMembersSeeded();
     cout << endl;

     cout << "---------- Herbivores Animals  ---------------" << endl;

     Animals *anmls[7];

     anmls[0] = new Deer;
     anmls[1] = new Rabbit;
     anmls[2] = new Groundhog;
     anmls[3] = new Salmon;
     anmls[4] = new Fox;
     anmls[5] = new Bear;
     anmls[6] = new Wolf;

     anmls[0]->printMembersAnimals();
     anmls[0]->printMembersHerbivores();
     cout << endl;

     anmls[1]->printMembersAnimals();
     anmls[1]->printMembersHerbivores();
     cout << endl;

     anmls[2]->printMembersAnimals();
     anmls[2]->printMembersHerbivores();
     cout << endl;

     anmls[3]->printMembersAnimals();
     anmls[3]->printMembersHerbivores();
     cout << endl;

     cout << "---------- Carnivores Animals  ---------------" << endl;

     anmls[4]->printMembersAnimals();
     anmls[4]->printMembersCarnivores();
     cout << endl;

     anmls[5]->printMembersAnimals();
     anmls[5]->printMembersCarnivores();
     cout << endl;

     anmls[6]->printMembersAnimals();
     anmls[6]->printMembersCarnivores();
     cout << endl;

     cout << "-----------------------------------------------" << endl;

     Ecosystem  myEco(TerrainSize,"Summer");

     myEco.MapGenerator();
     myEco.printTerrainSnapShot();

      myEco.deletingFile("Images/example.txt");

     myEco.printTerrainSnapShotToFile_txt("Images/example.txt");
     cout << endl;
     cout << endl;
     myEco.PlacePlants(HOW_MANY_ALGAES,HOW_MANY_GRASS,HOW_MANY_MAPLES,HOW_MANY_OAKS,HOW_MANY_PINES);
     myEco.printTerrainSnapShot();
 //-------------------------------------------------------------------------------------------------

     myEco.printTerrainSnapShotToFile_txt("Images/example.txt");

     myEco.PlaceAnimals(1,1,1,1,1,1,1);

     cout << endl;
     cout << endl;

     Tile **myTerrain = myEco.getTerrain();
     int myTerrainSize = myEco.getTerrainSize();
     int counter;

     for(int i=0; i<myTerrainSize; i++)
         for(int j=0; j<myTerrainSize; j++)
             if(myTerrain[i][j].getAnimal() != NULL ){

                 counter = myTerrain[i][j].getCountAnimals();
                 cout << "Count Animals: " << counter << endl;

                 for(int k=0; k<counter; k++)
                     cout<< myTerrain[i][j].getAnimal()[k]->getAnimalToken() << endl;
             }
 //---------------------------------------------------------------------------------------------------
     cout << endl;
     cout << endl;
     myEco.growthPlants();

     return a.exec();
     //return EXIT_SUCCESS;

}
