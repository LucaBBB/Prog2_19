# Il comando make cerca di realizzare il primo target ("tutti")
# La linea "tutti: $(EXECS)" dice a make che "tutti" dipende
# dai file elencati in EXECS

# opzioni di compilazione le definisco qui una volta per tutte
CFLAGS= -g -Wall -O -std=c99
# compilatore da usare
CC=gcc

EXECS = test_citta array_citta

tutti: $(EXECS)

# file oggetto
coordinate.o: coordinate.c coordinate.h
	$(CC) $(CFLAGS) -c -o coordinate.o coordinate.c

citta.o: citta.c citta.h coordinate.h
	$(CC) $(CFLAGS) -c -o citta.o citta.c

test_citta.o: test_citta.c citta.h coordinate.h
	$(CC) $(CFLAGS) -c -o test_citta.o test_citta.c

array_citta.o: array_citta.c citta.h coordinate.h
	$(CC) $(CFLAGS) -c -o array_citta.o array_citta.c

# eseguibili
test_citta: test_citta.o citta.o coordinate.o
	$(CC) $(CFLAGS) -o test_citta test_citta.o citta.o coordinate.o -lm

array_citta: array_citta.o citta.o coordinate.o
	$(CC) $(CFLAGS) -o array_citta array_citta.o citta.o coordinate.o -lm


clean:
	rm -f $(EXECS) *.o
