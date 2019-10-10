#include <stdio.h>
#include <stdlib.h>
#include "graphes.h"
#include "kosaraju_sharir.h"
int main(){
  GRAPHE g;
  GRAPHE g_t;

  lireFichier("data3.gr",&g);
  SOMMET *psommet = g.premierSommet;
  afficherGraphe(&g);

  creerTransposee("data3.gr", &g_t);
  SOMMET *psommet2 = g_t.premierSommet;

  int *tab = malloc(sizeof(int) * g.nbS);
    if(tab == NULL)
      return -1;

  DFS_run(&g, tab); //lance l'algorithme de parcours en profondeur pour le graphique g

  affichage(psommet);


  for(int i = 0; i < g.nbS; i++)
    tab[i] = decroissantDateFin(g.premierSommet); //ordre de passage dans DFS de la transposee de g


  DFS_run(&g_t, tab); //lance l'algorithme de parcours en profondeur pour la transposee graphique g
  affichage(psommet2);

  free(tab);
  supprimerGraphe(&g_t);
  supprimerGraphe(&g);
}
