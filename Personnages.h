/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier header de Personnages.c
**/


#ifndef PERSONNAGES_H_INCLUDED
#define PERSONNAGES_H_INCLUDED


 typedef struct
 {
     double pv;
     double atk;
     int vitesse;
     int saut;
     double spe;
     double energie;
     int nombreImagesSpe;
     SDL_Surface *mort, *mort2;
     SDL_Surface *normal, *normal2;
     SDL_Surface *deplacement, *deplacement2;
     SDL_Surface *attaque, *attaque2;
     SDL_Surface *defense, *defense2;
     SDL_Surface *actuel;
     SDL_Surface *special[10], *special2[10];
 } Personnage;


 Personnage Personnages(int *perso, SDL_Surface **nom, Personnage *J);

#endif
