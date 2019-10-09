#ifndef __KOSARAJUSHARIR__
#define __KOSARAJUSHARIR__
#include "graphes.h"
void creerTransposee(char *nomf, GRAPHE *);
/* Creer la Transposee d'une matrice écrite dans le fichier nomf et la traduit en graphe*/
int decroissantDateFin(SOMMET *psommet);
SOMMET *RechercheSommetSuivant(SOMMET *s, int label);
void DFS_run(GRAPHE *g, int transposee, int *tab);
void DFS(GRAPHE *g, SOMMET *s, int *date);
#endif
