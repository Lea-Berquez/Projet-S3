#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h> 
#include "../include/structures_types.h"

int 
lire_fin_ligne()
{
    char c ;
    c=getchar(); 
    int cp;
    cp=0; 
    while(c!='\n')
    {
        if (isspace(c))
        {
        	c=getchar(); 
        	continue; 
        }
        else 
        {
        	c=getchar(); 
            cp=cp+1;
        }
    }
    return cp; 
}