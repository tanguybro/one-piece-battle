/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier header de FonctionsCombat.c
**/


#ifndef FONCTIONSCOMBAT_H_INCLUDED
#define FONCTIONSCOMBAT_H_INCLUDED

#include "Personnages.h"
#include "Combat2.h"


/******************************** Initialisation ********************************/


/**
 * @brief Charger le fond
 * @param[in] num_fond_combat
 * @param[out] fondCombat[]
 */
void creation_fond(int num_fond_combat, Fond fondCombat[]);


/**
 * @brief Initialiser toutes les positions pour le combat
 * @param[in] J1
 * @param[in] J2
 * @param[in] num_fond_combat
 * @param[in] fondCombat[]
 * @param[in] nom2
 * @param[out] pos0
 * @param[out] posJ1
 * @param[out] posJ2
 * @param[out] posNom1
 * @param[out] posNom2
 * @param[out] posBarrePV1
 * @param[out] posBarrePV2
 * @param[out] posBarreEnergie1
 * @param[out] posBarreEnergie2
 */
void initialisation_pos_combat(SDL_Rect *pos0, SDL_Rect *posJ1, SDL_Rect *posJ2, SDL_Rect *posNom1, SDL_Rect *posNom2, SDL_Rect *posBarrePV1, SDL_Rect *posBarrePV2, SDL_Rect *posBarreEnergie1, SDL_Rect *posBarreEnergie2, const Personnage *J1, const Personnage *J2, const SDL_Surface *nom2, int num_fond_combat, const Fond fondCombat[]);


/**
 * @brief Rend les images des personnages transparentes
 * @param[out] J
 */
void transparence_persos(Personnage *J);


/******************************** Actions ********************************/


/**
 * @brief Deplacement d'un personnage
 * @param[in] touche_droite
 * @param[in] touche_gauche
 * @param[out] cote
 * @param[out] posJ
 * @param[out] J
 */
void deplacement(int touche_droite, int touche_gauche, int *cote, SDL_Rect *posJ, Personnage *J);


/**
 * @brief Saut d'un personnage
 * @param[in] J
 * @param[in] num_fond_combat
 * @param[in] fondCombat[]
 * @param[out] compteur_saut
 * @param[out] touche_saut
 * @param[out] posJ
 */
void saut(double *compteur_saut, int *touche_saut, SDL_Rect *posJ, const Personnage *J, int num_fond_combat, const Fond fondCombat[]);


/**
 * @brief Defense d'un personnage
 * @param[in] cote
 * @param[out] tempsDebutDef
 * @param[out] posJ
 * @param[out] J
 */
void defense(int cote, int *tempsDebutDef, SDL_Rect *posJ, Personnage *J);


/**
 * @brief Remettre le joueur normal si le temps de la défense est écoulé
 * @param[in] tempsActuel
 * @param[in] tempsDebutDef
 * @param[in] coteJ
 * @param[out] J
 * @param[out] posJ
 */
void fin_defense(int tempsActuel, int tempsDebutDef, int coteJ, Personnage *J, SDL_Rect *posJ);


/**
 * @brief Attaquer l'adversaire
 * @param[in] cote
 * @param[in] posEnnemi
 * @param[out] tempsDebutAtk
 * @param[out] posBarrePV
 * @param[out] posJ
 * @param[out] J
 * @param[out] Ennemi
 * @param[out] reculAtk
 */
void attaque(int cote, int *tempsDebutAtk, SDL_Rect *posBarrePV, SDL_Rect *posJ, const SDL_Rect *posEnnemi, Personnage *J, Personnage *Ennemi, int *reculAtk);


/**
 * @brief Remettre le joueur normal si le temps de l'attaque est écoulé
 * @param[in] tempsActuel
 * @param[in] tempsDebutAtk
 * @param[in] coteJ
 * @param[out] J
 * @param[out] posJ
 * @param[out] reculAtk
 */
void fin_attaque(int tempsActuel, int tempsDebutAtk, int *reculAtk, int coteJ, Personnage *J, SDL_Rect *posJ);


/******************************** Reste ********************************/


/**
 * @brief Teste l'état des différentes touches et indique lequels sont enfoncées
 * @param[in] char touche[]
 * @param[out] continuer
 * @param[out] continuer_combat
 * @param[out] espace
 * @param[out] q
 * @param[out] d
 * @param[out] z
 * @param[out] s
 * @param[out] a
 * @param[out] entree
 * @param[out] fleche_droite
 * @param[out] fleche_gauche
 * @param[out] fleche_haut
 * @param[out] fleche_bas
 * @param[out] shift_droit
 */
void test_touche(char touche[], int *continuer, int *continuer_combat, int *espace, int *q, int *d, int *z, int *s, int *a, int *entree, int *fleche_droite, int *fleche_gauche, int *fleche_haut, int *fleche_bas, int *shift_droit);


/**
 * @brief Remet le personnage normal si il est en image de deplacement
 * @param[out] J
 */
void remettre_perso_normal(Personnage *J);


/**
 * @brief Crée la barre de PV, remet les PV à 0 si PV négatif
 * @param[out] ecran
 * @param[out] barrePV
 * @param[out] J
 * @return barrePV
 */
SDL_Surface* barrePV(SDL_Surface *ecran, SDL_Surface *barrePV, Personnage *J);


/**
 * @brief Crée la barre d'énergie, remet les PV à 0 si PV négatif
 * @param[in] decalerBarre
 * @param[out] ecran
 * @param[out] barreEnergie
 * @param[out] J
 * @param[out] posBarreEnergie
 * @return barreEnergie
 */
SDL_Surface* barreEnergie(SDL_Surface *ecran, SDL_Surface *barreEnergie, Personnage *J, SDL_Rect *posBarreEnergie, int decalerBarre);


/**
 * @brief Remet le personnage à la bonne position vertical
 * @param[in] J
 * @param[in] num_fond_combat
 * @param[in] fondCombat[]
 * @param[out] posJ
 */
void posVertical(SDL_Rect *posJ, const Personnage *J, int num_fond_combat, const Fond fondCombat[]);


/**
 * @brief Remet les touches à zéro (non enfoncées)
 * @param[out] q
 * @param[out] d
 * @param[out] s
 * @param[out] espace
 * @param[out] fleche_gauche
 * @param[out] fleche_droite
 * @param[out] fleche_bas
 * @param[out] entree
 */
void touches_zero(int *q, int *d, int *s, int *espace, int *fleche_gauche, int *fleche_droite, int *fleche_bas, int *entree);


/**
 * @brief Teste si un personnage est mort
 * @param[in] coteJ
 * @param[out] J
 * @param[out] posJ
 * @return 1 si personnage mort, 0 sinon
 */
int mort(int coteJ, Personnage *J, SDL_Rect *posJ);


/**
 * @brief Fin du combat
 * @param[out] continuer
 * @param[out] continuer_combat2
 */
void fin_combat(int *continuer, int *continuer_combat2);


/**
 * @brief Libère les surfaces utilisées pour le combat
 * @param[out] fond
 * @param[out] nom1
 * @param[out] nom2
 * @param[out] barrePV1
 * @param[out] barrePV2
 * @param[out] barreEnergie1
 * @param[out] barreEnergie2
 * @param[out] J1
 * @param[out] J2
 */
void liberer_surfaces_combat(SDL_Surface **fond, SDL_Surface **nom1, SDL_Surface **nom2, SDL_Surface **barrePV1, SDL_Surface **barrePV2, SDL_Surface **barreEnergie1, SDL_Surface **barreEnergie2, Personnage *J1, Personnage *J2);

#endif
