#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h> 
#include "../include/structures_types.h"
#include "../include/entrees.h"


int lire_format(char*str, void*adr)
{
    int ret1;
    int ret2;
    do 
	{
		ret1=scanf(str, adr); 
		ret2=lire_fin_ligne(); 
		if (ret1!=1 || ret2>0)
		{
		    printf("Saisie non conforme à l'attente, veuillez réessayer\n");
		}
	}while(ret2>0 || ret1!=1); 
	return 0; 
}