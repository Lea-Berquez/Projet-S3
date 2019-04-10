#include <stdlib.h>
#include <stdio.h>
#include "../include/structures_types.h"

tri vitesse_Rossler(tri coordposition, tri paratrajectoire){
    tri coordvitesse;
    coordvitesse.x = -coordposition.y -coordposition.z;
    coordvitesse.y = coordposition.x + (paratrajectoire.x*coordposition.y);
    coordvitesse.z = paratrajectoire.y + (coordposition.z * (coordposition.x-paratrajectoire.z));
    return coordvitesse;
}
