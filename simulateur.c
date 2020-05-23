//main et simulateur, init simulation

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

//variables globales
int T = 0;					//temps écoulé
int K = 15;					//nombre stations

int nombre_paquets = 0; 	//paquets envoyés
int paquet_actif = 0; 		//paquets présents
int tableau_proba[200];		//contient la f° de répartition

int longueur_manchon;		//longueur manchon pour cond arrêt
int epsilon;				//hauteur manchon pour cond arrêt

typedef struct station
{
	int id;					//position initiale sur l'anneau
	int file;				//paquets en attente
	int temps_attention;	//temps perdu
	int delta;				//délaire avant de renvoyer un packet
	
	int haut;
	int bas;
	int manchon_iteration;
}station;


void simulateur(FILE* f1)
{
	//todo
}

//manchons pour vérifier la stabilité du système
int condition_arret(long double old, long double new)
{
	//todo
	return 0;
}

//lit f et range les valeurs lue dans le tableau_proba
void fonction_repartition_lecture(FILE* f)
{
	//todo
}

//initialise l'anneau à -1
int* init_anneau(int* tab)
{
	return tab;
}

//un tic d'horloge
void decale_anneau()
{
	//todo
}

int main(int argc, char **argv)
{

	FILE* f = fopen("simulation.data", "w");
	srandom(getpid() + time(NULL));
	simulateur(f);
	fclose(f);

	return 0;
}
