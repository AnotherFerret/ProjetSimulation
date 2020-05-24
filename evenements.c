//evenements de la simulation

#include "evenements.h"
#include "expo.h"

//arrivee d'un paquet
void arrivee_paquet(station *s)
{
	nombre_paquets++;
	s->file++;
	s->next_packet = expo();
}

//insertion d'un paquet si possible, augmente le temps d'attente sinon, n'augmente PAS si le temps d'attente est du à delta ! 
//temps d'attente par station car on s'intéresse aux 1 et 10, si on veut total on sommera tout.
void insertion_paquet(station* s)
{
	if(anneau[s->id] == -1)
	{
		if(s->delta <= 0)
		{
			s->file--;
			paquet_actif++;
			s->delta = 10;
			anneau[s->id] = s->id;
			
		}
		
	}
	else
	{
		s->temps_attente++;
	}
}

void suppression_paquet(station s)
{
	paquet_actif--;
	anneau[s.id] = -1;
}


