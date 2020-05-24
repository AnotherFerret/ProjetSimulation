//main et simulateur, init simulation
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "evenements.h"
#include "expo.h"

//initialise l'anneau à -1
void init_anneau()
{
	for(int i = 0; i < taille_anneau; i++)
	{
		anneau[i] = -1;
	}
}


station init_station(int id)
{
	station s;
	
	s.id = id;
	s.file = 0;
	s.temps_attente = 0;
	s.delta = 0;
	s.haut = 0;
	s.bas = 0;
	s.manchon_iteration = 0;
	s.next_packet = expo();
	
	return s;
}

void anneau_tourne()
{
	int memo = anneau[0];
	for(int i = 0; i < taille_anneau-1; i++)
	{
		anneau[i] = anneau[i+1];
	}
	anneau[taille_anneau-1] = memo;
}


void simulateur(FILE* f1)
{
	station s_tab[nombre_stations];
	int i = 0;
	
	init_anneau();
	
	for(int iteration = 150000; iteration > 0; iteration--)
	{
		//initialise les stations à intervalles réguliers
		for(i = 0;i < nombre_stations;i++)
		{
			s_tab[i] = init_station(i*(taille_anneau/nombre_stations));
		}
		
		//tic d'horloge
		for(i = 0; i < nombre_stations && s_tab[i].next_packet > 0 ;i++)
		{
			s_tab[i].next_packet--;
		}
		
		//on fait arriver tous les packets qui doivent arriver, puis genere la prochaine arrivee
		//sans mémoire donc normalement, on se fiche de quand on génère l'arrivee, ça ne changera rien aux intervalles
		for(i = 0; i < nombre_stations && s_tab[i].next_packet == 0 ;i++)
		{
			arrivee_paquet(s_tab[i]);
			s_tab[i].next_packet = expo();
		}
		
		//on tente d'inserer tous les packets de stations ayant une file
		for(i = 0; i < nombre_stations && s_tab[i].file > 0 ;i++)
		{
			insertion_paquet(s_tab[i]);
		}
		
		//on décale tous les objets d'une case
		anneau_tourne();
		
		//on supprime tous les packets qui se retrouvent face à leur envoyeur
		for(i = 0; i < nombre_stations && s_tab[i].id == anneau[s_tab[i].id] ;i++)
		{
			suppression_paquet(s_tab[i]);
		}
	}
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



int main(int argc, char **argv)
{

	FILE* f = fopen("simulation.data", "w");
	srandom(getpid() + time(NULL));
	simulateur(f);
	fclose(f);

	return 0;
}
