#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h> 
#include "../include/structures_types.h"
#include <string.h>
#include <malloc.h>

void remplace_valeur(float*t, tri paratrajectoire, tri position, int n)
{
	int i; 
	for(i=0; i<n; i=i+1)
	{
		if (t[i]=='x')
		{
			t[i]=position.x;
		}
		else if (t[i]=='y')
		{
			t[i]=position.y; 
		}
		else if (t[i]=='z')
		{
			t[i]=position.z; 
		}
		else if (t[i]=='a')
		{
			t[i]=paratrajectoire.x; 
		}
		else if (t[i]=='b')
		{
			t[i]=paratrajectoire.y; 
		}
		else if (t[i]=='c')
		{
			t[i]=paratrajectoire.z; 
		}
	}
} 

char conversion_chaine_tableau(char*ligne, float*t, int*n)
{
	int i;
	i=0;
	int cp; 
	cp=0; 
	while(*(ligne+i)!='\0')
	{
		if(isspace(*(ligne+i)))
		{
			
		}
		else
		{
			if (*(ligne+i)!='a' && *(ligne+i)!='b' && *(ligne+i)!='c' && *(ligne+i)!='x' && *(ligne+i)!='y' && *(ligne+i)!='z' && *(ligne+i)!='+' &&*(ligne+i)!='*' && *(ligne+i)!='-' && *(ligne+i)!='/')
			{
				return 'e'; 
			}
			else 
			{
				t[cp]=*(ligne+i); 
				cp=cp+1; 	
			}
		}
		i=i+1; 
	}
	*n=cp; 
	return 't'; 
}


float depiler(float*P, int cp)
{
	if (cp<0)
	{
		return 0; 
	}
	else 
	{
		float a; 
		a=P[cp];
		P[cp]=0; 
		return a; 
	}
}

int empiler(float*P, float e, int cp)
{
	P[cp]=e; 
}
	

float npi(float*t, int n)
{
	float p[n]; 
	int cp=0;
	int i; 
	for(i=0; i<n; i=i+1)
	{
		if(t[i]=='+' || t[i]=='-' || t[i]=='*' || t[i]=='/')
		{
			float e; 
			float y; 
			float x; 
			cp=cp-1;
			y=depiler(p,cp);
			cp=cp-1;
			x=depiler(p,cp); 
			if (t[i]=='+')
			{
				e=x+y; 
				empiler(p,e,cp);
				cp=cp+1; 
			}
			else if(t[i]=='-')
			{
				e=x-y; 
				empiler(p,e, cp); 
				cp=cp+1; 
			}
			else if(t[i]=='*')
			{
				e=x*y; 
				empiler(p,e, cp);
				cp=cp+1; 
			}
			else if(t[i]=='/')
			{
				e=x/y; 
				empiler(p,x/y, cp); 
				cp=cp+1; 
			}
		}
		else 
		{
			empiler(p, t[i], cp); 
			cp=cp+1; 
		}
	}
	float res; 
	res=p[0]; 
	return res ; 
}

void npi_initialisation(float*t1, float*t2, float*t3, int*n1, int*n2, int*n3)
{
	char*ligne1; 
	char c1; 
	printf("Rentrez x y ou z pour les positions et a b ou c pour les parametres\n"); 
	printf("equation pour vx: "); 
	scanf("%m[^\n]%c", &ligne1, &c1); 
	while (conversion_chaine_tableau(ligne1, t1, n1)!='t')
	{
		printf("Caractères non reconnus, veuillez réessayer\n"); 
		scanf("%m[^\n]%c", &ligne1, &c1);
	}
	char*ligne2; 
	char c2; 
	printf("equation pour vy: "); 
	scanf("%m[^\n]%c", &ligne2, &c2); 
	while(conversion_chaine_tableau(ligne2, t2, n2)!='t')
	{
		printf("Caractères non reconnus, veuillez réessayer\n"); 
		scanf("%m[^\n]%c", &ligne2, &c2); 
	}
	char*ligne3; 
	char c3; 
	printf("equation pour vz: "); 
	scanf("%m[^\n]%c", &ligne3, &c3); 
	while (conversion_chaine_tableau(ligne3, t3, n3)!='t')
	{
		printf("Caractères non reconnus, veuillez réessayer\n"); 
		scanf("%m[^\n]%c", &ligne3, &c3); 	
	}
	free(ligne1);
	free(ligne2);
	free(ligne3); 
	
}

tri calcul(tri paratrajectoire, tri position, float* t1, float* t2, float* t3, int n1, int n2, int n3)
{
	tri vitesse;
	float t12[20]; 
	float t22[20]; 
	float t32[20]; 
	int i; 
	for(i=0; i<n1; i=i+1)
	{
		t12[i]=t1[i]; 
	}
	i=0; 
	for(i=0; i<n2; i=i+1)
	{
		t22[i]=t2[i]; 
	}
	i=0; 
	for(i=0; i<n3; i=i+1)
	{
		t32[i]=t3[i]; 
	}
	remplace_valeur(t12, paratrajectoire, position, n1);
	remplace_valeur(t22, paratrajectoire, position, n2);
	remplace_valeur(t32, paratrajectoire, position, n3);
	vitesse.x=npi(t12, n1);
	vitesse.y=npi(t22, n2); 
	vitesse.z=npi(t32, n3);
	return vitesse; 
	
}

