#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "graphes.h"
#include "kosaraju_sharir.h"

int main(int argc, char *argv[]) {
  char *optstring = ":i:";
  char val;
  char *input = NULL;

  /* Création du graphe g et sa transposee */
 GRAPHE g;
 GRAPHE g_t;


  /* Regarde les arguments du programme */
  while((val=getopt(argc, argv, optstring))!=EOF){
    if(val == 'i')
      input = optarg;
    }
  /* verifie si l'input existe */
    if(input == NULL){
      printf("Veuillez compiler tel que \n  \" ./main -i nomDuFichier.gr \" \n");
      return -1;
    }

  if(lireFichier(input,&g) == -1){
    printf("Veuillez donner un fichier valide et existant\n");
    return -1;
  }

  /* crée la transposee de g à l'aide de l'input du programme */
  creerTransposee(input, &g_t);

  int *tab = malloc(sizeof(int) * g.nbS); // Contient l'odre des visites des sommets
    if(tab == NULL)
      return -1;

  DFS_run(&g, tab); //lance l'algorithme de parcours en profondeur pour le graphique g

  //affichage(g.premierSommet);

  for(int i = 0; i < g.nbS; i++)
    tab[i] = decroissantDateFin(g.premierSommet); //ordre de passage dans DFS de la transposee de g

  DFS_run(&g_t, tab); //lance l'algorithme de parcours en profondeur pour la transposee graphique g
  //affichage(g_t.premierSommet);

  free(tab);
  supprimerGraphe(&g_t);
  supprimerGraphe(&g);
}
