#include <stdlib.h>
#include <stdio.h>
#include "../include/structures_types.h"

tri position_Henon(tri coordposition, tri paratraj){
    tri ncoord;
    ncoord.x = coordposition.y + 1 - (paratraj.x*coordposition.x*coordposition.x);
    ncoord.y = paratraj.y*coordposition.x;
    ncoord.z = 0;
    return ncoord;
}
