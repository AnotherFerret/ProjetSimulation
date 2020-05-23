OBJS	= echeancier.o evenements.o expo.o simulateur.o
SOURCE	= echeancier.c evenements.c expo.c simulateur.c
HEADER	= 
OUT	= simulation
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

echeancier.o: echeancier.c
	$(CC) $(FLAGS) echeancier.c 

evenements.o: evenements.c
	$(CC) $(FLAGS) evenements.c 

expo.o: expo.c
	$(CC) $(FLAGS) expo.c 

simulateur.o: simulateur.c
	$(CC) $(FLAGS) simulateur.c 


clean:
	rm -f $(OBJS) $(OUT)
