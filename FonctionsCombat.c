/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier des fonctions de combat
**/


#include <SDL.h>
#include <SDL_image.h>
#include "Constantes.h"
#include "FonctionsCombat.h"
#include "Combat2.h"
#include "Personnages.h"




/******************************** Initialisation ********************************/




void creation_fond(int num_fond_combat, Fond fondCombat[])
{
    char chemin[100] = {0};

    sprintf(chemin,"Fonds/Fond%d.bmp",(num_fond_combat+1));
    fondCombat[num_fond_combat].image = IMG_Load(chemin);

    if(num_fond_combat < 14) fondCombat[num_fond_combat].difpos = 20;
    if(num_fond_combat >= 14 && num_fond_combat < 21) fondCombat[num_fond_combat].difpos = 5;
    if(num_fond_combat == 21) fondCombat[num_fond_combat].difpos = 40;
    if(num_fond_combat >= 22) fondCombat[num_fond_combat].difpos = 60;
}


void initialisation_pos_combat(SDL_Rect *pos0, SDL_Rect *posJ1, SDL_Rect *posJ2, SDL_Rect *posNom1, SDL_Rect *posNom2, SDL_Rect *posBarrePV1, SDL_Rect *posBarrePV2, SDL_Rect *posBarreEnergie1, SDL_Rect *posBarreEnergie2, const Personnage *J1, const Personnage *J2, const SDL_Surface *nom2, int num_fond_combat, const Fond fondCombat[])
{
    pos0->x = 0, pos0->y = 0;
    posJ1->x = 0, posJ1->y = (HAUTEUR_FENETRE - fondCombat[num_fond_combat].difpos) - (J1->normal->h);
    posJ2->x = LARGEUR_FENETRE - (J2->normal->w), posJ2->y = (HAUTEUR_FENETRE - fondCombat[num_fond_combat].difpos) - (J2->normal->h);
    posNom1->x = 5, posNom1->y = 0;
    posNom2->x = (LARGEUR_FENETRE -5) - (nom2->w), posNom2-> y =0;
    posBarrePV1->x = 5, posBarrePV1->y = 50;
    posBarrePV2->x = (LARGEUR_FENETRE - 5) - 2*(J2->pv), posBarrePV2->y = 50;
    posBarreEnergie1->x = 5, posBarreEnergie1->y = 90;
    posBarreEnergie2->x = (LARGEUR_FENETRE - 5) - ENERGIE_MAX, posBarreEnergie2->y = 90;
}


void transparence_persos(Personnage *J)
{
    int i=0;

    SDL_SetColorKey(J->mort, SDL_SRCCOLORKEY, SDL_MapRGB(J->normal->format, 255, 0, 0));
    SDL_SetColorKey(J->mort2, SDL_SRCCOLORKEY, SDL_MapRGB(J->normal->format, 255, 0, 0));
    SDL_SetColorKey(J->normal, SDL_SRCCOLORKEY, SDL_MapRGB(J->normal->format, 255, 0, 0));
    SDL_SetColorKey(J->normal2, SDL_SRCCOLORKEY, SDL_MapRGB(J->normal2->format, 255, 0, 0));
    SDL_SetColorKey(J->deplacement, SDL_SRCCOLORKEY, SDL_MapRGB(J->deplacement->format, 255, 0, 0));
    SDL_SetColorKey(J->deplacement2, SDL_SRCCOLORKEY, SDL_MapRGB(J->deplacement2->format, 255, 0, 0));
    SDL_SetColorKey(J->attaque, SDL_SRCCOLORKEY, SDL_MapRGB(J->attaque->format, 255, 0, 0));
    SDL_SetColorKey(J->attaque2, SDL_SRCCOLORKEY, SDL_MapRGB(J->attaque2->format, 255, 0, 0));
    SDL_SetColorKey(J->defense, SDL_SRCCOLORKEY, SDL_MapRGB(J->defense->format, 255, 0, 0));
    SDL_SetColorKey(J->defense2, SDL_SRCCOLORKEY, SDL_MapRGB(J->defense2->format, 255, 0, 0));
    for(i=0;i<10;i++)
    {
        if(J->special[i] != NULL)
        {
            SDL_SetColorKey(J->special[i], SDL_SRCCOLORKEY, SDL_MapRGB(J->special[i]->format, 255, 0, 0));
            SDL_SetColorKey(J->special2[i], SDL_SRCCOLORKEY, SDL_MapRGB(J->special2[i]->format, 255, 0, 0));
        }
    }
}




