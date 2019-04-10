#include <stdlib.h>
#include <stdio.h>
#include "../include/structures_types.h"

tri position_Rossler(tri coordposition, float dt, tri coordvitesse){
    tri ncoord;
    ncoord.x = coordposition.x + (coordvitesse.x * dt);
    ncoord.y = coordposition.y + (coordvitesse.y * dt);
    ncoord.z = coordposition.z + (coordvitesse.z * dt);
    return ncoord;
}