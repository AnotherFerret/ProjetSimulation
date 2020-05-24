modelname = "simulation_temps_attente.data"
data = read.table(modelname)
attach(data)

temps_simulation = V1
temps_attente = V2

plot(temps_simulation,temps_attente,type="l",xlab="temps_simulation en tic",ylab="temps_attente moyen en tic",col="red")