/******************************** Actions ********************************/




void deplacement(int touche_droite, int touche_gauche, int *cote, SDL_Rect *posJ, Personnage *J)
{
    int i=0;

    if(touche_droite)
    {
        J->actuel = J->deplacement;
        for(i=0; i < J->vitesse; i++) if(posJ->x < (LARGEUR_FENETRE - J->actuel->w) ) posJ->x++;
        *cote = DROITE;
    }

    if(touche_gauche)
    {
        J->actuel = J->deplacement2;
        for(i=0; i < J->vitesse; i++) if(posJ->x > 0) posJ->x--;
        *cote = GAUCHE;
    }
}


void saut(double *compteur_saut, int *touche_saut, SDL_Rect *posJ, const Personnage *J, int num_fond_combat, const Fond fondCombat[])
{
    int i=0;

    if(*compteur_saut < J->saut) // Montée
    {
        posJ->y-=10;
        (*compteur_saut)+=0.3;
    }

    if(*compteur_saut >= J->saut) // Descente
    {
        posJ->y+=10;
        if(posJ->y >= (HAUTEUR_FENETRE - fondCombat[num_fond_combat].difpos) -(J->actuel->h)) *compteur_saut=0;
    }

    if(*compteur_saut == 0)
    {
        posJ->y = (HAUTEUR_FENETRE - fondCombat[num_fond_combat].difpos)-(J->actuel->h);
        *touche_saut = 0;
    }
}


void defense(int cote, int *tempsDebutDef, SDL_Rect *posJ, Personnage *J)
{
    *tempsDebutDef = SDL_GetTicks();

    if(cote == DROITE) J->actuel = J->defense;
    if(cote == GAUCHE)
    {
        J->actuel = J->defense2;
        posJ->x += (J->normal->w) - (J->defense->w);
    }
}


void fin_defense(int tempsActuel, int tempsDebutDef, int coteJ, Personnage *J, SDL_Rect *posJ)
{
    if(tempsActuel - tempsDebutDef > DUREE_DEF)
    {
        if(coteJ == DROITE) J->actuel = J->normal;
        if(coteJ == GAUCHE)
        {
            posJ->x -= (J->normal->w) - (J->defense->w);
            J->actuel = J->normal2;
        }
    }
}


void attaque(int cote, int *tempsDebutAtk, SDL_Rect *posBarrePV, SDL_Rect *posJ, const SDL_Rect *posEnnemi, Personnage *J, Personnage *Ennemi, int *reculAtk)
{
    *tempsDebutAtk = SDL_GetTicks();

    if(cote == DROITE)
    {
        J->actuel = J->attaque;
        if(posEnnemi->x > posJ->x && posJ->x + (J->actuel->w) >= posEnnemi->x
        && posEnnemi->y + Ennemi->actuel->h > posJ->y + (J->actuel->h)/2)
        {
            if(Ennemi->actuel != Ennemi->defense && Ennemi->actuel != Ennemi->defense2)
            {
                if(posBarrePV->x == (LARGEUR_FENETRE - 5) - 2 * Ennemi->pv) posBarrePV->x += (2*J->atk); // Si J2 changer position barre PV
                Ennemi->pv -= J->atk;
            }
            else *reculAtk = 1;
        }
    }

    if(cote == GAUCHE)
    {
        J->actuel = J->attaque2;
        posJ->x += (J->normal->w) - (J->attaque->w);
        if(posJ->x + J->actuel->w > posEnnemi->x + Ennemi->actuel->w && posJ->x < posEnnemi->x + Ennemi->actuel->w
        && posEnnemi->y + Ennemi->actuel->h > posJ->y + (J->actuel->h)/2)
        {
            if(Ennemi->actuel != Ennemi->defense && Ennemi->actuel != Ennemi->defense2)
            {
                if(posBarrePV->x == (LARGEUR_FENETRE - 5) - 2 * Ennemi->pv) posBarrePV->x += (2*J->atk); // Si J2 changer position barre PV
                Ennemi->pv -= J->atk;
            }
            else *reculAtk = 1;
        }
    }
}


