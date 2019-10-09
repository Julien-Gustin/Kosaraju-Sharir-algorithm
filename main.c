#include <stdio.h>
#include <stdlib.h>
#include "graphes.h"
#include "kosaraju_sharir.h"
int main(){
  GRAPHE g;
  GRAPHE g_t;
  int i = 1;
  lireFichier("data.gr",&g);
  SOMMET *STmp = g.premierSommet;
  creerTransposee("data.gr", &g_t);
  printf("%d\n", STmp->adj->dest);
  printf("%d\n", STmp->label);


  while(!STmp->info){
    STmp->info = (i++);
        printf("%d, %d, %d\n", STmp->label, STmp->info, STmp->info2);
    STmp = RechercheSommetSuivant(g.premierSommet, STmp->adj->dest);

}




  afficherGraphe(&g);
  afficherGraphe(&g_t);
  supprimerGraphe(&g_t);
  supprimerGraphe(&g);
}
