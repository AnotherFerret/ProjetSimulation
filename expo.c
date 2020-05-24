#include <math.h>
#include <stdlib.h>

#include "expo.h"
#include "evenements.h"

//fonction exponentielle, générateurs de données aléatoires à placer ici

void init_tableau_proba()
{
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    char tmp[30] = "";
    int j = 0;
    int i = 0;
    int k = 0;
    
    for(i = 0; i < 109; i++)
    {
		tableau_proba[i] = 0.0;
	}
    
	fp = fopen("inter_arrivees", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) 
    {
        for(i = 5; line[i] != '\0' ; i++)
        {
			if(line[i] >= '0' && line[i] <= '9' || line[i] == '.' || line[i] == 'e'|| line[i] == '-')
			{
				tmp[j] = line[i];
				j++;
			}
		}
		//printf("%s\n", tmp);
		j = 0;
        //printf("%12.10e\n", strtod(tmp, NULL));
        tableau_proba[k] = strtod(tmp,NULL);
		
		if(k > 0)
		{
			tableau_proba[k] += tableau_proba[k-1];
		}
		k++;
    }
    
    fclose(fp);
    if (line)
        free(line);
}

int expo()
{
	double r = (double)random()/RAND_MAX;
	double proba = 0.0;
	int temps = 0;
	
	while(r==0 || r == 1)
	{
		r = (double)random()/RAND_MAX;
	}
	proba =  -(log(r))/(l*1.0);
	
	for(temps = 0; proba > tableau_proba[temps] && temps < 108; temps++)
	{
		;
	}
	return temps;
	//todo : utiliser proba dans le tableau "tableau_proba" déclaré en global pour return la bonne valeur avant prochain packet
}