void fin_attaque(int tempsActuel, int tempsDebutAtk, int *reculAtk, int coteJ, Personnage *J, SDL_Rect *posJ)
{
    if(tempsActuel - tempsDebutAtk > DUREE_ATK)
    {
        if(coteJ == DROITE)
        {
            J->actuel = J->normal;
            if(*reculAtk) posJ->x -= 200;
        }
        if(coteJ == GAUCHE)
        {
            posJ->x -= (J->normal->w) - (J->attaque->w);
            J->actuel = J->normal2;
            if(*reculAtk) posJ->x += 200;
        }

        *reculAtk = 0;
    }
}




/******************************** Reste ********************************/




void test_touche(char touche[], int *continuer, int *continuer_combat, int *espace, int *q, int *d, int *z, int *s, int *a, int *entree, int *fleche_droite, int *fleche_gauche, int *fleche_haut, int *fleche_bas, int *shift_droit)
{
    if(touche[SDLK_ESCAPE])
    {
        touche[SDLK_ESCAPE]=0;
        *continuer_combat = 0;
        *continuer = CHOIX_PERSOS;
    }
    if(touche[SDLK_a]) *q = 1;
    if(touche[SDLK_d]) *d = 1;
    if(touche[SDLK_w])
    {
        touche[SDLK_w] = 0;
        *z = 1;
    }
    if(touche[SDLK_s])
    {
        touche[SDLK_s] = 0;
        *s = 1;
    }
    if(touche[SDLK_SPACE])
    {
        touche[SDLK_SPACE] = 0;
        *espace= 1;
    }
    if(touche[SDLK_q])
    {
        touche[SDLK_q] = 0;
        *a = 1;
    }
    if(touche[SDLK_LEFT]) *fleche_gauche = 1;
    if(touche[SDLK_RIGHT]) *fleche_droite = 1;
    if(touche[SDLK_UP])
    {
        touche[SDLK_UP] = 0;
        *fleche_haut = 1;
    }
    if(touche[SDLK_DOWN])
    {
        touche[SDLK_DOWN] = 0;
        *fleche_bas = 1;
    }
    if(touche[SDLK_RETURN])
    {
        touche[SDLK_RETURN] = 0;
        *entree = 1;
    }
    if(touche[SDLK_RSHIFT])
    {
        touche[SDLK_RSHIFT]=0;
        *shift_droit = 1;
    }
}


void remettre_perso_normal(Personnage *J)
{
    if(J->actuel == J->deplacement) J->actuel = J->normal;
    if(J->actuel == J->deplacement2) J->actuel = J->normal2;
}


SDL_Surface* barrePV(SDL_Surface *ecran, SDL_Surface *barrePV, Personnage *J)
{
    if(J->pv < 0) J->pv = 0;

    barrePV = SDL_CreateRGBSurface(SDL_HWSURFACE, 2*(J->pv), 30, 32, 0, 0, 0, 0);
    SDL_FillRect(barrePV, NULL, SDL_MapRGB(ecran->format, 0, 255, 0));

    return barrePV;
}


