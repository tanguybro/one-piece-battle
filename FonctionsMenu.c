/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier des fonctions de combat
**/


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Constantes.h"
#include "FonctionsMenu.h"


void afficher_surfaces(SDL_Surface *ecran, SDL_Surface *surf1, SDL_Rect pos1, SDL_Surface *surf2, SDL_Rect pos2, SDL_Surface *surf3, SDL_Rect pos3, SDL_Surface *surf4, SDL_Rect pos4, SDL_Surface *surf5, SDL_Rect pos5, SDL_Surface *surf6, SDL_Rect pos6, SDL_Surface *surf7, SDL_Rect pos7, SDL_Surface *surf8, SDL_Rect pos8, SDL_Surface *surf9, SDL_Rect pos9, SDL_Surface *surf10, SDL_Rect pos10)
{
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_BlitSurface(surf1, NULL, ecran, &pos1);
    SDL_BlitSurface(surf2, NULL, ecran, &pos2);
    SDL_BlitSurface(surf3, NULL, ecran, &pos3);
    SDL_BlitSurface(surf4, NULL, ecran, &pos4);
    SDL_BlitSurface(surf5, NULL, ecran, &pos5);
    SDL_BlitSurface(surf6, NULL, ecran, &pos6);
    SDL_BlitSurface(surf7, NULL, ecran, &pos7);
    SDL_BlitSurface(surf8, NULL, ecran, &pos8);
    SDL_BlitSurface(surf9, NULL, ecran, &pos9);
    SDL_BlitSurface(surf10, NULL, ecran, &pos10);
}




/******************************** Menu ********************************/




void initialisation(SDL_Surface **ecran)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_WM_SetIcon(IMG_Load("Icone.jpg"), NULL);
    SDL_WM_SetCaption("One Piece Battle", NULL);
    *ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
}


void images_menu(SDL_Surface **fond, SDL_Surface **selection1, SDL_Surface **selection2)
{
    *fond = IMG_Load("Menu/Menu.bmp");
    *selection1 = IMG_Load("Menu/Selection.bmp");
    *selection2 = *selection1;
    SDL_SetColorKey(*selection1, SDL_SRCCOLORKEY, SDL_MapRGB((*selection1)->format, 255, 0, 0));
}


int selectionner(int *selection, char touche[])
{
     if(touche[SDLK_UP] || touche[SDLK_w])
     {
         touche[SDLK_UP] = 0;
         touche[SDLK_w] = 0;
         *selection -= 1;
         if(*selection <= 0) *selection = 2;
     }

     if(touche[SDLK_DOWN] || touche[SDLK_s])
     {
         touche[SDLK_DOWN] = 0;
         touche[SDLK_s] = 0;
         *selection += 1;
         if(*selection >= 3) *selection = 1;
     }

     if(touche[SDLK_SPACE] || touche[SDLK_RETURN])
     {
         touche[SDLK_SPACE] = 0;
         touche[SDLK_RETURN] = 0;
         return *selection;
     }

     return 0;
}


void posSelection(int selection, SDL_Rect *posSelection1, SDL_Rect *posSelection2)
{
        if(selection == 1)
        {
            posSelection1->x=400, posSelection1->y=300;
            posSelection2->x=935, posSelection2->y=300;
        }

        if(selection == 2)
        {
            posSelection1->x=360, posSelection1->y=440;
            posSelection2->x=990, posSelection2->y=440;
        }
}


void liberer_surfaces_menu(SDL_Surface **surf1, SDL_Surface **surf2, SDL_Surface **surf3, SDL_Surface **surf4)
{
    SDL_FreeSurface(*surf1);
    SDL_FreeSurface(*surf2);
    SDL_FreeSurface(*surf3);
    SDL_FreeSurface(*surf4);
}



/******************************** Choix persos ********************************/




void initialisation_pos_choix_persos(SDL_Rect *posPortrait1, SDL_Rect *posPortrait2, SDL_Rect posCases[10][8])
{
    int i = 0, j = 0, ecartX = 9, ecartY = 183;

    posPortrait1->x=350, posPortrait1->y=300;
    posPortrait2->x=740, posPortrait2->y=300;
    for(i=0;i<10;i++)
    {
        for(j=0;j<4;j++)
        {
            posCases[i][j].x = ecartX;
            posCases[i][j].y = ecartY;
            ecartX += 85;
            if(j == 3)
            {
                ecartX = 9;
                ecartY += 45;
            }
        }
    }
    ecartX = 1053;
    ecartY = 181;
    for(i=0;i<10;i++)
    {
        for(j=4;j<8;j++)
        {
            posCases[i][j].x = ecartX;
            posCases[i][j].y = ecartY;
            ecartX += 85;
            if(j == 7)
            {
                ecartX = 1053;
                ecartY += 45;
            }
        }
    }
}


