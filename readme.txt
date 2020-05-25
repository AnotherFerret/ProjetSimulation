Le script "script" compile le programme et générera automatiquement toutes les courbes demandées pour les stations 1 et 10 avec K = 20,22,24
Le fichier "inter_arrivees" duquel est déduit la fonction de répartition doit se trouver dans le repertoire de l'executable .
Les courbes sont générées dans le dossier output.


Les commandes suivantes sont données pour un usage avec d'autres données.
Compilation :
make

Executer le programme :
./simulateur "nombre de stations" "station à observer"

Générer une courbe : 
Rscript R_scripts/Draw.R "nom_sortie.pdf"			//courbe indiquant le temps d'attente au fil du temps
Rscript R_scripts/Draw2.R "nom_sortie.pdf"		//courbe indiquant le nombre de slots remplit au fil du temps