SDL_Surface* barreEnergie(SDL_Surface *ecran, SDL_Surface *barreEnergie, Personnage *J, SDL_Rect *posBarreEnergie, int decalerBarre)
{
    if(J->energie < 300 && (J->actuel == J->normal || J->actuel == J->normal2 || J->actuel == J->deplacement || J->actuel == J->deplacement2) )
    {
        (J->energie)++;
        if(decalerBarre) posBarreEnergie->x--;
    }

    barreEnergie = SDL_CreateRGBSurface(SDL_HWSURFACE, J->energie, 15, 32, 0, 0, 0, 0);
    SDL_FillRect(barreEnergie, NULL, SDL_MapRGB(ecran->format, 0, 0, 255));

    return barreEnergie;
}


void posVertical(SDL_Rect *posJ, const Personnage *J, int num_fond_combat, const Fond fondCombat[])
{
    posJ->y = HAUTEUR_FENETRE - fondCombat[num_fond_combat].difpos - (J->actuel->h);
}


void touches_zero(int *q, int *d, int *s, int *espace, int *fleche_gauche, int *fleche_droite, int *fleche_bas, int *entree)
{
    *q=0;
    *d=0;
    *s=0;
    *espace=0;
    *fleche_gauche=0;
    *fleche_droite=0;
    *fleche_bas=0;
    *entree=0;
}


int mort(int coteJ, Personnage *J, SDL_Rect *posJ)
{
    if(J->pv ==0 && J->actuel != J->mort && J->actuel != J->mort2)
    {
        if(coteJ == DROITE)
        {
            posJ->y += (J->normal->h) - (J->mort->h);
            J->actuel = J->mort;
        }
        if(coteJ == GAUCHE)
        {
            posJ->y += (J->normal->h) - (J->mort->h);
            J->actuel = J->mort2;
        }

        return 1;
    }

    return 0;
}


void fin_combat(int *continuer, int *continuer_combat2)
{
        *continuer_combat2 = 0;
        *continuer = MENU;
        SDL_Delay(DUREE_FIN_COMBAT);
}


void liberer_surfaces_combat(SDL_Surface **fond, SDL_Surface **nom1, SDL_Surface **nom2, SDL_Surface **barrePV1, SDL_Surface **barrePV2, SDL_Surface **barreEnergie1, SDL_Surface **barreEnergie2, Personnage *J1, Personnage *J2)
{
    int i = 0;

    SDL_FreeSurface(*fond);
    SDL_FreeSurface(*nom1);
    SDL_FreeSurface(*nom2);
    SDL_FreeSurface(*barrePV1);
    SDL_FreeSurface(*barrePV2);
    SDL_FreeSurface(*barreEnergie1);
    SDL_FreeSurface(*barreEnergie2);

    SDL_FreeSurface(J1->mort);
    SDL_FreeSurface(J1->mort2);
    SDL_FreeSurface(J1->normal);
    SDL_FreeSurface(J1->normal2);
    SDL_FreeSurface(J1->deplacement);
    SDL_FreeSurface(J1->deplacement2);
    SDL_FreeSurface(J1->attaque);
    SDL_FreeSurface(J1->attaque2);
    SDL_FreeSurface(J1->defense);
    SDL_FreeSurface(J1->defense2);
    SDL_FreeSurface(J1->actuel);
    for(i = 0; i < J1->nombreImagesSpe; i++)
    {
        SDL_FreeSurface(J1->special[i]);
        SDL_FreeSurface(J1->special2[i]);
    }

    SDL_FreeSurface(J2->mort);
    SDL_FreeSurface(J2->mort2);
    SDL_FreeSurface(J2->normal);
    SDL_FreeSurface(J2->normal2);
    SDL_FreeSurface(J2->deplacement);
    SDL_FreeSurface(J2->deplacement2);
    SDL_FreeSurface(J2->attaque);
    SDL_FreeSurface(J2->attaque2);
    SDL_FreeSurface(J2->defense);
    SDL_FreeSurface(J2->defense2);
    SDL_FreeSurface(J2->actuel);
    for(i = 0; i < J2->nombreImagesSpe; i++)
    {
        SDL_FreeSurface(J2->special[i]);
        SDL_FreeSurface(J2->special2[i]);
    }
}
