#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h> 
#include "../include/structures_types.h"
#include <string.h>
#include <malloc.h>
#include "../include/systemes_dynamiques.h"
#include "../include/notation_polonaise_inversee.h" 

void simul_npi(FILE* fichier , float tpssimulation, float dt, tri coordposition, tri coordparametre){
    float t1[20]; 
	float t2[20];
	float t3[20];
	int n1; 
	int n2; 
	int n3; 
	npi_initialisation(t1, t2, t3, &n1, &n2, &n3);
	tri coordvitesse;
	coordvitesse.x=0;
	coordvitesse.y=0;
	coordvitesse.z=0;
	float tps; 
	tps=0; 
	ecr_fichier(fichier, coordposition, coordvitesse, tps);
	while (tps<tpssimulation)
	{
	    tps=tps+dt; 
		coordvitesse = calcul( coordparametre, coordposition, t1, t2, t3, n1, n2, n3); 
		coordposition = position_lorenz(coordposition ,dt ,coordvitesse ); 
		coordvitesse.x = coordvitesse.x/10;
        coordvitesse.y = coordvitesse.y/10;
        coordvitesse.z = coordvitesse.z/10;
		ecr_fichier(fichier, coordposition, coordvitesse, tps);
	}
	
}