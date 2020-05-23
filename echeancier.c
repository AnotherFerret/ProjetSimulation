//Structure echeancier et fonctions associées à l'echancier

#define MAXEVENT 100000
#include <stdio.h>


double temps = 0.0;
int n = 0;

typedef struct event
{
	int type;
	double date;
	int etat;
}event;

typedef struct echancier
{
	event tab[MAXEVENT];
	int taille;
}echeancier;

echeancier ech;


void add_event(event ev)
{
	
	if(ech.taille < MAXEVENT)
	{
		
		ech.tab[ech.taille] = ev;
		ech.taille++;
	}
	else
	{
		printf("echeancier plein");
	}
}

void affiche_echeancier()
{
	event e;
	
	printf("temps %f et N = %d taille : %d [ ", temps, n, ech.taille);
	
	for(int i = 0; i<ech.taille; i++)
	{
		e = ech.tab[i];
		if(e.type == 0)
			printf("AC, %lf, %d,", e.date, e.etat);
		if(e.type == 1)
			printf("(FS, %lf, %d),", e.date, e.etat);
	}
	printf("]\n\n");
}
