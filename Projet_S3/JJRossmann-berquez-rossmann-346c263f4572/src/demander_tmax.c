#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h> 
#include "../include/structures_types.h"
#include "../include/entrees.h"

float demander_tmax()
{
	float Tmax;
	printf("Donner Tmax: ");
	lire_decimal(&Tmax); 
	return Tmax; 
}