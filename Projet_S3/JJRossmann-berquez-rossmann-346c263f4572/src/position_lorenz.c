#include <stdio.h>
#include "../include/structures_types.h"

tri position_lorenz(tri coordposition, float dt, tri coordvitesse)
{
	coordposition.x=coordposition.x+coordvitesse.x*dt; 
	coordposition.y= coordposition.y+coordvitesse.y*dt; 
	coordposition.z= coordposition.z+coordvitesse.z*dt; 
	return coordposition; 
}