#include "main.h"

liste_niveaux_t* etats_niveaux;

// Permet de créer une nouvelle liste de niveau, permettant par la suite d'utiliser le retour arrière
liste_niveaux_t* nouvelle_liste_niveaux(int taille) {
  liste_niveaux_t *resultat = malloc(sizeof(liste_niveaux_t));
  init_liste_niveaux (resultat, taille);
  return resultat;
}

// Permet d'initialiser les instances d'une liste de niveau, en fonction de la taille donnée
void init_liste_niveaux(liste_niveaux_t* liste, int taille) {
  liste->memoire = malloc (sizeof (niveau_t *) * taille);
  liste->taille = 0;
  liste->taille_memoire = taille;
}

// Permet de liberer la totalité des niveaux
void liberation_de_la_liste_niveaux(liste_niveaux_t* liste) {
  free(liste->memoire);
  liste->memoire = NULL;
  liste->taille = 0;
  liste->taille_memoire = 0;
}

// Agrandir la liste de niveau pour lui permettre d'accueillir un nouveau niveau, semblable à un tableau dynamique
void agrandir_liste_de_niveaux(liste_niveaux_t *liste, int ajout) {
  if (ajout > 0) {
    niveau_t** nouveau = malloc(sizeof(niveau_t*) * (liste->taille_memoire + ajout));
    memcpy(nouveau, liste->memoire, sizeof(niveau_t*) * liste->taille);
    free(liste->memoire);
    liste->memoire = nouveau;
    liste->taille_memoire += ajout;
  }
}

// Ajouter un niveau à une liste de niveau passer en paramètre
void ajouter_niveau(liste_niveaux_t *liste, niveau_t* niveau) {
  if (liste->taille == liste->taille_memoire) {
    agrandir_liste_de_niveaux (liste, 10);
  }
  liste->memoire[liste->taille] = niveau;
  niveau->indice = liste->taille;
  liste->taille += 1;
}

// FIXME ajouter commentaire
void enlever_dernier_niveau(liste_niveaux_t *liste) {
  if (liste->taille > 0) {
    liberation_du_niveau (haut_de_liste(etats_niveaux));
    liste->taille -= 1;
  }
}
// FIXME ajouter commentaire
niveau_t* haut_de_liste(liste_niveaux_t* liste) {
  if (liste->taille == 0) return NULL;
  return liste->memoire[liste->taille - 1];
}