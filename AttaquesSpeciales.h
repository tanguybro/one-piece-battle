/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier header de AttaquesSpeciales.c
**/


#ifndef ATTAQUESSPECIALES_H_INCLUDED
#define ATTAQUESSPECIALES_H_INCLUDED

 void attaque_speciale(int *touche_spe, int coteJ, SDL_Rect *posJ, SDL_Rect *posEnnemi, int *special, Personnage *J, Personnage *Ennemi, SDL_Rect *posBarrePV_Ennemi, SDL_Rect *posBarreEnergie, int *ecart_position, int tempsActuel, int *tempsDebutSpe);

#endif
