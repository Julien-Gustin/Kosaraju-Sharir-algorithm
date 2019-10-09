#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graphes.h"
#include "kosaraju_sharir.h"
int main(){
  GRAPHE g;
  GRAPHE g_t;

  lireFichier("data.gr",&g);
  int *tab = malloc(sizeof(int) * g.nbS);
    if(tab == NULL)
      return -1;
  SOMMET *psommet = g.premierSommet;
  creerTransposee("data.gr", &g_t);
  SOMMET *psommet2 = g_t.premierSommet;
  DFS_run(&g, false, tab);


  while(psommet != NULL){

    printf("sommet : %d (%d.%d)\n", psommet->label, psommet->date.debut, psommet->date.fin);
    psommet = psommet->suivant;
  }

  for(int i = 0; i < g.nbS; i++)
    tab[i] = decroissantDateFin(g.premierSommet);


  printf("\n");
    DFS_run(&g_t, true, tab);

  while(psommet2 != NULL){

    printf("sommet : %d (%d.%d)\n", psommet2->label-1, psommet2->date.debut, psommet2->date.fin);
    psommet2 = psommet2->suivant;
  }
  free(tab);
  supprimerGraphe(&g_t);
  supprimerGraphe(&g);
}
