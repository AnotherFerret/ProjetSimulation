all:
	gcc  -o simulateur *.c -lm

clean:
	rm -f *.o simulateur *.data *.Rout *.RData
