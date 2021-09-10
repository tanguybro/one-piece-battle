/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier des constantes
**/


#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

  /** Constantes de base **/

  #define LARGEUR_FENETRE 1400
  #define HAUTEUR_FENETRE 700
  #define QUITTER -1

  /** Constantes du Jeu **/

  /* Général */

  #define NOMBRE_PERSOS 40
  #define NOMBRE_FONDS 25
  #define NON_SELECTIONNE -1

  /* Combat */

  #define ENERGIE_MAX 300
  #define SAUT 10
  #define DUREE_ATK 400
  #define DUREE_DEF 600
  #define DUREE_SPE 280
  #define FREQUENCE_ATK 900
  #define FREQUENCE_DEF 1000
  #define COUT_SPE 299
  #define DUREE_FIN_COMBAT 2000

  enum {LUFFY,ZORRO,NAMI,USSOP,SANJI,
        CHOPPER,ROBIN,FRANKY,BROOK,LAW,
        DRAKE,KIDD,CAPONE,ACE,JINBE,
        AKAINU,AOKIJI,KIZARU,FUJITORA,SENGOKU,
        KUMA,DOFLAMINGO,CROCODILE,MIHAWK,MARCO,
        ENER,SHANKS,RAYLLEIGH,BARBE_BLANCHE,BARBE_NOIRE,
        SABO,GARP,SMOKER,T_BONE,RYUMA,
        BARTOLOMEO,LUCCI,CESAR,HODY,BAGGY,
        };
  enum {GAUCHE,DROITE};
  enum {MENU,COMMANDES,CHOIX_PERSOS,CHOIX_FONDS,COMBAT2};

#endif
