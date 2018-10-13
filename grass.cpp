#include "grass.h"

//Initial Values of Grass
#define TOKEN    'G'
#define BREED    15
#define ILL      15
#define LIFE     5
#define L_FACTOR 4

Grass::Grass() : Seedless(TOKEN,BREED,ILL,LIFE,L_FACTOR)
{
//HACK:You can pass the arguments through the setters
}

