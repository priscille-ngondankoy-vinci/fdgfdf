CFLAGS=-std=c17 -pedantic -Wvla -Wall -Werror -D_DEFAULT_SOURCE -g

ALL: controleur zombie

controleur: controleur.o  utils.o
	gcc $(CFLAGS) -o controleur controleur.o  utils.o

controleur.o : utils.h controleur.c
	gcc $(CFLAGS) -c controleur.c

zombie: zombie.o  utils.o
	gcc $(CFLAGS) -o zombie zombie.o utils.o

zombie.o: utils.h zombie.c
	gcc $(CFLAGS) -c zombie.c


utils.o: utils.c utils.h
	gcc $(CFLAGS) -c utils.c

clean :
	rm *.o
	rm zombie
