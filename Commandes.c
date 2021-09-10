/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier du menu des commandes
**/


#include <SDL.h>
#include <SDL_image.h>
#include "Evenements.h"
#include "Constantes.h"
#include "FonctionsMenu.h"

void commandes(SDL_Surface* ecran, int *continuer, char touche[], SDL_Surface *fond, SDL_Rect pos0)
{
    int continuer_commandes=1;
    fond = IMG_Load("Menu/Commandes.bmp");

    while(continuer_commandes)
    {
        evenement(touche, continuer);

        if(touche[SDLK_ESCAPE])
        {
            touche[SDLK_ESCAPE] = 0;
            continuer_commandes = 0;
            *continuer = MENU;
        }

        afficher_surfaces(ecran, fond, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0);
        if(*continuer != QUITTER) SDL_Flip(ecran);

        if(*continuer == QUITTER) continuer_commandes = 0;
    }
}

