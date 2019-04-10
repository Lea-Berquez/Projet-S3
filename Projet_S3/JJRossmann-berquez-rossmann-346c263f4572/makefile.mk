bin/programme: lib/simulation.a lib/choix.a lib/entrees.a lib/interaction_fichier.a lib/systemes_dynamiques.a lib/libgnuplot_i.o lib/npi.a
	gcc -o bin/programme src/main.c -I include include/structures_types.h include/gnuplot_i.h -L lib lib/simulation.a lib/systemes_dynamiques.a lib/choix.a lib/interaction_fichier.a lib/entrees.a lib/libgnuplot_i.o lib/npi.a



lib/libgnuplot_i.o: src/gnuplot_i.c
	gcc -c src/gnuplot_i.c -o lib/libgnuplot_i.o



lib/simulation.a: lib/simul_lorenz.o lib/simul_Rossler.o lib/simul_Henon.o lib/simul_npi.o
	ar rcs lib/simulation.a lib/simul_lorenz.o lib/simul_Rossler.o lib/simul_Henon.o lib/simul_npi.o

lib/simul_lorenz.o: src/simul_lorenz.c
	gcc -c src/simul_lorenz.c -o lib/simul_lorenz.o

lib/simul_Rossler.o: src/simul_Rossler.c
	gcc -c src/simul_Rossler.c -o lib/simul_Rossler.o

lib/simul_Henon.o: src/simul_Henon.c
	gcc -c src/simul_Henon.c -o lib/simul_Henon.o

lib/simul_npi.o: src/simulation_npi.c 
	gcc -c src/simulation_npi.c -o lib/simul_npi.o 



lib/entrees.a:lib/lire_fin_ligne.o lib/lire_format.o lib/lire_entier.o lib/lire_decimal.o
	ar rcs lib/entrees.a lib/lire_fin_ligne.o lib/lire_format.o lib/lire_entier.o lib/lire_decimal.o
	
lib/lire_fin_ligne.o: src/lire_fin_ligne.c
	gcc -c src/lire_fin_ligne.c -o lib/lire_fin_ligne.o
	
lib/lire_format.o: src/lire_format.c
	gcc -c src/lire_format.c -o lib/lire_format.o
	
lib/lire_entier.o: src/lire_entier.c
	gcc -c src/lire_entier.c -o lib/lire_entier.o
	
lib/lire_decimal.o: src/lire_decimal.c
	gcc -c src/lire_decimal.c -o lib/lire_decimal.o



lib/choix.a: lib/demander_increment.o lib/demander_parametres.o lib/demander_position.o lib/demander_tmax.o
	ar rcs lib/choix.a lib/demander_increment.o lib/demander_parametres.o lib/demander_position.o lib/demander_tmax.o

lib/demander_increment.o: src/demander_increment.c
	gcc -c src/demander_increment.c -o lib/demander_increment.o

lib/demander_parametres.o: src/demander_parametres.c
	gcc -c src/demander_parametres.c -o lib/demander_parametres.o

lib/demander_position.o: src/demander_position.c
	gcc -c src/demander_position.c -o lib/demander_position.o

lib/demander_tmax.o: src/demander_tmax.c
	gcc -c src/demander_tmax.c -o lib/demander_tmax.o



lib/interaction_fichier.a: lib/ecr_fichier.o
	ar rcs lib/interaction_fichier.a lib/ecr_fichier.o

lib/ecr_fichier.o: src/ecr_fichier.c
	gcc -c src/ecr_fichier.c -o lib/ecr_fichier.o



lib/systemes_dynamiques.a: lib/position_lorenz.o lib/vitesse_lorenz.o lib/position_Rossler.o lib/vitesse_Rossler.o lib/position_Henon.o
	ar rcs lib/systemes_dynamiques.a lib/position_lorenz.o lib/vitesse_lorenz.o lib/position_Rossler.o lib/vitesse_Rossler.o lib/position_Henon.o

lib/position_lorenz.o: src/position_lorenz.c
	gcc -c src/position_lorenz.c -o lib/position_lorenz.o

lib/vitesse_lorenz.o: src/vitesse_lorenz.c
	gcc -c src/vitesse_lorenz.c -o lib/vitesse_lorenz.o

lib/position_Rossler.o: src/position_Rossler.c
	gcc -c src/position_Rossler.c -o lib/position_Rossler.o

lib/vitesse_Rossler.o: src/vitesse_Rossler.c
	gcc -c src/vitesse_Rossler.c -o lib/vitesse_Rossler.o

lib/position_Henon.o: src/position_Henon.c
	gcc -c src/position_Henon.c -o lib/position_Henon.o



lib/npi.a : lib/notation_polonaise_inversee.o
	ar rcs lib/npi.a lib/notation_polonaise_inversee.o 

lib/notation_polonaise_inversee.o: src/notation_polonaise_inversee.c
	gcc -c src/notation_polonaise_inversee.c -o lib/notation_polonaise_inversee.o