#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/structures_types.h"
#include "../include/entrees.h"
#include "../include/choix.h"
#include "../include/interaction_fichier.h"
#include "../include/simulation.h"
#include "../include/systemes_dynamiques.h"
#include "../include/gnuplot_i.h"
#include "../include/notation_polonaise_inversee.h"



int
main ( int argc , char * argv[] )
{
    printf("Quel système dynamique voulez-vous utilisez?\n1 Attracteur de Lorenz\n2 Attracteur de Rössler\n3 Attracteur de Hénon\n4 Système donné par l'utilisateur sous forme de notation polonaise inversée\n Faites votre choix en donnant le numéro correspondant: ");
    int i;
    do{
        lire_entier(&i);
        if (i != 1 && i != 2 && i != 3 && i!=4){
            printf("Pas un nombre correspondant à un système. Veuillez réessayer: ");
        }
    }while (i != 1 && i != 2 && i != 3 && i!=4);
    
    float dt;
    dt = demander_increment();
    float tmax;
    tmax = demander_tmax();
    tri coord0;
    coord0 = demander_position();
    tri param;
    param = demander_parametres();
    
    
    printf("Récapitulatif: dt=%f Tmax=%f x0=%f y0=%f z0=%f a=%f b=%f c=%f Système %i\n",dt,tmax,coord0.x,coord0.y,coord0.z,param.x,param.y,param.z,i);
    
    FILE* fichier = NULL;
    fichier = fopen("courbe.dat","w+"); //initialisation du fichier qui contiendra les coordonnées à un état vide
    fclose(fichier);
    
    fichier = fopen("courbe.dat","a"); // ouverture du fichier pour l'ajout des coordonnées
    
    if (fichier != NULL){
        if (i==1){
            simul_lorenz(fichier , tmax, dt, coord0, param);
        }
        else if (i==2){
            simul_Rossler(fichier , tmax, dt, coord0, param);
        }
        else if (i==3){
            simul_Henon(fichier , tmax, dt, coord0, param);
        }
        else if (i==4)
        {
            simul_npi(fichier, tmax, dt, coord0, param); 
        }
        
        fclose(fichier);
    }
    else{
        printf("Ouverture du fichier impossible\n"); // S'il y a une erreur au niveau de l'ouverture du fichier, le programme s'arrète immédiatement (ce cas ne devrais jamais se produire normalement)
        return 1;
    }
    
    printf("Voulez vous utiliser l'affichage avec des vecteurs?\n1 Oui\n2 Non\n Faites votre choix en donnant le numéro correspondant: ");
    do{
        lire_entier(&i);
        if (i != 1 && i != 2){
            printf("Pas un nombre attendu. Veuillez réessayer: ");
        }
    }while (i != 1 && i != 2);
    
	gnuplot_ctrl * g = gnuplot_init();      // Ouverture d'une session gnuplot
	gnuplot_cmd(g, "set parametric");
    gnuplot_cmd(g, "set terminal wxt");     // On utilise le terminal "wxt" celui ci est normalement utiliséde base par les systèmes d'exploitation, mais on ne sait jamais
	if (i==1){
	    gnuplot_cmd(g, "splot \"courbe.dat\" u 2:3:4:5:6:7 with vectors"); // Avec vecteurs
	}
	else{
	    gnuplot_cmd(g, "splot \"courbe.dat\" u 2:3:4"); // Sans vecteurs
	}
    
	sleep(300);                             // La fenètre reste ouverte 300 secondes
	gnuplot_close(g);                       // la session gnuplot est fermée
    
    return 0 ;
}

