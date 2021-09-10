/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier des attaques spéciales
**/


#include <SDL.h>
#include <math.h>
#include "Constantes.h"
#include "Combat2.h"
#include "Personnages.h"
#include "AttaquesSpeciales.h"


void attaque_speciale(int *touche_spe, int coteJ, SDL_Rect *posJ, SDL_Rect *posEnnemi, int *special, Personnage *J, Personnage *Ennemi, SDL_Rect *posBarrePV_Ennemi, SDL_Rect *posBarreEnergie, int *ecart_position, int tempsActuel, int *tempsDebutSpe)
{
    if(*tempsDebutSpe == 0) // Modifier position au debut
    {
        if(coteJ == GAUCHE)
        {
            posJ->x -= (J->special2[*special]->w) - (J->normal->w);
            *ecart_position += (J->special2[*special]->w) - (J->normal->w);
        }
        *tempsDebutSpe = SDL_GetTicks();
    }

    if(coteJ == DROITE)
    {
        J->actuel = J->special[*special];
        if(tempsActuel - *tempsDebutSpe > DUREE_SPE) // Changement d'image
        {
            (*special)++;
            *tempsDebutSpe = SDL_GetTicks();
        }
        if(*special == J->nombreImagesSpe && posEnnemi->x > posJ->x && posEnnemi->x < posJ->x + J->actuel->w )  // Dégâts
        {
            if(Ennemi->actuel != Ennemi->defense && Ennemi->actuel != Ennemi->defense2)
            {
                if(posBarrePV_Ennemi->x == 1395-2*(Ennemi->pv) ) posBarrePV_Ennemi->x += (2*J->spe);
                Ennemi->pv -= J->spe;
            }
            else
            {
                if(posBarrePV_Ennemi->x == 1395-2*(Ennemi->pv) ) posBarrePV_Ennemi->x += 2*round(J->spe/2);
                Ennemi->pv -= round(J->spe/2);
            }
        }
    }

    if(coteJ == GAUCHE)
    {
        if(tempsActuel - *tempsDebutSpe > DUREE_SPE) // Changement d'image
        {
            (*special)++;
            *tempsDebutSpe = SDL_GetTicks();
            if(*special != J->nombreImagesSpe) // Modifier position
            {
                posJ->x -= (J->special2[*special]->w) - (J->special2[*special-1]->w);
                *ecart_position += (J->special2[*special]->w) - (J->special2[*special-1]->w);
            }
        }
        if(*special != J->nombreImagesSpe) J->actuel = J->special2[*special];
        else J->actuel = J->special2[*special-1];
        if(*special == J->nombreImagesSpe &&  posJ->x + J->actuel->w > posEnnemi->x + Ennemi->actuel->w && posJ->x < posEnnemi->x + Ennemi->actuel->w ) // Dégâts
        {
            if(Ennemi->actuel != Ennemi->defense && Ennemi->actuel != Ennemi->defense2)
            {
                if(posBarrePV_Ennemi->x == 1395-2*(Ennemi->pv) ) posBarrePV_Ennemi->x += (2*J->spe);
                Ennemi->pv -= J->spe;
            }
            else
            {
                if(posBarrePV_Ennemi->x == 1395-2*(Ennemi->pv) ) posBarrePV_Ennemi->x += 2*round(J->spe/2);
                Ennemi->pv -= round(J->spe/2);
            }
        }
    }

    if(*special == J->nombreImagesSpe) // Fin spé
    {
        if(coteJ == DROITE) J->actuel = J->normal;
        if(coteJ == GAUCHE) J->actuel = J->normal2;
        *special =0 ;
        *tempsDebutSpe = 0;
        posJ->x += *ecart_position;
        *ecart_position = 0;
        *touche_spe = 0;
        if(posBarreEnergie->x == 1395-(J->energie) ) posBarreEnergie->x += COUT_SPE;
        J->energie -= COUT_SPE;
    }
}
