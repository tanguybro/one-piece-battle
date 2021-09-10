/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier du main
**/


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Combat2.h"
#include "ChoixFonds.h"
#include "ChoixPersonnages.h"
#include "Commandes.h"
#include "Evenements.h"
#include "Constantes.h"
#include "FonctionsMenu.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *fond = NULL, *selection1 = NULL, *selection2 = NULL;
    SDL_Rect pos0, posSelection1, posSelection2;
    int selection = 1, choix = 0;
    int continuer = MENU, perso1 = NON_SELECTIONNE, perso2 = NON_SELECTIONNE, num_fond_combat = NON_SELECTIONNE;
    char touche[SDLK_LAST]={0};
    pos0.x = 0, pos0.y = 0;

    initialisation(&ecran);
    images_menu(&fond, &selection1, &selection2);

    while(continuer != QUITTER)
    {
        evenement(touche, &continuer);

        choix = selectionner(&selection, touche);
        posSelection(selection, &posSelection1, &posSelection2);
        if(choix == 1) continuer = CHOIX_PERSOS;
        if(choix == 2) continuer = COMMANDES;

        if(continuer == COMMANDES) commandes(ecran, &continuer, touche, fond, pos0);
        if(continuer == CHOIX_PERSOS) choixPersonnages(ecran, &continuer, touche, fond, pos0, &perso1, &perso2);
        if(continuer == CHOIX_FONDS) choixFonds(ecran, &continuer, touche, fond, pos0, &num_fond_combat);
        if(continuer == COMBAT2) combat2(ecran, &continuer, touche, &perso1, &perso2, num_fond_combat);

        afficher_surfaces(ecran, fond, pos0, selection1, posSelection1, selection2, posSelection2, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0);
        if(continuer == MENU) SDL_Flip(ecran);
    }

     TTF_Quit();
     SDL_Quit();

     return EXIT_SUCCESS;

     liberer_surfaces_menu(&ecran, &fond, &selection1, &selection2);
}
