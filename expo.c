#include <math.h>
#include <stdlib.h>

//fonction exponentielle, générateurs de données aléatoires à placer ici

double expo(int l)
{
	double r = (double)random()/RAND_MAX;
	double proba = 0.0;
	
	while(r==0 || r == 1)
	{
		r = (double)random()/RAND_MAX;
	}
	proba = -(log(r))/(l*1.0);
	return 1.0;
	//todo : utiliser proba dans le tableau "tableau_proba" déclaré en global pour return la bonne valeur avant prochain packet
}
