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
  
  afficher_menu();
  
  niveau_t* niveau = lecture_du_niveau(choix_du_niveau());
  affichage_niveau(niveau);
  int nombre_de_move = 0;
  do{
    system("clear");
    printf("Nombre de coups: %d\n", nombre_de_move);
    affichage_niveau(niveau);
    char direction = entree_du_joueur();
    deplacement(niveau, direction);
    nombre_de_move++;
  }while(nombre_de_caisse_restante_sur_terrain(niveau) != 0);

  system("clear");
  affichage_niveau(niveau);
  printf("GG T'AS FINI LE JEU EN %d COUPS !!!!!!!!!!!\n",nombre_de_move);

  return 0;
}
