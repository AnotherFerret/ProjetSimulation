//main et simulateur, init simulation

#define EPSILON 10e-5
#define MANCHONMAXLENGTH 1000


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

//initialise une station
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

//décale l'anneau d'un slot
void anneau_tourne()
{
	int memo = anneau[0];
	for(int i = 0; i < taille_anneau-1; i++)
	{
		anneau[i] = anneau[i+1];
	}
	anneau[taille_anneau-1] = memo;
}

//affiche l'anneau ( pour tests )
void anneau_affiche(int nbr_stations)
{
	int j = 0;
	for(int i = 0; i < taille_anneau; i++)
	{
		if(i == j * (taille_anneau/nbr_stations) && j < nbr_stations)
		{
			printf("[[%d] station = %d]", anneau[i], i);
			j++;
		}
		else
		{
			printf("[%d]", anneau[i]);
		}
		
	}
}

//vérifie la condition d'arrêt
int condition_arret(double temps_attente_moyen)
{
	if (temps_attente_moyen < bas_manchon || temps_attente_moyen > haut_manchon)
	{
		bas_manchon = temps_attente_moyen - EPSILON/2.0;
		haut_manchon = temps_attente_moyen + EPSILON/2.0;
		longueur_manchon = 0;
	}
	else
	{
		longueur_manchon++;
	}
	if (longueur_manchon == MANCHONMAXLENGTH)
	{
		return 1;
	}
	return 0;
}


void simulateur(FILE* f1,FILE* f2,FILE* f3, int nbr_station, int main_station)
{
	station s_tab[nbr_station];
	int i = 0;
	int temps_simulation = 0;
	
	init_anneau();
	init_tableau_proba();
	

	//initialise les stations à intervalles réguliers
	for(i = 0;i < nbr_station;i++)
	{
		s_tab[i] = init_station(i*(taille_anneau/nbr_station));
	}
		
	for(int iteration = 2000000; iteration > 0; iteration--)
	{
		//tic d'horloge
		for(i = 0; i < nbr_station ;i++)
		{
			if(s_tab[i].next_packet > 0)
			{
				s_tab[i].next_packet--;
			}
		}
		
		//on fait arriver tous les packets qui doivent arriver, puis genere la prochaine arrivee
		//sans mémoire donc normalement, on se fiche de quand on génère l'arrivee, ça ne changera rien aux intervalles
		for(i = 0; i < nbr_station;i++)
		{
			if(s_tab[i].next_packet <= 0)
			{
				arrivee_paquet(&s_tab[i]);
			}
		}
		
		//on tente d'inserer tous les packets de stations ayant une file
		for(i = 0; i < nbr_station;i++)
		{
			if(s_tab[i].file > 0)
			{
				insertion_paquet(&s_tab[i]);
				
			}
			s_tab[i].delta--;
			
		}
		
		//on décale tous les objets d'une case
		anneau_tourne();
		
		//on supprime tous les packets qui se retrouvent face à leur envoyeur
		for(i = 0; i < nbr_station;i++)
		{
			if(s_tab[i].id == anneau[s_tab[i].id])
			{
				suppression_paquet(s_tab[i]);
			}
		}
		//anneau_affiche(nbr_stations);

		temps_simulation ++;
		fprintf(f1,"%d	%lf\n",temps_simulation,(double)(s_tab[main_station].temps_attente)/temps_simulation);
		fprintf(f2,"%d	%d\n",temps_simulation,paquet_actif);
		fprintf(f3,"%d	%lf\n",temps_simulation,(double)(s_tab[main_station].temps_attente)/(s_tab[main_station].nombre_paquets));
		
		
		if (condition_arret((double)(s_tab[main_station].temps_attente)/temps_simulation))
		{
			printf("Arret à l'itération : %d \n",temps_simulation);
			iteration = 0;
		}
		
	}
}

//manchons pour vérifier la stabilité du système



int main(int argc, char **argv)
{

	FILE* f1 = fopen("simulation_temps_attente.data", "w");
	FILE* f2 = fopen("simulation_paquets_actifs.data", "w");
	FILE* f3 = fopen("simulation_temps_attente_moyen_par_paquet.data", "w");
	srandom(getpid() + time(NULL));
	simulateur(f1,f2,f3, atoi(argv[1]), atoi(argv[2]));
	fclose(f1);
	fclose(f2);
	fclose(f3);

	return 0;
}
