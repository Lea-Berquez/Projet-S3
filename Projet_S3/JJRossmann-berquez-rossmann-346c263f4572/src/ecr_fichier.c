#include <stdlib.h>
#include <stdio.h>
#include "../include/structures_types.h"

int ecr_fichier(FILE* fichier, tri coord, tri vit, float temps){
    fprintf(fichier,"%f %f %f %f %f %f %f\n",temps,coord.x,coord.y,coord.z,(vit.x)/10,(vit.y)/10,(vit.z)/10);
    return 0; 
}
    
