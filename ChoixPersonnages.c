/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier du choix des personnages
**/


#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Constantes.h"
#include "Evenements.h"
#include "ChoixPersonnages.h"
#include "FonctionsMenu.h"


void choixPersonnages(SDL_Surface* ecran, int *continuer, char touche[], SDL_Surface *fond, SDL_Rect pos0, int *perso1, int *perso2)
{
    SDL_Surface *selection1 = NULL, *selection2 = NULL;
    SDL_Surface *cases[10][8]= {{NULL}}, *portraits[10][8] = {{NULL}};
    memset(cases,0,sizeof(cases));
    SDL_Rect posCases[10][8], posSelection[10][8], posPortrait1, posPortrait2;
    int continuer_choix_persos=1;
    int ligne1 = 0, colonne1 = 0, ligne2 = 0, colonne2 = 4;

    *perso1 = NON_SELECTIONNE;
    *perso2 = NON_SELECTIONNE;

    initialisation_pos_choix_persos(&posPortrait1, &posPortrait2, posCases);
    charger_images_choix_persos(&fond, cases, portraits);
    creation_selection_choix_persos(ecran, &selection1, &selection2);

    while(continuer_choix_persos)
    {
        evenement(touche, continuer);

        if(touche[SDLK_ESCAPE])
        {
            touche[SDLK_ESCAPE]=0;
            continuer_choix_persos = 0;
            *continuer = MENU;
        }

        if(*perso1 == NON_SELECTIONNE) selectionner_perso1(perso1, &ligne1, &colonne1, ligne2, colonne2, touche);
        if(*perso2 == NON_SELECTIONNE) selectionner_perso2(perso2, &ligne2, &colonne2, ligne1, colonne1, touche);
        pos_selection_persos(ligne1, colonne1, posSelection, posCases);
        pos_selection_persos(ligne2, colonne2, posSelection, posCases);
        affichage_choix_persos(ecran, fond, selection1, selection2, cases, portraits, pos0, posSelection, posCases, posPortrait1, posPortrait2, perso1, perso2, ligne1, ligne2, colonne1, colonne2, continuer);

        if(*perso1 != NON_SELECTIONNE && *perso2 != NON_SELECTIONNE) fin_choix_persos(continuer, &continuer_choix_persos);

        if(*continuer == QUITTER) continuer_choix_persos = 0;
    }

    liberer_surfaces_choix_persos(&selection1, &selection2, cases, portraits);

}
