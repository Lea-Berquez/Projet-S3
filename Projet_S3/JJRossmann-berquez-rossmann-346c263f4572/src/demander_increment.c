#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h> 
#include "../include/structures_types.h"
#include "../include/entrees.h"

float demander_increment()
{ 
	printf("Donner l'incrément:"); 
	float Tmax;
	lire_decimal(&Tmax);
	return Tmax; 
}