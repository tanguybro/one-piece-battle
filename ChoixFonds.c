/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier du choix du fond
**/


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Constantes.h"
#include "Evenements.h"
#include "ChoixFonds.h"
#include "FonctionsMenu.h"

void choixFonds(SDL_Surface* ecran, int *continuer, char touche[], SDL_Surface *fond, SDL_Rect pos0, int *num_fond_combat)
{
    SDL_Surface *selection = NULL;
    SDL_Surface *cases[5][5] = {{NULL}}, *apercu[5][5] = {{NULL}};
    memset(cases,0,sizeof(cases));
    SDL_Rect posApercu, posCases[5][5], posSelection[5][5];
    int continuer_choix_fonds = 1;
    int ligne = 0, colonne = 0;

    *num_fond_combat = NON_SELECTIONNE;

    initialisation_pos_choix_fond(&posApercu, posCases);
    charger_images_choix_fond(&fond, cases, apercu);
    creation_selection_choix_fond(ecran, &selection);

    while(continuer_choix_fonds)
    {
        evenement(touche, continuer);

        if(touche[SDLK_ESCAPE])
        {
            touche[SDLK_ESCAPE]=0;
            continuer_choix_fonds = 0;
            *continuer = CHOIX_PERSOS;
        }

        selectionner_fond(num_fond_combat, &ligne, &colonne, touche);
        pos_selection_fond(ligne, colonne, posSelection, posCases);
        affichage_choix_fond(ecran, fond, selection, cases, apercu, pos0, posSelection, posCases, posApercu, num_fond_combat, ligne, colonne, continuer);

        if(*num_fond_combat != NON_SELECTIONNE) fin_choix_fond(continuer, &continuer_choix_fonds);

        if(*continuer == QUITTER) continuer_choix_fonds = 0;
    }

    liberer_surfaces_choix_fonds(&selection, cases, apercu);
}