void charger_images_choix_persos(SDL_Surface **fond, SDL_Surface *cases[10][8], SDL_Surface *portraits[10][8])
{
    int longueur_chaine = 0, i = 0, j = 0;
    char perso[50]={0}, chemin[50]={0};
    FILE* fichier = NULL;

    *fond = IMG_Load("Menu/Choix persos.bmp");

    fichier = fopen("Persos.txt", "r");
    while (!feof(fichier))
    {
        fgets(perso, 50, fichier);
        longueur_chaine = strlen(perso);
        perso[longueur_chaine-1]='\0';
        sprintf(chemin,"Personnages/Miniatures/%s.bmp",perso);
        cases[i][j] = IMG_Load(chemin);
        cases[i][j+4] = IMG_Load(chemin);
        sprintf(chemin,"Personnages/Portraits/%s.png",perso);
        portraits[i][j] = IMG_Load(chemin);
        portraits[i][j+4] = IMG_Load(chemin);
        SDL_SetColorKey(portraits[i][j], SDL_SRCCOLORKEY, SDL_MapRGB(portraits[i][j]->format, 255, 0, 0));
        j++;
        if(j==4)
        {
            i++;
            j=0;
        }
    }

    fclose(fichier);
}


void selectionner_perso1(int *perso1, int *ligne1, int *colonne1, int ligne2, int colonne2, char touche[])
{
        if(touche[SDLK_a])
        {
            (*colonne1)--;
            if(*colonne1 == colonne2 && *ligne1 == ligne2) (*colonne1)--;
            if(*colonne1 < 0) *colonne1 = 3;
            SDL_Delay(200);
        }

        if(touche[SDLK_d])
        {
            (*colonne1)++;
            if(*colonne1 == colonne2 && *ligne1 == ligne2) (*colonne1)++;
            if(*colonne1 > 3) *colonne1 = 0;
            SDL_Delay(200);
        }

        if(touche[SDLK_w])
        {
            (*ligne1)--;
            if(*colonne1 == colonne2 && *ligne1 == ligne2) (*ligne1)--;
            if(*ligne1 < 0) *ligne1 = 9;
            SDL_Delay(200);
        }

        if(touche[SDLK_s])
        {
            (*ligne1)++;
            if(*colonne1 == colonne2 && *ligne1 == ligne2) (*ligne1)++;
            if(*ligne1 > 9) *ligne1 = 0;
            SDL_Delay(200);
        }

        if(touche[SDLK_SPACE] && (*colonne1 + 4 * (*ligne1)  <= NOMBRE_PERSOS) )
        {
            touche[SDLK_SPACE] = 0;
            *perso1 = *colonne1 + 4 * (*ligne1);
        }
}


void selectionner_perso2(int *perso2, int *ligne2, int *colonne2, int ligne1, int colonne1, char touche[])
{
        if(touche[SDLK_UP])
        {
            (*ligne2)--;
            if(colonne1 == *colonne2 && ligne1 == *ligne2) (*ligne2)--;
            if(*ligne2 < 0) *ligne2 = 9;
            SDL_Delay(200);
        }

        if(touche[SDLK_DOWN])
        {
            (*ligne2)++;
            if(colonne1 == *colonne2 && ligne1 == *ligne2) (*ligne2)++;
            if(*ligne2 > 9) *ligne2 = 0;
            SDL_Delay(200);
        }

        if(touche[SDLK_LEFT])
        {
            (*colonne2)--;
            if(colonne1 == *colonne2 && ligne1 == *ligne2) (*colonne2)--;
            if(*colonne2 < 4) *colonne2 = 7;
            SDL_Delay(200);
        }

        if(touche[SDLK_RIGHT])
        {
            (*colonne2)++;
            if(colonne1 == *colonne2 && ligne1 == *ligne2) (*colonne2)++;
            if(*colonne2 > 7) *colonne2 = 4;
            SDL_Delay(200);
        }

        if(touche[SDLK_RETURN] && ( (*colonne2 - 4) + 4 * (*ligne2)  <= NOMBRE_PERSOS) )
        {
            touche[SDLK_RETURN] = 0;
            *perso2 = (*colonne2 -  4) + 4 * (*ligne2);
        }
}


