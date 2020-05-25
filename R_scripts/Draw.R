modelname = "simulation_temps_attente.data"
data = read.table(modelname)
attach(data)
args = commandArgs(trailingOnly=TRUE)

name <- args[1]

temps_simulation = V1
temps_attente = V2

pdf(name, width = 16, height=16)

plot(temps_simulation,temps_attente,type="l",xlab="temps_simulation en tic",ylab="% du temps d'attente",col="red")

dev.off()
