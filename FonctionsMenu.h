/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier header de FonctionsCombat.c
**/


#ifndef FONCTIONSMENU_H_INCLUDED
#define FONCTIONSMENU_H_INCLUDED


/**
 * @brief Blitter des surfaces à l'écran
 * @param[in] pos1
 * @param[in] pos2
 * @param[in] pos3
 * @param[in] pos4
 * @param[in] pos5
 * @param[in] pos6
 * @param[in] pos7
 * @param[in] pos8
 * @param[in] pos9
 * @param[in] pos10
 * @param[out] ecran
 * @param[out] surf1
 * @param[out] surf2
 * @param[out] surf3
 * @param[out] surf4
 * @param[out] surf5
 * @param[out] surf6
 * @param[out] surf7
 * @param[out] surf8
 * @param[out] surf9
 * @param[out] surf10
 */
 void afficher_surfaces(SDL_Surface *ecran, SDL_Surface *surf1, SDL_Rect pos1, SDL_Surface *surf2, SDL_Rect pos2, SDL_Surface *surf3, SDL_Rect pos3, SDL_Surface *surf4, SDL_Rect pos4, SDL_Surface *surf5, SDL_Rect pos5, SDL_Surface *surf6, SDL_Rect pos6, SDL_Surface *surf7, SDL_Rect pos7, SDL_Surface *surf8, SDL_Rect pos8, SDL_Surface *surf9, SDL_Rect pos9, SDL_Surface *surf10, SDL_Rect pos10);


/******************************** Menu ********************************/


/**
 * @brief Initialiser la fenêtre graphique
 * @param[out] ecran
 */
 void initialisation(SDL_Surface **ecran);


 /**
 * @brief Charger les images du menu
 * @param[out] fond
 * @param[out] selection1
 * @param[out] selection2
 */
 void images_menu(SDL_Surface **fond, SDL_Surface **selection1, SDL_Surface **selection2);


/**
 * @brief Renvoyer la selection actuelle
 * @param[out] selection
 * @param[out] touche[]
 * @return selection si espace/entrée, sinon 0
 */
 int selectionner(int *selection, char touche[]);


/**
 * @brief Positions des curseurs de selections
 * @param[in] selection
 * @param[in] continuer
 * @param[out] posSelection1
 * @param[out] posSelection2
 */
 void posSelection(int selection, SDL_Rect *posSelection1, SDL_Rect *posSelection2);


 /**
 * @brief Libérer les surfaces du menu
 * @param[out] surf1
 * @param[out] surf2
 * @param[out] surf3
 * @param[out] surf4
 */
void liberer_surfaces_menu(SDL_Surface **surf1, SDL_Surface **surf2, SDL_Surface **surf3, SDL_Surface **surf4);


/******************************** Choix persos ********************************/


/**
 * @brief Initialiser les positions pour le menu de choix de personnages
 * @param[out] posPortrait1
 * @param[out] posPortrait2
 * @param[out] posCases[][]
 */
 void initialisation_pos_choix_persos(SDL_Rect *posPortrait1, SDL_Rect *posPortrait2, SDL_Rect posCases[10][8]);


/**
 * @brief Charger les images pour le choix des personnages
 * @param[out] fond
 * @param[out] cases[][]
 * @param[out] portraits[][]
 */
 void charger_images_choix_persos(SDL_Surface **fond, SDL_Surface *cases[10][8], SDL_Surface *portraits[10][8]);


 /**
 * @brief Selection du 1er perso
 * @param[in] ligne2
 * @param[in] colonne2
 * @param[out] perso1
 * @param[out] ligne1
 * @param[out] colonne1
 * @param[out] touche[]
 */
 void selectionner_perso1(int *perso1, int *ligne1, int *colonne1, int ligne2, int colonne2, char touche[]);


/**
 * @brief Selection du 2eme perso
 * @param[in] ligne1
 * @param[in] colonne1
 * @param[out] perso2
 * @param[out] ligne2
 * @param[out] colonne2
 * @param[out] touche[]
 */
 void selectionner_perso2(int *perso2, int *ligne2, int *colonne2, int ligne1, int colonne1, char touche[]);


/**
 * @brief Création des curseurs de selection de personnages
 * @param[in] ecran
 * @param[out] selection1
 * @param[out] selection2
 */
 void creation_selection_choix_persos(SDL_Surface *ecran, SDL_Surface **selection1, SDL_Surface **selection2);


/**
 * @brief Positions des curseurs de selection de personnages
 * @param[in] ligne
 * @param[in] colonne
 * @param[in] posCases[][]
 * @param[out] posSelection[][]
 */
 void pos_selection_persos(int ligne, int colonne, SDL_Rect posSelection[10][8], SDL_Rect posCases[10][8]);