void creation_selection_choix_persos(SDL_Surface *ecran, SDL_Surface **selection1, SDL_Surface **selection2)
{
    *selection1 = SDL_CreateRGBSurface(SDL_HWSURFACE, 86, 46, 32, 0, 0, 0, 0);
    *selection2 = SDL_CreateRGBSurface(SDL_HWSURFACE, 86, 46, 32, 0, 0, 0, 0);
    SDL_FillRect(*selection1, NULL, SDL_MapRGB(ecran->format, 255, 0, 0));
    SDL_FillRect(*selection2, NULL, SDL_MapRGB(ecran->format, 0, 255, 255));
}


void pos_selection_persos(int ligne, int colonne, SDL_Rect posSelection[10][8], SDL_Rect posCases[10][8])
{
    posSelection[ligne][colonne].x = posCases[ligne][colonne].x -3;
    posSelection[ligne][colonne].y = posCases[ligne][colonne].y -3;
}


void affichage_choix_persos(SDL_Surface *ecran, SDL_Surface *fond, SDL_Surface *selection1, SDL_Surface *selection2, SDL_Surface *cases[10][8], SDL_Surface *portraits[10][8], SDL_Rect pos0, SDL_Rect posSelection[10][8], SDL_Rect posCases[10][8], SDL_Rect posPortrait1, SDL_Rect posPortrait2, const int *perso1, const int *perso2, int ligne1, int ligne2, int colonne1, int colonne2, const int *continuer)
{
    int i = 0, j = 0;

    afficher_surfaces(ecran, fond, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0);
    if(*perso1 == NON_SELECTIONNE) SDL_BlitSurface(selection1, NULL, ecran, &posSelection[ligne1][colonne1]);
    if(*perso2 == NON_SELECTIONNE) SDL_BlitSurface(selection2, NULL, ecran, &posSelection[ligne2][colonne2]);
    for(i=0;i<10;i++)
    {
        for(j=0;j<8;j++) SDL_BlitSurface(cases[i][j], NULL, ecran, &posCases[i][j]);
    }
    if(portraits[ligne1][colonne1] != NULL) SDL_BlitSurface(portraits[ligne1][colonne1], NULL, ecran, &posPortrait1);
    if(portraits[ligne2][colonne2] != NULL) SDL_BlitSurface(portraits[ligne2][colonne2], NULL, ecran, &posPortrait2);
    if(*continuer != QUITTER) SDL_Flip(ecran);
}


void fin_choix_persos(int *continuer, int *continuer_choix_persos)
{
    *continuer = CHOIX_FONDS;
    *continuer_choix_persos = 0;
}


void liberer_surfaces_choix_persos(SDL_Surface **selection1, SDL_Surface **selection2, SDL_Surface *cases[10][8], SDL_Surface *portraits[10][8])
{
    int i = 0, j = 0;
    SDL_FreeSurface(*selection1);
    SDL_FreeSurface(*selection2);
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 8; j++)
        {
            SDL_FreeSurface(cases[i][j]);
            SDL_FreeSurface(portraits[i][j]);
        }
    }
}




/******************************** Choix fonds ********************************/




void initialisation_pos_choix_fond(SDL_Rect *posApercu, SDL_Rect posCases[5][5])
{
    int i = 0;

    posApercu->x=37, posApercu->y=346;
    posCases[0][0].x=411, posCases[0][0].y=180;
    for(i=1;i<5;i++)
    {
        posCases[0][i].x = posCases[0][i-1].x + 180;
        posCases[0][i].y = posCases[0][i-1].y;
        posCases[i][0].x = posCases[i-1][0].x;
        posCases[i][0].y = posCases[i-1][0].y + 100;
        posCases[1][i].x = posCases[1][i-1].x + 180;
        posCases[1][i].y = posCases[1][i-1].y;
        posCases[i][1].x = posCases[i-1][1].x;
        posCases[i][1].y = posCases[i-1][1].y + 100;
        posCases[2][i].x = posCases[2][i-1].x + 180;
        posCases[2][i].y = posCases[2][i-1].y;
        posCases[i][2].x = posCases[i-1][2].x;
        posCases[i][2].y = posCases[i-1][2].y + 100;
        posCases[3][i].x = posCases[3][i-1].x + 180;
        posCases[3][i].y = posCases[3][i-1].y;
        posCases[i][3].x = posCases[i-1][3].x;
        posCases[i][3].y = posCases[i-1][3].y + 100;
        posCases[4][i].x = posCases[4][i-1].x + 180;
        posCases[4][i].y = posCases[4][i-1].y;
        posCases[i][4].x = posCases[i-1][4].x;
        posCases[i][4].y = posCases[i-1][4].y + 100;
    }
}


