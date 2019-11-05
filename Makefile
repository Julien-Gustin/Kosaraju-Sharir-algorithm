###
## Makefile skeleton
## INFO0030: Projet 2
##
###

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes -g
LD=gcc

# Files
EXEC_WILCOXON=main
MODULES_WILCOXON=main.c kosaraju_sharir.c graphes.c
OBJECTS_WILCOXON=main.o kosaraju_sharir.o graphes.o


EXEC_ALL=main

## Rules

############# WILCOXON #############

main: $(OBJECTS_WILCOXON)
	$(LD) -o $(EXEC_WILCOXON) $(OBJECTS_WILCOXON)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

kosaraju_sharir.o: kosaraju_sharir.c
	$(CC) -c kosaraju_sharir.c -o kosaraju_sharir.o $(CFLAGS)

graphes.o: graphes.c
	$(CC) -c graphes.c -o graphes.o $(CFLAGS)

clean:
	rm -f *.o $(EXEC_ALL) *~
