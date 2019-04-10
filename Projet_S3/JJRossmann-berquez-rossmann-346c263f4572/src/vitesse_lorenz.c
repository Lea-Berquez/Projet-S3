#include <stdio.h>
#include "../include/structures_types.h"

tri vitesse_lorenz(tri coordposition, tri paratrajectoire)
{
	tri coordvitesse; 
	coordvitesse.x=paratrajectoire.x*(coordposition.y-coordposition.x); 
	coordvitesse.y=coordposition.x*(paratrajectoire.y-coordposition.z)-coordposition.y; 
	coordvitesse.z=(coordposition.x*coordposition.y)-(paratrajectoire.z*coordposition.z); 
	return coordvitesse; 
}