void charger_images_choix_fond(SDL_Surface **fond, SDL_Surface *cases[5][5], SDL_Surface *apercu[5][5])
{
    int i = 0, j = 0, numero_fond = 1;
    char chemin[100]={0};

    *fond = IMG_Load("Menu/Choix fonds.bmp");

    while (numero_fond <= NOMBRE_FONDS)
    {
        sprintf(chemin,"Fonds/Miniatures/Fond%d.bmp",numero_fond);
        cases[i][j] = IMG_Load(chemin);
        sprintf(chemin,"Fonds/Apercus/Fond%d.bmp",numero_fond);
        apercu[i][j] = IMG_Load(chemin);
        SDL_SetColorKey(apercu[i][j], SDL_SRCCOLORKEY, SDL_MapRGB(apercu[i][j]->format, 255, 0, 0));
        j++;
        numero_fond++;
        if(j==5)
        {
            i++;
            j=0;
        }
    }
}


void creation_selection_choix_fond(SDL_Surface *ecran, SDL_Surface **selection)
{
    *selection = SDL_CreateRGBSurface(SDL_HWSURFACE, 176, 96, 32, 0, 0, 0, 0);
    SDL_FillRect(*selection, NULL, SDL_MapRGB(ecran->format, 255, 0, 0));

}


void selectionner_fond(int *num_fond_combat, int *ligne, int *colonne, char touche[])
{
    if(touche[SDLK_a])
    {
        (*colonne)--;
        if(*colonne < 0) *colonne = 4;
        SDL_Delay(200);
    }

    if(touche[SDLK_d])
    {
        (*colonne)++;
        if(*colonne > 4) *colonne = 0;
        SDL_Delay(200);
    }

    if(touche[SDLK_w])
    {
        (*ligne)--;
        if(*ligne < 0) *ligne = 4;
        SDL_Delay(200);
    }

    if(touche[SDLK_s])
    {
        (*ligne)++;
        if(*ligne > 4) *ligne = 0;
        SDL_Delay(200);
    }

    if(touche[SDLK_SPACE] && (*colonne + 5 * (*ligne)  < NOMBRE_FONDS) )
    {
        touche[SDLK_SPACE] = 0;
        *num_fond_combat = *colonne + 5 * (*ligne) ;
    }

}


void pos_selection_fond(int ligne, int colonne, SDL_Rect posSelection[5][5], SDL_Rect posCases[5][5])
{
    posSelection[ligne][colonne].x = posCases[ligne][colonne].x -3;
    posSelection[ligne][colonne].y = posCases[ligne][colonne].y -3;
}


void affichage_choix_fond(SDL_Surface *ecran, SDL_Surface *fond, SDL_Surface *selection, SDL_Surface *cases[5][5], SDL_Surface *apercu[5][5], SDL_Rect pos0, SDL_Rect posSelection[5][5], SDL_Rect posCases[5][5], SDL_Rect posApercu, const int *fond_combat, int ligne, int colonne, const int *continuer)
{
    int i = 0, j = 0;

    afficher_surfaces(ecran, fond, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0, NULL, pos0);
    if(*fond_combat == NON_SELECTIONNE) SDL_BlitSurface(selection, NULL, ecran, &posSelection[ligne][colonne]);
    for(i=0;i<5;i++)
    {
     for(j=0;j<5;j++) SDL_BlitSurface(cases[i][j], NULL, ecran, &posCases[i][j]);
    }
    if(apercu[ligne][colonne] != NULL) SDL_BlitSurface(apercu[ligne][colonne], NULL, ecran, &posApercu);
    if(*continuer != QUITTER) SDL_Flip(ecran);
}


void fin_choix_fond(int *continuer, int *continuer_choix_fonds)
{
    *continuer = COMBAT2;
    *continuer_choix_fonds = 0;
}


void liberer_surfaces_choix_fonds(SDL_Surface **selection, SDL_Surface *cases[5][5], SDL_Surface *apercu[5][5])
{
    int i = 0, j = 0;
    SDL_FreeSurface(*selection);
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            SDL_FreeSurface(cases[i][j]);
            SDL_FreeSurface(apercu[i][j]);
        }
    }
}

