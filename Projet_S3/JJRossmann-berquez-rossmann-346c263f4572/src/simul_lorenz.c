#include <stdlib.h>
#include <stdio.h>
#include "../include/structures_types.h"
#include "../include/interaction_fichier.h"
#include "../include/systemes_dynamiques.h"




void simul_lorenz(FILE* fichier , float tpssimulation, float dt, tri coordpos, tri parametres){
	tri vit;
	vit.x = 0;
	vit.y = 0;
	vit.z = 0;
    ecr_fichier(fichier, coordpos, vit, 0.0);
    tri vitesses;
    tri coordonnees;
    coordonnees = coordpos;
    float tps = 0;
    while (tps <= tpssimulation){
        tps = tps+dt;
        vitesses = vitesse_lorenz(coordonnees, parametres);
        coordonnees = position_lorenz(coordonnees, dt, vitesses);
        vit.x = vit.x/10;
        vit.y = vit.y/10;
        vit.z = vit.z/10;
        ecr_fichier(fichier, coordonnees, vitesses, tps);
    }
}
