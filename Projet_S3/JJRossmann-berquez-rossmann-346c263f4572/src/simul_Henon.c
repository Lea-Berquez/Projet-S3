#include <stdlib.h>
#include <stdio.h>
#include "../include/structures_types.h"
#include "../include/interaction_fichier.h"
#include "../include/systemes_dynamiques.h"


void simul_Henon(FILE* fichier, float tpssimulation, float dt, tri coordpos, tri parametres){
	tri vit;
	vit.x = 0;
	vit.y = 0;
	vit.z = 0;
    ecr_fichier(fichier, coordpos, vit, 0.0);
    tri coordonnees;
    coordonnees = coordpos;
    float tps = 0;
    while (tps <= tpssimulation){
        tps = tps+dt;
        vit = coordonnees;
        coordonnees = position_Henon(coordonnees, parametres);
        vit.x = (coordonnees.x - vit.x)/(10*dt);
        vit.y = (coordonnees.y - vit.y)/(10*dt);
        vit.z = (coordonnees.z - vit.z)/(10*dt);
        ecr_fichier(fichier, coordonnees, vit, tps);
    }
}
