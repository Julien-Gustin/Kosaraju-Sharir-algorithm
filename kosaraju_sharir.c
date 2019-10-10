#include <stdio.h>
#include <stdlib.h>
#include "kosaraju_sharir.h"
#include "graphes.h"

static SOMMET *RechercheSommetSuivant(SOMMET *s, int label);
/* renvois un sommet à l'aide de son numero label */

static void DFS(GRAPHE *g, SOMMET *s, int *date);
/* l'algorithme de parcours en profondeur pour le graphique g */

static void initCouleur(SOMMET *psommet);
/* initialise les "couleurs" des sommets */

static SOMMET *RechercheSommetSuivant(SOMMET *s, int label)
{

  while(s->label != label)
    s = s->suivant;

  return s;
}

static void initCouleur(SOMMET *psommet)
{
  while(psommet != NULL){
    psommet->couleur = 0;
    psommet = psommet->suivant;
  }
}

static void DFS(GRAPHE *g, SOMMET *s, int *date)
{
  s->couleur = 1;
  s->date.debut = (*date)++;
  if(s->info ==  2) // 2 = transposee
    printf("%d", s->label);

  ELTADJ *padj = s->adj;

  while(padj != NULL){ //fait passer tout les sommets dans l'algorithme en suivant les arcs flèchés
    if(RechercheSommetSuivant(g->premierSommet, padj->dest)->couleur == 0){ //on ne renvois pas les sommets qui sont déja passé dans l'algorithme ( couleur = 1 )
      if(s->info ==  2)
        printf(", ");

      DFS(g, RechercheSommetSuivant(g->premierSommet, padj->dest), date);
    }

    padj = padj->suivant;
  }

  s->date.fin = (*date)++;
}

void affichage(SOMMET *sommet)
{
  SOMMET *psommet = sommet;
      printf("\n");
  while(psommet != NULL){
    printf("sommet : %d (%d.%d)\n", psommet->label, psommet->date.debut, psommet->date.fin);
    psommet = psommet->suivant;
  }
    printf("\n");

}


int decroissantDateFin(SOMMET *psommet)
{
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
  return sommetR->label;

}

void DFS_run(GRAPHE *g, int *tab){
  SOMMET *psommet = g->premierSommet;
  int date = 1;
  int i = 0;

  initCouleur(g->premierSommet);
  printf("Les composantes f connexes sont : \n \n");

  if(psommet->info == 2)
    psommet = RechercheSommetSuivant(psommet, tab[i]);

  while(psommet != NULL && i < g->nbS - 1){

    if(psommet->couleur == 0){
      if(psommet->info == 2)
        printf("(");

      DFS(g, psommet, &date);
      if(psommet->info == 2)
        printf(")");

      printf("\n");
}

    if(psommet->info != 2)
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

void creerTransposee(char *nomf, GRAPHE *g_t)
{
  FILE *fp = fopen(nomf, "r"); /* ouvre un fichier en lecture */
  char ligne[MAX+1];
  int nbS = 0;
  int i;
  char **matrice_t;
  int compteurLigne = 0;
  int compteurColonne = 0;
  SOMMET *psommet;

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

    psommet = g_t->premierSommet;

    for(;psommet !=NULL; psommet = psommet->suivant)
      psommet->info = 2; //indique que c'est la transposee

}
