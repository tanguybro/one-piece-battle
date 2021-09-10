/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier du combat libre 2 joueurs
**/


#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Combat2.h"
#include "Evenements.h"
#include "Constantes.h"
#include "Personnages.h"
#include "AttaquesSpeciales.h"
#include "FonctionsCombat.h"
#include "FonctionsMenu.h"

void combat2(SDL_Surface* ecran, int *continuer, char touche[], int *perso1, int *perso2, int num_fond_combat)
{
    SDL_Surface *nom1=NULL, *nom2=NULL, *barrePV1=NULL, *barrePV2=NULL, *barreEnergie1=NULL, *barreEnergie2=NULL;
    SDL_Rect pos0, posJ1, posJ2, posNom1, posNom2, posBarrePV1, posBarrePV2, posBarreEnergie1, posBarreEnergie2;
    int continuer_combat2 = 1, finCombat = 0;
    int coteJ1 = DROITE, coteJ2 = GAUCHE;
    int espace = 0, q = 0, d = 0, z = 0, s = 0, a = 0;
    int entree = 0, fleche_droite = 0, fleche_gauche = 0, fleche_haut = 0, fleche_bas = 0, shift_droit =  0;
    double compteur_saut1 = 0, compteur_saut2 = 0;
    int ecart_position1 = 0, ecart_position2 = 0, reculAtk = 0;
    int tempsActuel = 0, tempsDebutAtk1 = 0, tempsDebutAtk2 = 0, tempsDebutDef1 = 0, tempsDebutDef2 = 0, tempsDebutSpe1 = 0, tempsDebutSpe2 = 0;
    int special1 = 0, special2 = 0;
    Fond fondCombat[NOMBRE_FONDS];
    Personnage J1 = {0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Personnage J2 = {0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    /** Initialisation **/

    J1 = Personnages(perso1, &nom1, &J1);
    J2 = Personnages(perso2, &nom2, &J2);

    J1.actuel = J1.normal;
    J2.actuel = J2.normal2;

    creation_fond(num_fond_combat, fondCombat);
    initialisation_pos_combat(&pos0, &posJ1, &posJ2, &posNom1, &posNom2, &posBarrePV1, &posBarrePV2, &posBarreEnergie1, &posBarreEnergie2, &J1, &J2, nom2, num_fond_combat, fondCombat);
    transparence_persos(&J1);
    transparence_persos(&J2);

    while(continuer_combat2)
    {
        evenement(touche, continuer);
        test_touche(touche, continuer, &continuer_combat2, &espace, &q, &d, &z, &s, &a, &entree, &fleche_droite, &fleche_gauche, &fleche_haut, &fleche_bas, &shift_droit);
        remettre_perso_normal(&J1);
        remettre_perso_normal(&J2);

        /** Actions **/

        if(J1.actuel == J1.normal || J1.actuel == J1.normal2) deplacement(d, q, &coteJ1, &posJ1, &J1);
        if(J2.actuel == J2.normal || J2.actuel == J2.normal2) deplacement(fleche_droite, fleche_gauche, &coteJ2, &posJ2, &J2);

        if(z && (J1.actuel == J1.normal || J1.actuel == J1.normal2 || J1.actuel == J1.deplacement || J1.actuel == J1.deplacement2) ) saut(&compteur_saut1, &z, &posJ1, &J1, num_fond_combat, fondCombat);
        if(fleche_haut && (J2.actuel == J2.normal || J2.actuel == J2.normal2 || J2.actuel == J2.deplacement || J2.actuel == J2.deplacement2) ) saut(&compteur_saut2, &fleche_haut, &posJ2, &J2, num_fond_combat, fondCombat);

        tempsActuel = SDL_GetTicks();
        if(s && (tempsActuel - tempsDebutDef1 > FREQUENCE_DEF)) defense(coteJ1, &tempsDebutDef1, &posJ1, &J1);
        if(fleche_bas && (tempsActuel - tempsDebutDef2 > FREQUENCE_DEF)) defense(coteJ2, &tempsDebutDef2, &posJ2, &J2);
        if(J1.actuel == J1.defense || J1.actuel == J1.defense2) fin_defense(tempsActuel, tempsDebutDef1, coteJ1, &J1, &posJ1);
        if(J2.actuel == J2.defense || J2.actuel == J2.defense2) fin_defense(tempsActuel, tempsDebutDef2, coteJ2, &J2, &posJ2);

        tempsActuel = SDL_GetTicks();
        if(espace && compteur_saut1 == 0 && (tempsActuel - tempsDebutAtk1 > FREQUENCE_ATK) ) attaque(coteJ1, &tempsDebutAtk1, &posBarrePV2, &posJ1, &posJ2, &J1, &J2, &reculAtk);
        if(entree && compteur_saut2 == 0 && (tempsActuel - tempsDebutAtk2 > FREQUENCE_ATK)) attaque(coteJ2, &tempsDebutAtk2, &posBarrePV1, &posJ2, &posJ1, &J2, &J1, &reculAtk);
        if(J1.actuel == J1.attaque || J1.actuel == J1.attaque2) fin_attaque(tempsActuel, tempsDebutAtk1, &reculAtk, coteJ1, &J1, &posJ1);
        if(J2.actuel == J2.attaque || J2.actuel == J2.attaque2) fin_attaque(tempsActuel, tempsDebutAtk2, &reculAtk, coteJ2, &J2, &posJ2);

        tempsActuel = SDL_GetTicks();
        if(a && J1.energie > COUT_SPE && compteur_saut1 == 0) attaque_speciale(&a, coteJ1, &posJ1, &posJ2, &special1, &J1, &J2, &posBarrePV2, &posBarreEnergie1, &ecart_position1, tempsActuel, &tempsDebutSpe1);
        if(shift_droit && J2.energie > COUT_SPE && compteur_saut2 == 0) attaque_speciale(&shift_droit, coteJ2, &posJ2, &posJ1, &special2, &J2, &J1, &posBarrePV1, &posBarreEnergie2, &ecart_position2, tempsActuel, &tempsDebutSpe2);

        /** Reste **/

        if(compteur_saut1 == 0) posVertical(&posJ1, &J1, num_fond_combat, fondCombat);
        if(compteur_saut2 == 0) posVertical(&posJ2, &J2, num_fond_combat, fondCombat);

        barrePV1 = barrePV(ecran, barrePV1, &J1);
        barrePV2 = barrePV(ecran, barrePV2, &J2);
        barreEnergie1 = barreEnergie(ecran, barreEnergie1, &J1, &posBarreEnergie1, 0);
        barreEnergie2 = barreEnergie(ecran, barreEnergie2, &J2, &posBarreEnergie2, 1);

        touches_zero(&q, &d, &s, &espace, &fleche_gauche, &fleche_droite, &fleche_bas, &entree);

        if(mort(coteJ1, &J1, &posJ1) || mort(coteJ2, &J2, &posJ2) ) finCombat = 1;

        afficher_surfaces(ecran, fondCombat[num_fond_combat].image, pos0, J1.actuel, posJ1, J2.actuel, posJ2, barrePV1, posBarrePV1, barrePV2, posBarrePV2, barreEnergie1, posBarreEnergie1, barreEnergie2, posBarreEnergie2, nom1, posNom1, nom2, posNom2, NULL, pos0);
        SDL_Flip(ecran);

        if(finCombat) fin_combat(continuer, &continuer_combat2);

        if(*continuer == QUITTER) continuer_combat2 = 0;
    }

    liberer_surfaces_combat(&fondCombat[num_fond_combat].image, &nom1, &nom2, &barrePV1, &barrePV2, &barreEnergie1, &barreEnergie2, &J1, &J2);
}
