#include "main.h"

int main(void){
system("clear");
  /*niveau_t* niv1 = nouveau_niveau(10,10);
  initialise_terrain(niv1);
  printf("1\n");
  place_sur_terrain(niv1,4,2,TILE_EMPTY);
  place_sur_terrain(niv1,6,5,TILE_EMPTY);
  printf("1\n");
  affichage_niveau(niv1);*/
  


  // FIX Mettre dans une fonction alternative, pour externaliser le jeu et pouvoir relancer un niveau sans soucis (par exemple)
  afficher_menu();
  int niveauActuel = choix_du_niveau();
  niveau_t* niveau = lecture_du_niveau(niveauActuel);
  affichage_niveau(niveau);
  do{
    system("clear");
    printf("Nombre de coups: %d\n", niveau->nombreDePas);
    affichage_niveau(niveau);
    char direction = entree_du_joueur();
    if(direction == LEAVE){
      break;
    }
    deplacement(niveau, direction);
    niveau->nombreDePas++;
  }while(nombre_de_caisse_restante_sur_terrain(niveau) != 0);

  system("clear");
  affichage_niveau(niveau);
  if(nombre_de_caisse_restante_sur_terrain(niveau)==0){
    printf("GG T'AS FINI LE JEU EN %d COUPS !!!!!!!!!!!\n",niveau->nombreDePas); 
    // FIX > Add la fonction pour ajouter le meilleur score //// On garde quoi ? Les 3 meilleurs ???
  }else{
    printf("T'es qu'une sale merde\n");
  }
  liberation_du_niveau(niveau);

  return 0;
}