/**
 * @brief Blitter les surfaces du choix des personnages
 * @param[in] continuer
 * @param[in] perso1
 * @param[in] perso2
 * @param[in] ligne1
 * @param[in] ligne2
 * @param[in] colonne1
 * @param[in] colonne2
 * @param[in] pos0
 * @param[in] posSelection[][]
 * @param[in] posCases[][]
 * @param[in] posPortrait1
 * @param[in] posPortrait2
 * @param[out] ecran
 * @param[out] fond
 * @param[out] selection1
 * @param[out] selection2
 * @param[out] cases[][]
 * @param[out] portraits[][]
 */
 void affichage_choix_persos(SDL_Surface *ecran, SDL_Surface *fond, SDL_Surface *selection1, SDL_Surface *selection2, SDL_Surface *cases[10][8], SDL_Surface *portraits[10][8], SDL_Rect pos0, SDL_Rect posSelection[10][8], SDL_Rect posCases[10][8], SDL_Rect posPortrait1, SDL_Rect posPortrait2, const int *perso1, const int *perso2, int ligne1, int ligne2, int colonne1, int colonne2, const int *continuer);


 /**
 * @brief Passer au choix du fond
 * @param[out] continuer
 * @param[out] continuer_choix_persos
 */
 void fin_choix_persos(int *continuer, int *continuer_choix_persos);


/**
 * @brief Libérer les surfaces du choix des personnages
 * @param[out] selection1
 * @param[out] selection2
 * @param[out] cases
 * @param[out] portraits
 */
void liberer_surfaces_choix_persos(SDL_Surface **selection1, SDL_Surface **selection2, SDL_Surface *cases[10][8], SDL_Surface *portraits[10][8]);


/******************************** Choix fonds ********************************/


/**
 * @brief Initialiser les positions pour le menu de choix du fond
 * @param[out] posApercu
 * @param[out] posCases[][]
 */
 void initialisation_pos_choix_fond(SDL_Rect *posApercu, SDL_Rect posCases[5][5]);


/**
 * @brief Charger les images pour le choix du fond
 * @param[out] fond
 * @param[out] cases[][]
 * @param[out] apercu[][]
 */
 void charger_images_choix_fond(SDL_Surface **fond, SDL_Surface *cases[5][5], SDL_Surface *apercu[5][5]);


/**
 * @brief Création du curseur de sélection du fond
 * @param[in] ecran
 * @param[out] selection
 */
 void creation_selection_choix_fond(SDL_Surface *ecran, SDL_Surface **selection);


/**
 * @brief Selection du fond
 * @param[out] num_fond_combat
 * @param[out] ligne
 * @param[out] colonne
 * @param[out] touche[]
 */
 void selectionner_fond(int *num_fond_combat, int *ligne, int *colonne, char touche[]);


/**
 * @brief Positions des curseurs de selection du fond
 * @param[in] ligne
 * @param[in] colonne
 * @param[in] posCases[][]
 * @param[out] posSelection[][]
 */
 void pos_selection_fond(int ligne, int colonne, SDL_Rect posSelection[5][5], SDL_Rect posCases[5][5]);


/**
 * @brief Blitter les surfaces de choix du fond
 * @param[in] fond_combat
 * @param[in] ligne
 * @param[in] colonne
 * @param[in] continuer
 * @param[in] pos0
 * @param[in] posSelection[][]
 * @param[in] posCases[][]
 * @param[in] posApercu
 * @param[out] ecran
 * @param[out] fond
 * @param[out] selection
 * @param[out] cases[][]
 * @param[out] apercu[][]
 */
 void affichage_choix_fond(SDL_Surface *ecran, SDL_Surface *fond, SDL_Surface *selection, SDL_Surface *cases[5][5], SDL_Surface *apercu[5][5], SDL_Rect pos0, SDL_Rect posSelection[5][5], SDL_Rect posCases[5][5], SDL_Rect posApercu, const int *fond_combat, int ligne, int colonne, const int *continuer);


/**
 * @brief Passer au combat
 * @param[out] continuer
 * @param[out] continuer_choix_fonds
 */
 void fin_choix_fond(int *continuer, int *continuer_choix_fonds);


 /**
 * @brief Libérer les surfaces du choix des personnages
 * @param[out] selection
 * @param[out] cases
 * @param[out] apercu
 */
void liberer_surfaces_choix_fonds(SDL_Surface **selection, SDL_Surface *cases[5][5], SDL_Surface *apercu[5][5]);

#endif
