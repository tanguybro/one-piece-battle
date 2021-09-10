/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier header de Combat2.c
**/


#ifndef COMBAT2_H_INCLUDED
#define COMBAT2_H_INCLUDED

 void combat2(SDL_Surface* ecran, int *continuer, char touche[], int *perso1, int *perso2, int num_fond_combat);

 typedef struct
 {
     int difpos;
     SDL_Surface *image;
 }Fond;


#endif
