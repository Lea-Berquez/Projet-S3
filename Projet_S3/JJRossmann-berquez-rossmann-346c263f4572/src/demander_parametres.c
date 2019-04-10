#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h> 
#include "../include/structures_types.h"
#include "../include/entrees.h"

tri demander_parametres()
{ 
	tri coordparametre;
	printf("Donner une valeur pour le premier parametre:"); 
	lire_decimal(&coordparametre.x);
	printf("Donner une valeur pour le deuxieme parametre:"); 
	lire_decimal(&coordparametre.y);
	printf("Donner une valeur pour le troisième parametre:"); 
	lire_decimal(&coordparametre.z);
	return coordparametre; 
}