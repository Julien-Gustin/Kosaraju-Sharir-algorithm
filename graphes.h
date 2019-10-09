#if defined(GRAPHES_H)
#else
#define GRAPHES_H

#define MAX 10000

struct date {
	int debut;
	int fin;
};

struct eltadj {
	int dest;
	int info;
	struct eltadj *suivant;
};

struct sommet {
	int label;
	int couleur; /* 0 = blanc, 1 = rouge, 2 = noir */
	int info;
	struct date date;
	struct sommet *suivant;
	struct eltadj *adj;
};

struct graphe {
	int nbS;
	int nbA;
	int maxS;
	struct sommet *premierSommet;
	struct sommet *dernierSommet;
};

typedef struct graphe GRAPHE;
typedef struct sommet SOMMET;
typedef struct eltadj ELTADJ;


void initialiserGraphe(GRAPHE *);
/*On transmet a cette fonction l’adresse d’une variable de type GRAPHE. Lavariable correspondante sera initialisee au graphe vide.*/


int ajouterSommet(GRAPHE *, int info);
/*On transmet a cette fonction l’adresse d’une variable de type GRAPHE et un entier.
 Le champ maxS est incremente d’une unite, un sommet de labelmaxS(apres incrementation) est ajoute au graphe en fin de liste et ce sommet porte l’information info fournie en argument*/

//Erreur -1 si l’allocation de memoire n’est pas possible

int ajouterArc(GRAPHE *, int a, int b, int info);
/*Cree un nouvel arc du sommet de label a vers le sommet de label b avec l’information supplementaire donnee par "info".
Les arcs sont ranges dans la liste d’adjacence par indice croissant. Si un arc entre a et b existe deja, le champ info est misa jour sans creer de nouvel arc dans la liste d’adjacence.
Cette fonction ne renvoie rien.
Erreur -1 si a n’existe pas
       -2 si b n’existe pas
       -3 si l’allocation de memoire n’est pas possible*/

int supprimerSommet(GRAPHE *, int label);
/*Supprime un sommet et les arcs correspondants (i.e., les arcs ayant leur origine ou leur extremite correspondant a label).
 Cette fonction libere la memoire correspondante.
Erreur -1si le sommet n’existe pas*/

int supprimerArc(GRAPHE *, int a, int b);
/*Supprime l’arc joignant a à b. Cette fonction libere la memoire correspondante.
Erreur -1 si l’arc n’existe pas*/

void supprimerGraphe(GRAPHE *);
/*Supprime entierement un graphe en liberant la memoire correspondante. Enfin de procedure, le graphe est automatiquement reinitialise par la fonction "initialiserGraphe".*/

void afficherGraphe(GRAPHE *);
/*Il s’agit exclusivement d’une fonction d’affichage. Elle affiche à l’ecran la valeur des champs nbS, nbA et maxS ainsi que l’ensemble des sommets, des arcs et des informations qu’ils portent.*/

int lireFichier(char *nomf, GRAPHE *);
/*On fournit a cette fonction le nom d’un fichier de donnees et un pointeur vers une variable de type GRAPHE. Ce fichier doit contenir des champs separes par des virgules (et peut contenir arbitrairement des tabulations et des espaces, ceux-ci ne sont pas pris en compte). Un fichier valide contient des champs formes de nombres ou du seul caracter ex. Chaque ligne (terminee par un retour chariot) doit contenir le meme nombre de champs (les lignes vides sont ignorees). Le i eme champ de la j-i eme ligne du fichier contient le poids de l’arc entre les sommets j et k d’un graphe (on se limite ici a des poids positifs ou nuls). Si ce champ est x, il n’y a pas d’arcs entre les sommetsjetk. Il est inutile d’initialiser le graphe avant d’appeler cette fonction. En effet, un tel appel est effectue en debut de fonction.
Erreur -1 si le fichier n’est pas valide*/

#endif
