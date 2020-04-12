#ifndef __KOSARAJUSHARIR__
#define __KOSARAJUSHARIR__
#include "graphes.h"
/**
 * creerTransposee
 *
 * Creer la Transposee d'une matrice écrite dans le fichier nomf et la traduit en graphe
 *
 * @param nomf char contenant le nom du fichier
 * @param g_t structure de type GRAPHE
 *
 * @pre: nomf != NULL, g_t != NULL
 * @post: la transposé du graphe a été effectué
 *
 */
void creerTransposee(char *nomf, GRAPHE *g_t);

/**
 * decroissantDateFin
 *
 * renvois un entier correspondant au numéro de sommet dont la date fin est la plus grande
 *
 * @param s structure de type SOMMET
 *
 * @pre: /
 * @post: un entier est renvoyé
 *
 * return : le numéro du sommet
 *
 */
int decroissantDateFin(SOMMET *psommet);

/**
 * DFS_run
 *
 *  lance l'algorithme DSF
 *
 * @param s structure de type SOMMET
 * @param tab pointeur sur int
 *
 * @pre: /
 * @post: l'algorithme DFS a été effectué sur tout les sommets
 *
 */
void DFS_run(GRAPHE *g, int *tab);


#endif
