#ifndef __KOSARAJUSHARIR__
#define __KOSARAJUSHARIR__
#include "graphes.h"
void creerTransposee(char *nomf, GRAPHE *);
/* Creer la Transposee d'une matrice écrite dans le fichier nomf et la traduit en graphe*/

int decroissantDateFin(SOMMET *psommet);
/* renvois un entier correspondant au numéro de sommet dont la date fin est la plus grande */

void affichage(SOMMET *psommet);
/* affiche les "dates" correspondant a son sommets */

void DFS_run(GRAPHE *g, int *tab);
/* le lanceur de l'algorithme */

#endif
