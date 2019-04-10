#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h> 
#include "../include/structures_types.h" 
#include "../include/entrees.h"


tri demander_position()
{ 
	tri coordposition;
	printf("Donner une valeur pour x:"); 
	lire_decimal(&coordposition.x);
	printf("Donner une valeur pour y:"); 
	lire_decimal(&coordposition.y);
	printf("Donner une valeur pour z:"); 
	lire_decimal(&coordposition.z);
	return coordposition; 
}
