/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier de la fonction event
**/


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Evenements.h"
#include "Constantes.h"

void evenement(char touche[], int *continuer)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                touche[event.key.keysym.sym]=1;
            break;

            case SDL_KEYUP:
                touche[event.key.keysym.sym]=0;
            break;

            case SDL_QUIT:
                *continuer = QUITTER;
            break;

            default:
            break;
        }
     }
}
