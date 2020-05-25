modelname = "simulation_temps_attente_moyen_par_paquet.data"
data = read.table(modelname)
attach(data)
args = commandArgs(trailingOnly=TRUE)

name <- args[1]

temps_simulation = V1
nombre_paquets_actifs = V2

pdf(name, width = 16, height=16)

plot(temps_simulation,nombre_paquets_actifs,type="l",xlab="temps_simulation en tic",ylab="Temps d'attente moyen par paquet en tic",col="red")

dev.off()
