#ifndef SIMULATEUR_H
#define SIMULATEUR_H

//struct
typedef struct station
{
	int id;					//position initiale sur l'anneau
	int file;				//paquets en attente
	int temps_attente;		//temps perdu
	int delta;				//délaire avant de renvoyer un packet
	int next_packet;
	
	int haut;
	int bas;
	int manchon_iteration;
}station;


#define taille_anneau 150
#define nombre_stations 15

//variables globales
int T;								//temps écoulé

int nombre_paquets; 				//paquets envoyés
int paquet_actif; 					//paquets présents
int tableau_proba[200];				//contient la f° de répartition
int anneau[taille_anneau];			//l'anneau

int longueur_manchon;				//longueur manchon pour cond arrêt
int epsilon;						//hauteur manchon pour cond arrêt

//fonctions

void insertion_paquet(station s);
void arrivee_paquet(station s);
void suppression_paquet(station s);

#endif
