#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "graphes.h"
#include "kosaraju_sharir.h"
int main(int argc, char *argv[]) {
  char *optstring = ":i:";
  char val;
  char *input = NULL;

  while((val=getopt(argc, argv, optstring))!=EOF){
    if(val == 'i')
      input = optarg;
    }
    if(input == NULL){
      printf("Veuillez compiler tel que \n  \" ./main -i nomDuFichier.gr \"");
      return -1;
    }


  GRAPHE g;
  GRAPHE g_t;

  lireFichier(input,&g);
  SOMMET *psommet = g.premierSommet;
  afficherGraphe(&g);

  creerTransposee(input, &g_t);
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
