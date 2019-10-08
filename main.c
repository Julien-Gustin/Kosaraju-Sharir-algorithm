#include <stdio.h>
#include <stdlib.h>
#include "graphes.h"
#include "kosaraju_sharir.h"
int main(){
  GRAPHE g;
  GRAPHE g_t;
  lireFichier("data.gr",&g);
  creerTransposee("data.gr", &g_t);
  afficherGraphe(&g);
  afficherGraphe(&g_t);
  supprimerGraphe(&g_t);
  supprimerGraphe(&g);
}
