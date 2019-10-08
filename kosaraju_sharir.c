#include <stdio.h>
#include <stdlib.h>
#include "kosaraju_sharir.h"
#include "graphes.h"

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
