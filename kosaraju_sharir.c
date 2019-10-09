#include <stdio.h>
#include <stdlib.h>
#include "kosaraju_sharir.h"
#include "graphes.h"

SOMMET *RechercheSommetSuivant(SOMMET *s, int label)
{

  while(s->label != label)
    s = s->suivant;

  return s;
}

static void initCouleur(SOMMET *psommet){
  while(psommet != NULL){
    psommet->couleur = 0;
    psommet = psommet->suivant;
  }
}


int decroissantDateFin(SOMMET *psommet){
  SOMMET *sommetR = psommet;
  int sommetN;
  sommetN = -1;
  while(psommet != NULL){
    if((sommetN < psommet->date.fin) && psommet->info == 0){
      sommetN = psommet->date.fin;
      sommetR = psommet;
    }

    psommet = psommet->suivant;
  }
  sommetR->info = 1;
  //psommet->date.fin = 10;

  return sommetR->label;

}



void DFS_run(GRAPHE *g, int transposee, int *tab){
  SOMMET *psommet = g->premierSommet;
  int date = 1;
  int i = 0;
  initCouleur(g->premierSommet);

  if(transposee)
    psommet = RechercheSommetSuivant(psommet, tab[i]);



  while(psommet != NULL && i < g->nbS - 1){


    if(psommet->couleur == 0)
      DFS(g, psommet, &date);

    if(!transposee)
      psommet = psommet->suivant;

    else{
      i++;
      psommet = RechercheSommetSuivant(g->premierSommet, tab[i]);
    }

  }
  psommet = g->premierSommet;
  while(psommet != NULL){

    psommet->couleur = 0;
    psommet = psommet->suivant;

  }
}

void DFS(GRAPHE *g, SOMMET *s, int *date){
  s->couleur = 1;
  s->date.debut = (*date)++;
  ELTADJ *padj = s->adj;

  while(padj != NULL){
    if(RechercheSommetSuivant(g->premierSommet, padj->dest)->couleur == 0)
      DFS(g, RechercheSommetSuivant(g->premierSommet, padj->dest), date);
    padj = padj->suivant;
  }

  s->date.fin = (*date)++;
}







void creerTransposee(char *nomf, GRAPHE *g_t)
{
  FILE *fp = fopen(nomf, "r"); /* ouvre un fichier en lecture */
  char ligne[MAX+1];
  int nbS = 0;
  int i;
  char **matrice_t;
  int compteurLigne = 0;
  int compteurColonne = 0;

  while (fgets(ligne,MAX,fp) != NULL)
    {

      if (ligne[0] != '\n') /* on passe les lignes vides */
				{
					i=0;
          if(nbS ==  0)
        {
          nbS = 1;
					while (ligne[i] != '\n')
						{
							if (ligne[i] == ',') nbS++; //Compte le nombre de sommets
							i++;
						}
          matrice_t = malloc(sizeof(char*) * nbS);
            for(int j = 0; j < nbS; j++)
              matrice_t[j] = malloc(sizeof(char)*nbS);
					i=0; /* on relit la 1ere ligne */

				}
        while(ligne[i] != '\n')
        {
          if(ligne[i] == 'x' || (ligne[i] < '9' && ligne[i] > '0')){ /* on stocke les sommets dans une matrice équivalente au fichier data.gr */
            matrice_t[compteurLigne][compteurColonne] = ligne[i];
            compteurColonne++;

          }
          i++;

        }
        compteurColonne = 0;
        compteurLigne++;

      }

    }

    fclose(fp);

    FILE *fp2 = fopen("matriceT.gr", "w"); /* ouvre un fichier en lecture */
    for(int j = 0; j < nbS; j++){
      for(int i = 0; i < nbS; i++){
        fprintf(fp2, "%c", matrice_t[i][j]); //on inverse les lignes et les colonnes => Transposee de la matrice

        if( i != nbS-1) //Pour éviter de terminer la ligne par une ','
          fprintf(fp2, ",");
      }

      fprintf(fp2, "\n" );
    }


    for(int j = 0; j < nbS; j++)
      free(matrice_t[j]);

    free(matrice_t);

    fclose(fp2);

    lireFichier("matriceT.gr", g_t);
}
