/**
One Piece Battle
--------------------------------------
Tanguy Brouassin
--------------------------------------
Fichier des personnages
**/


#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Constantes.h"
#include "Combat2.h"
#include "Personnages.h"
#include "StatsPersonnages.h"


Personnage Personnages(int *perso, SDL_Surface **nom, Personnage *J)
{
    SDL_Color couleurBlanche = {255,255,255};
    TTF_Font *policeNom = NULL;
    policeNom = TTF_OpenFont("verdana.ttf", 35);

    if(*perso == LUFFY)
    {
        Luffy.mort = IMG_Load("Personnages/Luffy/Luffy0.bmp");
        Luffy.mort2 = IMG_Load("Personnages/Luffy/Luffy0b.bmp");
        Luffy.normal = IMG_Load("Personnages/Luffy/Luffy1.bmp");
        Luffy.normal2 = IMG_Load("Personnages/Luffy/Luffy1b.bmp");
        Luffy.deplacement = IMG_Load("Personnages/Luffy/Luffy2.bmp");
        Luffy.deplacement2 = IMG_Load("Personnages/Luffy/Luffy2b.bmp");
        Luffy.attaque = IMG_Load("Personnages/Luffy/Luffy3.bmp");
        Luffy.attaque2 = IMG_Load("Personnages/Luffy/Luffy3b.bmp");
        Luffy.defense = IMG_Load("Personnages/Luffy/Luffy4.bmp");
        Luffy.defense2 = IMG_Load("Personnages/Luffy/Luffy4b.bmp");
        Luffy.special[0] = IMG_Load("Personnages/Luffy/Luffy5.bmp");
        Luffy.special[1] = IMG_Load("Personnages/Luffy/Luffy6.bmp");
        Luffy.special[2] = IMG_Load("Personnages/Luffy/Luffy7.bmp");
        Luffy.special[3] = IMG_Load("Personnages/Luffy/Luffy8.bmp");
        Luffy.special2[0] = IMG_Load("Personnages/Luffy/Luffy5b.bmp");
        Luffy.special2[1] = IMG_Load("Personnages/Luffy/Luffy6b.bmp");
        Luffy.special2[2] = IMG_Load("Personnages/Luffy/Luffy7b.bmp");
        Luffy.special2[3] = IMG_Load("Personnages/Luffy/Luffy8b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Luffy", couleurBlanche);
        *J = Luffy;
    }

    if(*perso == ZORRO)
    {
        Zorro.mort = IMG_Load("Personnages/Zorro/Zorro0.bmp");
        Zorro.mort2 = IMG_Load("Personnages/Zorro/Zorro0b.bmp");
        Zorro.normal = IMG_Load("Personnages/Zorro/Zorro1.bmp");
        Zorro.normal2 = IMG_Load("Personnages/Zorro/Zorro1b.bmp");
        Zorro.deplacement = IMG_Load("Personnages/Zorro/Zorro2.bmp");
        Zorro.deplacement2 = IMG_Load("Personnages/Zorro/Zorro2b.bmp");
        Zorro.attaque = IMG_Load("Personnages/Zorro/Zorro3.bmp");
        Zorro.attaque2 = IMG_Load("Personnages/Zorro/Zorro3b.bmp");
        Zorro.defense = IMG_Load("Personnages/Zorro/Zorro4.bmp");
        Zorro.defense2 = IMG_Load("Personnages/Zorro/Zorro4b.bmp");
        Zorro.special[0] = IMG_Load("Personnages/Zorro/Zorro5.bmp");
        Zorro.special[1] = IMG_Load("Personnages/Zorro/Zorro6.bmp");
        Zorro.special2[0] = IMG_Load("Personnages/Zorro/Zorro5b.bmp");
        Zorro.special2[1] = IMG_Load("Personnages/Zorro/Zorro6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Zorro", couleurBlanche);
        *J = Zorro;
    }

    if(*perso == NAMI)
    {
        Nami.mort = IMG_Load("Personnages/Nami/Nami0.bmp");
        Nami.mort2 = IMG_Load("Personnages/Nami/Nami0b.bmp");
        Nami.normal = IMG_Load("Personnages/Nami/Nami1.bmp");
        Nami.normal2 = IMG_Load("Personnages/Nami/Nami1b.bmp");
        Nami.deplacement = IMG_Load("Personnages/Nami/Nami2.bmp");
        Nami.deplacement2 = IMG_Load("Personnages/Nami/Nami2b.bmp");
        Nami.attaque = IMG_Load("Personnages/Nami/Nami3.bmp");
        Nami.attaque2 = IMG_Load("Personnages/Nami/Nami3b.bmp");
        Nami.defense = IMG_Load("Personnages/Nami/Nami4.bmp");
        Nami.defense2 = IMG_Load("Personnages/Nami/Nami4b.bmp");
        Nami.special[0] = IMG_Load("Personnages/Nami/Nami5.bmp");
        Nami.special[1] = IMG_Load("Personnages/Nami/Nami6.bmp");
        Nami.special[2] = IMG_Load("Personnages/Nami/Nami7.bmp");
        Nami.special2[0] = IMG_Load("Personnages/Nami/Nami5b.bmp");
        Nami.special2[1] = IMG_Load("Personnages/Nami/Nami6b.bmp");
        Nami.special2[2] = IMG_Load("Personnages/Nami/Nami7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Nami", couleurBlanche);
        *J = Nami;
    }

    if(*perso == USSOP)
    {
        Ussop.mort = IMG_Load("Personnages/Ussop/Ussop0.bmp");
        Ussop.mort2 = IMG_Load("Personnages/Ussop/Ussop0b.bmp");
        Ussop.normal = IMG_Load("Personnages/Ussop/Ussop1.bmp");
        Ussop.normal2 = IMG_Load("Personnages/Ussop/Ussop1b.bmp");
        Ussop.deplacement = IMG_Load("Personnages/Ussop/Ussop2.bmp");
        Ussop.deplacement2 = IMG_Load("Personnages/Ussop/Ussop2b.bmp");
        Ussop.attaque = IMG_Load("Personnages/Ussop/Ussop3.bmp");
        Ussop.attaque2 = IMG_Load("Personnages/Ussop/Ussop3b.bmp");
        Ussop.defense = IMG_Load("Personnages/Ussop/Ussop4.bmp");
        Ussop.defense2 = IMG_Load("Personnages/Ussop/Ussop4b.bmp");
        Ussop.special[0] = IMG_Load("Personnages/Ussop/Ussop5.bmp");
        Ussop.special[1] = IMG_Load("Personnages/Ussop/Ussop6.bmp");
        Ussop.special2[0] = IMG_Load("Personnages/Ussop/Ussop5b.bmp");
        Ussop.special2[1] = IMG_Load("Personnages/Ussop/Ussop6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Ussop", couleurBlanche);
        *J = Ussop;
    }

    if(*perso == SANJI)
    {
        Sanji.mort = IMG_Load("Personnages/Sanji/Sanji0.bmp");
        Sanji.mort2 = IMG_Load("Personnages/Sanji/Sanji0b.bmp");
        Sanji.normal = IMG_Load("Personnages/Sanji/Sanji1.bmp");
        Sanji.normal2 = IMG_Load("Personnages/Sanji/Sanji1b.bmp");
        Sanji.deplacement = IMG_Load("Personnages/Sanji/Sanji2.bmp");
        Sanji.deplacement2 = IMG_Load("Personnages/Sanji/Sanji2b.bmp");
        Sanji.attaque = IMG_Load("Personnages/Sanji/Sanji3.bmp");
        Sanji.attaque2 = IMG_Load("Personnages/Sanji/Sanji3b.bmp");
        Sanji.defense = IMG_Load("Personnages/Sanji/Sanji4.bmp");
        Sanji.defense2 = IMG_Load("Personnages/Sanji/Sanji4b.bmp");
        Sanji.special[0] = IMG_Load("Personnages/Sanji/Sanji5.bmp");
        Sanji.special[1] = IMG_Load("Personnages/Sanji/Sanji6.bmp");
        Sanji.special[2] = IMG_Load("Personnages/Sanji/Sanji7.bmp");
        Sanji.special[3] = IMG_Load("Personnages/Sanji/Sanji8.bmp");
        Sanji.special2[0] = IMG_Load("Personnages/Sanji/Sanji5b.bmp");
        Sanji.special2[1] = IMG_Load("Personnages/Sanji/Sanji6b.bmp");
        Sanji.special2[2] = IMG_Load("Personnages/Sanji/Sanji7b.bmp");
        Sanji.special2[3] = IMG_Load("Personnages/Sanji/Sanji8b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Sanji", couleurBlanche);
        *J = Sanji;
    }

    if(*perso == CHOPPER)
    {
        Chopper.mort = IMG_Load("Personnages/Chopper/Chopper0.bmp");
        Chopper.mort2 = IMG_Load("Personnages/Chopper/Chopper0b.bmp");
        Chopper.normal = IMG_Load("Personnages/Chopper/Chopper1.bmp");
        Chopper.normal2 = IMG_Load("Personnages/Chopper/Chopper1b.bmp");
        Chopper.deplacement = IMG_Load("Personnages/Chopper/Chopper2.bmp");
        Chopper.deplacement2 = IMG_Load("Personnages/Chopper/Chopper2b.bmp");
        Chopper.attaque = IMG_Load("Personnages/Chopper/Chopper3.bmp");
        Chopper.attaque2 = IMG_Load("Personnages/Chopper/Chopper3b.bmp");
        Chopper.defense = IMG_Load("Personnages/Chopper/Chopper4.bmp");
        Chopper.defense2 = IMG_Load("Personnages/Chopper/Chopper4b.bmp");
        Chopper.special[0] = IMG_Load("Personnages/Chopper/Chopper5.bmp");
        Chopper.special[1] = IMG_Load("Personnages/Chopper/Chopper6.bmp");
        Chopper.special2[0] = IMG_Load("Personnages/Chopper/Chopper5b.bmp");
        Chopper.special2[1] = IMG_Load("Personnages/Chopper/Chopper6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Chopper", couleurBlanche);
        *J = Chopper;
    }

    if(*perso == ROBIN)
    {
        Robin.mort = IMG_Load("Personnages/Robin/Robin0.bmp");
        Robin.mort2 = IMG_Load("Personnages/Robin/Robin0b.bmp");
        Robin.normal = IMG_Load("Personnages/Robin/Robin1.bmp");
        Robin.normal2 = IMG_Load("Personnages/Robin/Robin1b.bmp");
        Robin.deplacement = IMG_Load("Personnages/Robin/Robin2.bmp");
        Robin.deplacement2 = IMG_Load("Personnages/Robin/Robin2b.bmp");
        Robin.attaque = IMG_Load("Personnages/Robin/Robin3.bmp");
        Robin.attaque2 = IMG_Load("Personnages/Robin/Robin3b.bmp");
        Robin.defense = IMG_Load("Personnages/Robin/Robin4.bmp");
        Robin.defense2 = IMG_Load("Personnages/Robin/Robin4b.bmp");
        Robin.special[0] = IMG_Load("Personnages/Robin/Robin5.bmp");
        Robin.special[1] = IMG_Load("Personnages/Robin/Robin6.bmp");
        Robin.special[2] = IMG_Load("Personnages/Robin/Robin7.bmp");
        Robin.special[3] = IMG_Load("Personnages/Robin/Robin8.bmp");
        Robin.special2[0] = IMG_Load("Personnages/Robin/Robin5b.bmp");
        Robin.special2[1] = IMG_Load("Personnages/Robin/Robin6b.bmp");
        Robin.special2[2] = IMG_Load("Personnages/Robin/Robin7b.bmp");
        Robin.special2[3] = IMG_Load("Personnages/Robin/Robin8b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Robin", couleurBlanche);
        *J = Robin;
    }

    if(*perso == FRANKY)
    {
        Franky.mort = IMG_Load("Personnages/Franky/Franky0.bmp");
        Franky.mort2 = IMG_Load("Personnages/Franky/Franky0b.bmp");
        Franky.normal = IMG_Load("Personnages/Franky/Franky1.bmp");
        Franky.normal2 = IMG_Load("Personnages/Franky/Franky1b.bmp");
        Franky.deplacement = IMG_Load("Personnages/Franky/Franky2.bmp");
        Franky.deplacement2 = IMG_Load("Personnages/Franky/Franky2b.bmp");
        Franky.attaque = IMG_Load("Personnages/Franky/Franky3.bmp");
        Franky.attaque2 = IMG_Load("Personnages/Franky/Franky3b.bmp");
        Franky.defense = IMG_Load("Personnages/Franky/Franky4.bmp");
        Franky.defense2 = IMG_Load("Personnages/Franky/Franky4b.bmp");
        Franky.special[0] = IMG_Load("Personnages/Franky/Franky5.bmp");
        Franky.special[1] = IMG_Load("Personnages/Franky/Franky6.bmp");
        Franky.special[2] = IMG_Load("Personnages/Franky/Franky7.bmp");
        Franky.special2[0] = IMG_Load("Personnages/Franky/Franky5b.bmp");
        Franky.special2[1] = IMG_Load("Personnages/Franky/Franky6b.bmp");
        Franky.special2[2] = IMG_Load("Personnages/Franky/Franky7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Franky", couleurBlanche);
        *J = Franky;
    }

    if(*perso == BROOK)
    {
        Brook.mort = IMG_Load("Personnages/Brook/Brook0.bmp");
        Brook.mort2 = IMG_Load("Personnages/Brook/Brook0b.bmp");
        Brook.normal = IMG_Load("Personnages/Brook/Brook1.bmp");
        Brook.normal2 = IMG_Load("Personnages/Brook/Brook1b.bmp");
        Brook.deplacement = IMG_Load("Personnages/Brook/Brook2.bmp");
        Brook.deplacement2 = IMG_Load("Personnages/Brook/Brook2b.bmp");
        Brook.attaque = IMG_Load("Personnages/Brook/Brook3.bmp");
        Brook.attaque2 = IMG_Load("Personnages/Brook/Brook3b.bmp");
        Brook.defense = IMG_Load("Personnages/Brook/Brook4.bmp");
        Brook.defense2 = IMG_Load("Personnages/Brook/Brook4b.bmp");
        Brook.special[0] = IMG_Load("Personnages/Brook/Brook5.bmp");
        Brook.special[1] = IMG_Load("Personnages/Brook/Brook6.bmp");
        Brook.special2[0] = IMG_Load("Personnages/Brook/Brook5b.bmp");
        Brook.special2[1] = IMG_Load("Personnages/Brook/Brook6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Brook", couleurBlanche);
        *J = Brook;
    }

    if(*perso == LAW)
    {
        Law.mort = IMG_Load("Personnages/Law/Law0.bmp");
        Law.mort2 = IMG_Load("Personnages/Law/Law0b.bmp");
        Law.normal = IMG_Load("Personnages/Law/Law1.bmp");
        Law.normal2 = IMG_Load("Personnages/Law/Law1b.bmp");
        Law.deplacement = IMG_Load("Personnages/Law/Law2.bmp");
        Law.deplacement2 = IMG_Load("Personnages/Law/Law2b.bmp");
        Law.attaque = IMG_Load("Personnages/Law/Law3.bmp");
        Law.attaque2 = IMG_Load("Personnages/Law/Law3b.bmp");
        Law.defense = IMG_Load("Personnages/Law/Law4.bmp");
        Law.defense2 = IMG_Load("Personnages/Law/Law4b.bmp");
        Law.special[0] = IMG_Load("Personnages/Law/Law5.bmp");
        Law.special[1] = IMG_Load("Personnages/Law/Law6.bmp");
        Law.special[2] = IMG_Load("Personnages/Law/Law7.bmp");
        Law.special2[0] = IMG_Load("Personnages/Law/Law5b.bmp");
        Law.special2[1] = IMG_Load("Personnages/Law/Law6b.bmp");
        Law.special2[2] = IMG_Load("Personnages/Law/Law7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Law", couleurBlanche);
        *J = Law;
    }

    if(*perso == DRAKE)
    {
        Drake.mort = IMG_Load("Personnages/Drake/Drake0.bmp");
        Drake.mort2 = IMG_Load("Personnages/Drake/Drake0b.bmp");
        Drake.normal = IMG_Load("Personnages/Drake/Drake1.bmp");
        Drake.normal2 = IMG_Load("Personnages/Drake/Drake1b.bmp");
        Drake.deplacement = IMG_Load("Personnages/Drake/Drake2.bmp");
        Drake.deplacement2 = IMG_Load("Personnages/Drake/Drake2b.bmp");
        Drake.attaque = IMG_Load("Personnages/Drake/Drake3.bmp");
        Drake.attaque2 = IMG_Load("Personnages/Drake/Drake3b.bmp");
        Drake.defense = IMG_Load("Personnages/Drake/Drake4.bmp");
        Drake.defense2 = IMG_Load("Personnages/Drake/Drake4b.bmp");
        Drake.special[0] = IMG_Load("Personnages/Drake/Drake5.bmp");
        Drake.special[1] = IMG_Load("Personnages/Drake/Drake6.bmp");
        Drake.special2[0] = IMG_Load("Personnages/Drake/Drake5b.bmp");
        Drake.special2[1] = IMG_Load("Personnages/Drake/Drake6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Drake", couleurBlanche);
        *J = Drake;
    }

    if(*perso == KIDD)
    {
        Kidd.mort = IMG_Load("Personnages/Kidd/Kidd0.bmp");
        Kidd.mort2 = IMG_Load("Personnages/Kidd/Kidd0b.bmp");
        Kidd.normal = IMG_Load("Personnages/Kidd/Kidd1.bmp");
        Kidd.normal2 = IMG_Load("Personnages/Kidd/Kidd1b.bmp");
        Kidd.deplacement = IMG_Load("Personnages/Kidd/Kidd2.bmp");
        Kidd.deplacement2 = IMG_Load("Personnages/Kidd/Kidd2b.bmp");
        Kidd.attaque = IMG_Load("Personnages/Kidd/Kidd3.bmp");
        Kidd.attaque2 = IMG_Load("Personnages/Kidd/Kidd3b.bmp");
        Kidd.defense = IMG_Load("Personnages/Kidd/Kidd4.bmp");
        Kidd.defense2 = IMG_Load("Personnages/Kidd/Kidd4b.bmp");
        Kidd.special[0] = IMG_Load("Personnages/Kidd/Kidd5.bmp");
        Kidd.special[1] = IMG_Load("Personnages/Kidd/Kidd6.bmp");
        Kidd.special[2] = IMG_Load("Personnages/Kidd/Kidd7.bmp");
        Kidd.special2[0] = IMG_Load("Personnages/Kidd/Kidd5b.bmp");
        Kidd.special2[1] = IMG_Load("Personnages/Kidd/Kidd6b.bmp");
        Kidd.special2[2] = IMG_Load("Personnages/Kidd/Kidd7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Kidd", couleurBlanche);
        *J = Kidd;
    }

    if(*perso == CAPONE)
    {
        Capone.mort = IMG_Load("Personnages/Capone/Capone0.bmp");
        Capone.mort2 = IMG_Load("Personnages/Capone/Capone0b.bmp");
        Capone.normal = IMG_Load("Personnages/Capone/Capone1.bmp");
        Capone.normal2 = IMG_Load("Personnages/Capone/Capone1b.bmp");
        Capone.deplacement = IMG_Load("Personnages/Capone/Capone2.bmp");
        Capone.deplacement2 = IMG_Load("Personnages/Capone/Capone2b.bmp");
        Capone.attaque = IMG_Load("Personnages/Capone/Capone3.bmp");
        Capone.attaque2 = IMG_Load("Personnages/Capone/Capone3b.bmp");
        Capone.defense = IMG_Load("Personnages/Capone/Capone4.bmp");
        Capone.defense2 = IMG_Load("Personnages/Capone/Capone4b.bmp");
        Capone.special[0] = IMG_Load("Personnages/Capone/Capone5.bmp");
        Capone.special[1] = IMG_Load("Personnages/Capone/Capone6.bmp");
        Capone.special2[0] = IMG_Load("Personnages/Capone/Capone5b.bmp");
        Capone.special2[1] = IMG_Load("Personnages/Capone/Capone6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Capone", couleurBlanche);
        *J = Capone;
    }

    if(*perso == ACE)
    {
        Ace.mort = IMG_Load("Personnages/Ace/Ace0.bmp");
        Ace.mort2 = IMG_Load("Personnages/Ace/Ace0b.bmp");
        Ace.normal = IMG_Load("Personnages/Ace/Ace1.bmp");
        Ace.normal2 = IMG_Load("Personnages/Ace/Ace1b.bmp");
        Ace.deplacement = IMG_Load("Personnages/Ace/Ace2.bmp");
        Ace.deplacement2 = IMG_Load("Personnages/Ace/Ace2b.bmp");
        Ace.attaque = IMG_Load("Personnages/Ace/Ace3.bmp");
        Ace.attaque2 = IMG_Load("Personnages/Ace/Ace3b.bmp");
        Ace.defense = IMG_Load("Personnages/Ace/Ace4.bmp");
        Ace.defense2 = IMG_Load("Personnages/Ace/Ace4b.bmp");
        Ace.special[0] = IMG_Load("Personnages/Ace/Ace5.bmp");
        Ace.special[1] = IMG_Load("Personnages/Ace/Ace6.bmp");
        Ace.special[2] = IMG_Load("Personnages/Ace/Ace7.bmp");
        Ace.special2[0] = IMG_Load("Personnages/Ace/Ace5b.bmp");
        Ace.special2[1] = IMG_Load("Personnages/Ace/Ace6b.bmp");
        Ace.special2[2] = IMG_Load("Personnages/Ace/Ace7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Ace", couleurBlanche);
        *J = Ace;
    }

    if(*perso == JINBE)
    {
        Jinbe.mort = IMG_Load("Personnages/Jinbe/Jinbe0.bmp");
        Jinbe.mort2 = IMG_Load("Personnages/Jinbe/Jinbe0b.bmp");
        Jinbe.normal = IMG_Load("Personnages/Jinbe/Jinbe1.bmp");
        Jinbe.normal2 = IMG_Load("Personnages/Jinbe/Jinbe1b.bmp");
        Jinbe.deplacement = IMG_Load("Personnages/Jinbe/Jinbe2.bmp");
        Jinbe.deplacement2 = IMG_Load("Personnages/Jinbe/Jinbe2b.bmp");
        Jinbe.attaque = IMG_Load("Personnages/Jinbe/Jinbe3.bmp");
        Jinbe.attaque2 = IMG_Load("Personnages/Jinbe/Jinbe3b.bmp");
        Jinbe.defense = IMG_Load("Personnages/Jinbe/Jinbe4.bmp");
        Jinbe.defense2 = IMG_Load("Personnages/Jinbe/Jinbe4b.bmp");
        Jinbe.special[0] = IMG_Load("Personnages/Jinbe/Jinbe5.bmp");
        Jinbe.special[1] = IMG_Load("Personnages/Jinbe/Jinbe6.bmp");
        Jinbe.special[2] = IMG_Load("Personnages/Jinbe/Jinbe7.bmp");
        Jinbe.special[3] = IMG_Load("Personnages/Jinbe/Jinbe8.bmp");
        Jinbe.special2[0] = IMG_Load("Personnages/Jinbe/Jinbe5b.bmp");
        Jinbe.special2[1] = IMG_Load("Personnages/Jinbe/Jinbe6b.bmp");
        Jinbe.special2[2] = IMG_Load("Personnages/Jinbe/Jinbe7b.bmp");
        Jinbe.special2[3] = IMG_Load("Personnages/Jinbe/Jinbe8b.bmp");


        *nom=TTF_RenderText_Blended(policeNom, "Jinbe", couleurBlanche);
        *J = Jinbe;
    }

    if(*perso == AKAINU)
    {
        Akainu.mort = IMG_Load("Personnages/Akainu/Akainu0.bmp");
        Akainu.mort2 = IMG_Load("Personnages/Akainu/Akainu0b.bmp");
        Akainu.normal = IMG_Load("Personnages/Akainu/Akainu1.bmp");
        Akainu.normal2 = IMG_Load("Personnages/Akainu/Akainu1b.bmp");
        Akainu.deplacement = IMG_Load("Personnages/Akainu/Akainu2.bmp");
        Akainu.deplacement2 = IMG_Load("Personnages/Akainu/Akainu2b.bmp");
        Akainu.attaque = IMG_Load("Personnages/Akainu/Akainu3.bmp");
        Akainu.attaque2 = IMG_Load("Personnages/Akainu/Akainu3b.bmp");
        Akainu.defense = IMG_Load("Personnages/Akainu/Akainu4.bmp");
        Akainu.defense2 = IMG_Load("Personnages/Akainu/Akainu4b.bmp");
        Akainu.special[0] = IMG_Load("Personnages/Akainu/Akainu5.bmp");
        Akainu.special[1] = IMG_Load("Personnages/Akainu/Akainu6.bmp");
        Akainu.special[2] = IMG_Load("Personnages/Akainu/Akainu7.bmp");
        Akainu.special[3] = IMG_Load("Personnages/Akainu/Akainu8.bmp");
        Akainu.special2[0] = IMG_Load("Personnages/Akainu/Akainu5b.bmp");
        Akainu.special2[1] = IMG_Load("Personnages/Akainu/Akainu6b.bmp");
        Akainu.special2[2] = IMG_Load("Personnages/Akainu/Akainu7b.bmp");
        Akainu.special2[3] = IMG_Load("Personnages/Akainu/Akainu8b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Akainu", couleurBlanche);
        *J = Akainu;
    }

    if(*perso == AOKIJI)
    {
        Aokiji.mort = IMG_Load("Personnages/Aokiji/Aokiji0.bmp");
        Aokiji.mort2 = IMG_Load("Personnages/Aokiji/Aokiji0b.bmp");
        Aokiji.normal = IMG_Load("Personnages/Aokiji/Aokiji1.bmp");
        Aokiji.normal2 = IMG_Load("Personnages/Aokiji/Aokiji1b.bmp");
        Aokiji.deplacement = IMG_Load("Personnages/Aokiji/Aokiji2.bmp");
        Aokiji.deplacement2 = IMG_Load("Personnages/Aokiji/Aokiji2b.bmp");
        Aokiji.attaque = IMG_Load("Personnages/Aokiji/Aokiji3.bmp");
        Aokiji.attaque2 = IMG_Load("Personnages/Aokiji/Aokiji3b.bmp");
        Aokiji.defense = IMG_Load("Personnages/Aokiji/Aokiji4.bmp");
        Aokiji.defense2 = IMG_Load("Personnages/Aokiji/Aokiji4b.bmp");
        Aokiji.special[0] = IMG_Load("Personnages/Aokiji/Aokiji5.bmp");
        Aokiji.special[1] = IMG_Load("Personnages/Aokiji/Aokiji6.bmp");
        Aokiji.special2[0] = IMG_Load("Personnages/Aokiji/Aokiji5b.bmp");
        Aokiji.special2[1] = IMG_Load("Personnages/Aokiji/Aokiji6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Aokiji", couleurBlanche);
        *J = Aokiji;
    }

    if(*perso == KIZARU)
    {
        Kizaru.mort = IMG_Load("Personnages/Kizaru/Kizaru0.bmp");
        Kizaru.mort2 = IMG_Load("Personnages/Kizaru/Kizaru0b.bmp");
        Kizaru.normal = IMG_Load("Personnages/Kizaru/Kizaru1.bmp");
        Kizaru.normal2 = IMG_Load("Personnages/Kizaru/Kizaru1b.bmp");
        Kizaru.deplacement = IMG_Load("Personnages/Kizaru/Kizaru2.bmp");
        Kizaru.deplacement2 = IMG_Load("Personnages/Kizaru/Kizaru2b.bmp");
        Kizaru.attaque = IMG_Load("Personnages/Kizaru/Kizaru3.bmp");
        Kizaru.attaque2 = IMG_Load("Personnages/Kizaru/Kizaru3b.bmp");
        Kizaru.defense = IMG_Load("Personnages/Kizaru/Kizaru4.bmp");
        Kizaru.defense2 = IMG_Load("Personnages/Kizaru/Kizaru4b.bmp");
        Kizaru.special[0] = IMG_Load("Personnages/Kizaru/Kizaru5.bmp");
        Kizaru.special[1] = IMG_Load("Personnages/Kizaru/Kizaru6.bmp");
        Kizaru.special[2] = IMG_Load("Personnages/Kizaru/Kizaru7.bmp");
        Kizaru.special2[0] = IMG_Load("Personnages/Kizaru/Kizaru5b.bmp");
        Kizaru.special2[1] = IMG_Load("Personnages/Kizaru/Kizaru6b.bmp");
        Kizaru.special2[2] = IMG_Load("Personnages/Kizaru/Kizaru7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Kizaru", couleurBlanche);
        *J = Kizaru;
    }

    if(*perso == FUJITORA)
    {
        Fujitora.mort = IMG_Load("Personnages/Fujitora/Fujitora0.bmp");
        Fujitora.mort2 = IMG_Load("Personnages/Fujitora/Fujitora0b.bmp");
        Fujitora.normal = IMG_Load("Personnages/Fujitora/Fujitora1.bmp");
        Fujitora.normal2 = IMG_Load("Personnages/Fujitora/Fujitora1b.bmp");
        Fujitora.deplacement = IMG_Load("Personnages/Fujitora/Fujitora2.bmp");
        Fujitora.deplacement2 = IMG_Load("Personnages/Fujitora/Fujitora2b.bmp");
        Fujitora.attaque = IMG_Load("Personnages/Fujitora/Fujitora3.bmp");
        Fujitora.attaque2 = IMG_Load("Personnages/Fujitora/Fujitora3b.bmp");
        Fujitora.defense = IMG_Load("Personnages/Fujitora/Fujitora4.bmp");
        Fujitora.defense2 = IMG_Load("Personnages/Fujitora/Fujitora4b.bmp");
        Fujitora.special[0] = IMG_Load("Personnages/Fujitora/Fujitora5.bmp");
        Fujitora.special[1] = IMG_Load("Personnages/Fujitora/Fujitora6.bmp");
        Fujitora.special[2] = IMG_Load("Personnages/Fujitora/Fujitora7.bmp");
        Fujitora.special2[0] = IMG_Load("Personnages/Fujitora/Fujitora5b.bmp");
        Fujitora.special2[1] = IMG_Load("Personnages/Fujitora/Fujitora6b.bmp");
        Fujitora.special2[2] = IMG_Load("Personnages/Fujitora/Fujitora7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Fujitora", couleurBlanche);
        *J = Fujitora;
    }

    if(*perso == SENGOKU)
    {
        Sengoku.mort = IMG_Load("Personnages/Sengoku/Sengoku0.bmp");
        Sengoku.mort2 = IMG_Load("Personnages/Sengoku/Sengoku0b.bmp");
        Sengoku.normal = IMG_Load("Personnages/Sengoku/Sengoku1.bmp");
        Sengoku.normal2 = IMG_Load("Personnages/Sengoku/Sengoku1b.bmp");
        Sengoku.deplacement = IMG_Load("Personnages/Sengoku/Sengoku2.bmp");
        Sengoku.deplacement2 = IMG_Load("Personnages/Sengoku/Sengoku2b.bmp");
        Sengoku.attaque = IMG_Load("Personnages/Sengoku/Sengoku3.bmp");
        Sengoku.attaque2 = IMG_Load("Personnages/Sengoku/Sengoku3b.bmp");
        Sengoku.defense = IMG_Load("Personnages/Sengoku/Sengoku4.bmp");
        Sengoku.defense2 = IMG_Load("Personnages/Sengoku/Sengoku4b.bmp");
        Sengoku.special[0] = IMG_Load("Personnages/Sengoku/Sengoku5.bmp");
        Sengoku.special[1] = IMG_Load("Personnages/Sengoku/Sengoku6.bmp");
        Sengoku.special[2] = IMG_Load("Personnages/Sengoku/Sengoku7.bmp");
        Sengoku.special2[0] = IMG_Load("Personnages/Sengoku/Sengoku5b.bmp");
        Sengoku.special2[1] = IMG_Load("Personnages/Sengoku/Sengoku6b.bmp");
        Sengoku.special2[2] = IMG_Load("Personnages/Sengoku/Sengoku7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Sengoku", couleurBlanche);
        *J = Sengoku;
    }

    if(*perso == KUMA)
    {
        Kuma.mort = IMG_Load("Personnages/Kuma/Kuma0.bmp");
        Kuma.mort2 = IMG_Load("Personnages/Kuma/Kuma0b.bmp");
        Kuma.normal = IMG_Load("Personnages/Kuma/Kuma1.bmp");
        Kuma.normal2 = IMG_Load("Personnages/Kuma/Kuma1b.bmp");
        Kuma.deplacement = IMG_Load("Personnages/Kuma/Kuma2.bmp");
        Kuma.deplacement2 = IMG_Load("Personnages/Kuma/Kuma2b.bmp");
        Kuma.attaque = IMG_Load("Personnages/Kuma/Kuma3.bmp");
        Kuma.attaque2 = IMG_Load("Personnages/Kuma/Kuma3b.bmp");
        Kuma.defense = IMG_Load("Personnages/Kuma/Kuma4.bmp");
        Kuma.defense2 = IMG_Load("Personnages/Kuma/Kuma4b.bmp");
        Kuma.special[0] = IMG_Load("Personnages/Kuma/Kuma5.bmp");
        Kuma.special[1] = IMG_Load("Personnages/Kuma/Kuma6.bmp");
        Kuma.special2[0] = IMG_Load("Personnages/Kuma/Kuma5b.bmp");
        Kuma.special2[1] = IMG_Load("Personnages/Kuma/Kuma6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Kuma", couleurBlanche);
        *J = Kuma;
    }

    if(*perso == DOFLAMINGO)
    {
        Doflamingo.mort = IMG_Load("Personnages/Doflamingo/Doflamingo0.bmp");
        Doflamingo.mort2 = IMG_Load("Personnages/Doflamingo/Doflamingo0b.bmp");
        Doflamingo.normal = IMG_Load("Personnages/Doflamingo/Doflamingo1.bmp");
        Doflamingo.normal2 = IMG_Load("Personnages/Doflamingo/Doflamingo1b.bmp");
        Doflamingo.deplacement = IMG_Load("Personnages/Doflamingo/Doflamingo2.bmp");
        Doflamingo.deplacement2 = IMG_Load("Personnages/Doflamingo/Doflamingo2b.bmp");
        Doflamingo.attaque = IMG_Load("Personnages/Doflamingo/Doflamingo3.bmp");
        Doflamingo.attaque2 = IMG_Load("Personnages/Doflamingo/Doflamingo3b.bmp");
        Doflamingo.defense = IMG_Load("Personnages/Doflamingo/Doflamingo4.bmp");
        Doflamingo.defense2 = IMG_Load("Personnages/Doflamingo/Doflamingo4b.bmp");
        Doflamingo.special[0] = IMG_Load("Personnages/Doflamingo/Doflamingo5.bmp");
        Doflamingo.special[1] = IMG_Load("Personnages/Doflamingo/Doflamingo6.bmp");
        Doflamingo.special[2] = IMG_Load("Personnages/Doflamingo/Doflamingo7.bmp");
        Doflamingo.special2[0] = IMG_Load("Personnages/Doflamingo/Doflamingo5b.bmp");
        Doflamingo.special2[1] = IMG_Load("Personnages/Doflamingo/Doflamingo6b.bmp");
        Doflamingo.special2[2] = IMG_Load("Personnages/Doflamingo/Doflamingo7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Doflamingo", couleurBlanche);
        *J = Doflamingo;
    }

    if(*perso == CROCODILE)
    {
        Crocodile.mort = IMG_Load("Personnages/Crocodile/Crocodile0.bmp");
        Crocodile.mort2 = IMG_Load("Personnages/Crocodile/Crocodile0b.bmp");
        Crocodile.normal = IMG_Load("Personnages/Crocodile/Crocodile1.bmp");
        Crocodile.normal2 = IMG_Load("Personnages/Crocodile/Crocodile1b.bmp");
        Crocodile.deplacement = IMG_Load("Personnages/Crocodile/Crocodile2.bmp");
        Crocodile.deplacement2 = IMG_Load("Personnages/Crocodile/Crocodile2b.bmp");
        Crocodile.attaque = IMG_Load("Personnages/Crocodile/Crocodile3.bmp");
        Crocodile.attaque2 = IMG_Load("Personnages/Crocodile/Crocodile3b.bmp");
        Crocodile.defense = IMG_Load("Personnages/Crocodile/Crocodile4.bmp");
        Crocodile.defense2 = IMG_Load("Personnages/Crocodile/Crocodile4b.bmp");
        Crocodile.special[0] = IMG_Load("Personnages/Crocodile/Crocodile5.bmp");
        Crocodile.special[1] = IMG_Load("Personnages/Crocodile/Crocodile6.bmp");
        Crocodile.special2[0] = IMG_Load("Personnages/Crocodile/Crocodile5b.bmp");
        Crocodile.special2[1] = IMG_Load("Personnages/Crocodile/Crocodile6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Crocodile", couleurBlanche);
        *J = Crocodile;
    }

    if(*perso == MIHAWK)
    {
        Mihawk.mort = IMG_Load("Personnages/Mihawk/Mihawk0.bmp");
        Mihawk.mort2 = IMG_Load("Personnages/Mihawk/Mihawk0b.bmp");
        Mihawk.normal = IMG_Load("Personnages/Mihawk/Mihawk1.bmp");
        Mihawk.normal2 = IMG_Load("Personnages/Mihawk/Mihawk1b.bmp");
        Mihawk.deplacement = IMG_Load("Personnages/Mihawk/Mihawk2.bmp");
        Mihawk.deplacement2 = IMG_Load("Personnages/Mihawk/Mihawk2b.bmp");
        Mihawk.attaque = IMG_Load("Personnages/Mihawk/Mihawk3.bmp");
        Mihawk.attaque2 = IMG_Load("Personnages/Mihawk/Mihawk3b.bmp");
        Mihawk.defense = IMG_Load("Personnages/Mihawk/Mihawk4.bmp");
        Mihawk.defense2 = IMG_Load("Personnages/Mihawk/Mihawk4b.bmp");
        Mihawk.special[0] = IMG_Load("Personnages/Mihawk/Mihawk5.bmp");
        Mihawk.special[1] = IMG_Load("Personnages/Mihawk/Mihawk6.bmp");
        Mihawk.special[2] = IMG_Load("Personnages/Mihawk/Mihawk7.bmp");
        Mihawk.special2[0] = IMG_Load("Personnages/Mihawk/Mihawk5b.bmp");
        Mihawk.special2[1] = IMG_Load("Personnages/Mihawk/Mihawk6b.bmp");
        Mihawk.special2[2] = IMG_Load("Personnages/Mihawk/Mihawk7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Mihawk", couleurBlanche);
        *J = Mihawk;
    }

    if(*perso == MARCO)
    {
        Marco.mort = IMG_Load("Personnages/Marco/Marco0.bmp");
        Marco.mort2 = IMG_Load("Personnages/Marco/Marco0b.bmp");
        Marco.normal = IMG_Load("Personnages/Marco/Marco1.bmp");
        Marco.normal2 = IMG_Load("Personnages/Marco/Marco1b.bmp");
        Marco.deplacement = IMG_Load("Personnages/Marco/Marco2.bmp");
        Marco.deplacement2 = IMG_Load("Personnages/Marco/Marco2b.bmp");
        Marco.attaque = IMG_Load("Personnages/Marco/Marco3.bmp");
        Marco.attaque2 = IMG_Load("Personnages/Marco/Marco3b.bmp");
        Marco.defense = IMG_Load("Personnages/Marco/Marco4b.bmp");
        Marco.defense2 = IMG_Load("Personnages/Marco/Marco4b.bmp");
        Marco.special[0] = IMG_Load("Personnages/Marco/Marco5.bmp");
        Marco.special[1] = IMG_Load("Personnages/Marco/Marco6.bmp");
        Marco.special2[0] = IMG_Load("Personnages/Marco/Marco5b.bmp");
        Marco.special2[1] = IMG_Load("Personnages/Marco/Marco6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Marco", couleurBlanche);
        *J = Marco;
    }

    if(*perso == ENER)
    {
        Ener.mort = IMG_Load("Personnages/Ener/Ener0.bmp");
        Ener.mort2 = IMG_Load("Personnages/Ener/Ener0b.bmp");
        Ener.normal = IMG_Load("Personnages/Ener/Ener1.bmp");
        Ener.normal2 = IMG_Load("Personnages/Ener/Ener1b.bmp");
        Ener.deplacement = IMG_Load("Personnages/Ener/Ener2.bmp");
        Ener.deplacement2 = IMG_Load("Personnages/Ener/Ener2b.bmp");
        Ener.attaque = IMG_Load("Personnages/Ener/Ener3.bmp");
        Ener.attaque2 = IMG_Load("Personnages/Ener/Ener3b.bmp");
        Ener.defense = IMG_Load("Personnages/Ener/Ener4.bmp");
        Ener.defense2 = IMG_Load("Personnages/Ener/Ener4b.bmp");
        Ener.special[0] = IMG_Load("Personnages/Ener/Ener5.bmp");
        Ener.special[1] = IMG_Load("Personnages/Ener/Ener6.bmp");
        Ener.special2[0] = IMG_Load("Personnages/Ener/Ener5b.bmp");
        Ener.special2[1] = IMG_Load("Personnages/Ener/Ener6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Ener", couleurBlanche);
        *J = Ener;
    }

    if(*perso == SHANKS)
    {
        Shanks.mort = IMG_Load("Personnages/Shanks/Shanks0.bmp");
        Shanks.mort2 = IMG_Load("Personnages/Shanks/Shanks0b.bmp");
        Shanks.normal = IMG_Load("Personnages/Shanks/Shanks1.bmp");
        Shanks.normal2 = IMG_Load("Personnages/Shanks/Shanks1b.bmp");
        Shanks.deplacement = IMG_Load("Personnages/Shanks/Shanks2.bmp");
        Shanks.deplacement2 = IMG_Load("Personnages/Shanks/Shanks2b.bmp");
        Shanks.attaque = IMG_Load("Personnages/Shanks/Shanks3.bmp");
        Shanks.attaque2 = IMG_Load("Personnages/Shanks/Shanks3b.bmp");
        Shanks.defense = IMG_Load("Personnages/Shanks/Shanks4.bmp");
        Shanks.defense2 = IMG_Load("Personnages/Shanks/Shanks4b.bmp");
        Shanks.special[0] = IMG_Load("Personnages/Shanks/Shanks5.bmp");
        Shanks.special[1] = IMG_Load("Personnages/Shanks/Shanks6.bmp");
        Shanks.special2[0] = IMG_Load("Personnages/Shanks/Shanks5b.bmp");
        Shanks.special2[1] = IMG_Load("Personnages/Shanks/Shanks6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Shanks", couleurBlanche);
        *J = Shanks;
    }

    if(*perso == RAYLLEIGH)
    {
        Raylleigh.mort = IMG_Load("Personnages/Raylleigh/Raylleigh0.bmp");
        Raylleigh.mort2 = IMG_Load("Personnages/Raylleigh/Raylleigh0b.bmp");
        Raylleigh.normal = IMG_Load("Personnages/Raylleigh/Raylleigh1.bmp");
        Raylleigh.normal2 = IMG_Load("Personnages/Raylleigh/Raylleigh1b.bmp");
        Raylleigh.deplacement = IMG_Load("Personnages/Raylleigh/Raylleigh2.bmp");
        Raylleigh.deplacement2 = IMG_Load("Personnages/Raylleigh/Raylleigh2b.bmp");
        Raylleigh.attaque = IMG_Load("Personnages/Raylleigh/Raylleigh3.bmp");
        Raylleigh.attaque2 = IMG_Load("Personnages/Raylleigh/Raylleigh3b.bmp");
        Raylleigh.defense = IMG_Load("Personnages/Raylleigh/Raylleigh4.bmp");
        Raylleigh.defense2 = IMG_Load("Personnages/Raylleigh/Raylleigh4b.bmp");
        Raylleigh.special[0] = IMG_Load("Personnages/Raylleigh/Raylleigh5.bmp");
        Raylleigh.special[1] = IMG_Load("Personnages/Raylleigh/Raylleigh6.bmp");
        Raylleigh.special[2] = IMG_Load("Personnages/Raylleigh/Raylleigh7.bmp");
        Raylleigh.special[3] = IMG_Load("Personnages/Raylleigh/Raylleigh8.bmp");
        Raylleigh.special2[0] = IMG_Load("Personnages/Raylleigh/Raylleigh5b.bmp");
        Raylleigh.special2[1] = IMG_Load("Personnages/Raylleigh/Raylleigh6b.bmp");
        Raylleigh.special2[2] = IMG_Load("Personnages/Raylleigh/Raylleigh7b.bmp");
        Raylleigh.special2[3] = IMG_Load("Personnages/Raylleigh/Raylleigh8b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Raylleigh", couleurBlanche);
        *J = Raylleigh;
    }

    if(*perso == BARBE_BLANCHE)
    {
        BarbeBlanche.mort = IMG_Load("Personnages/Barbe blanche/BarbeBlanche0.bmp");
        BarbeBlanche.mort2 = IMG_Load("Personnages/Barbe blanche/BarbeBlanche0b.bmp");
        BarbeBlanche.normal = IMG_Load("Personnages/Barbe blanche/BarbeBlanche1.bmp");
        BarbeBlanche.normal2 = IMG_Load("Personnages/Barbe blanche/BarbeBlanche1b.bmp");
        BarbeBlanche.deplacement = IMG_Load("Personnages/Barbe blanche/BarbeBlanche2.bmp");
        BarbeBlanche.deplacement2 = IMG_Load("Personnages/Barbe blanche/BarbeBlanche2b.bmp");
        BarbeBlanche.attaque = IMG_Load("Personnages/Barbe blanche/BarbeBlanche3.bmp");
        BarbeBlanche.attaque2 = IMG_Load("Personnages/Barbe blanche/BarbeBlanche3b.bmp");
        BarbeBlanche.defense = IMG_Load("Personnages/Barbe blanche/BarbeBlanche4.bmp");
        BarbeBlanche.defense2 = IMG_Load("Personnages/Barbe blanche/BarbeBlanche4b.bmp");
        BarbeBlanche.special[0] = IMG_Load("Personnages/Barbe blanche/BarbeBlanche5.bmp");
        BarbeBlanche.special[1] = IMG_Load("Personnages/Barbe blanche/BarbeBlanche6.bmp");
        BarbeBlanche.special2[0] = IMG_Load("Personnages/Barbe blanche/BarbeBlanche5b.bmp");
        BarbeBlanche.special2[1] = IMG_Load("Personnages/Barbe blanche/BarbeBlanche6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Barbe Blanche", couleurBlanche);
        *J = BarbeBlanche;
    }

    if(*perso == BARBE_NOIRE)
    {
        BarbeNoire.mort = IMG_Load("Personnages/Barbe noire/BarbeNoire0.bmp");
        BarbeNoire.mort2 = IMG_Load("Personnages/Barbe noire/BarbeNoire0b.bmp");
        BarbeNoire.normal = IMG_Load("Personnages/Barbe noire/BarbeNoire1.bmp");
        BarbeNoire.normal2 = IMG_Load("Personnages/Barbe noire/BarbeNoire1b.bmp");
        BarbeNoire.deplacement = IMG_Load("Personnages/Barbe noire/BarbeNoire2.bmp");
        BarbeNoire.deplacement2 = IMG_Load("Personnages/Barbe noire/BarbeNoire2b.bmp");
        BarbeNoire.attaque = IMG_Load("Personnages/Barbe noire/BarbeNoire3.bmp");
        BarbeNoire.attaque2 = IMG_Load("Personnages/Barbe noire/BarbeNoire3b.bmp");
        BarbeNoire.defense = IMG_Load("Personnages/Barbe noire/BarbeNoire4.bmp");
        BarbeNoire.defense2 = IMG_Load("Personnages/Barbe noire/BarbeNoire4b.bmp");
        BarbeNoire.special[0] = IMG_Load("Personnages/Barbe noire/BarbeNoire5.bmp");
        BarbeNoire.special[1] = IMG_Load("Personnages/Barbe noire/BarbeNoire6.bmp");
        BarbeNoire.special2[0] = IMG_Load("Personnages/Barbe noire/BarbeNoire5b.bmp");
        BarbeNoire.special2[1] = IMG_Load("Personnages/Barbe noire/BarbeNoire6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Barbe Noire", couleurBlanche);
        *J = BarbeNoire;
    }

    if(*perso == SABO)
    {
        Sabo.mort = IMG_Load("Personnages/Sabo/Sabo0.bmp");
        Sabo.mort2 = IMG_Load("Personnages/Sabo/Sabo0b.bmp");
        Sabo.normal = IMG_Load("Personnages/Sabo/Sabo1.bmp");
        Sabo.normal2 = IMG_Load("Personnages/Sabo/Sabo1b.bmp");
        Sabo.deplacement = IMG_Load("Personnages/Sabo/Sabo2.bmp");
        Sabo.deplacement2 = IMG_Load("Personnages/Sabo/Sabo2b.bmp");
        Sabo.attaque = IMG_Load("Personnages/Sabo/Sabo3.bmp");
        Sabo.attaque2 = IMG_Load("Personnages/Sabo/Sabo3b.bmp");
        Sabo.defense = IMG_Load("Personnages/Sabo/Sabo4.bmp");
        Sabo.defense2 = IMG_Load("Personnages/Sabo/Sabo4b.bmp");
        Sabo.special[0] = IMG_Load("Personnages/Sabo/Sabo5.bmp");
        Sabo.special[1] = IMG_Load("Personnages/Sabo/Sabo6.bmp");
        Sabo.special[2] = IMG_Load("Personnages/Sabo/Sabo7.bmp");
        Sabo.special2[0] = IMG_Load("Personnages/Sabo/Sabo5b.bmp");
        Sabo.special2[1] = IMG_Load("Personnages/Sabo/Sabo6b.bmp");
        Sabo.special2[2] = IMG_Load("Personnages/Sabo/Sabo7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Sabo", couleurBlanche);
        *J = Sabo;
    }

    if(*perso == GARP)
    {
        Garp.mort = IMG_Load("Personnages/Garp/Garp0.bmp");
        Garp.mort2 = IMG_Load("Personnages/Garp/Garp0b.bmp");
        Garp.normal = IMG_Load("Personnages/Garp/Garp1.bmp");
        Garp.normal2 = IMG_Load("Personnages/Garp/Garp1b.bmp");
        Garp.deplacement = IMG_Load("Personnages/Garp/Garp2.bmp");
        Garp.deplacement2 = IMG_Load("Personnages/Garp/Garp2b.bmp");
        Garp.attaque = IMG_Load("Personnages/Garp/Garp3.bmp");
        Garp.attaque2 = IMG_Load("Personnages/Garp/Garp3b.bmp");
        Garp.defense = IMG_Load("Personnages/Garp/Garp4.bmp");
        Garp.defense2 = IMG_Load("Personnages/Garp/Garp4b.bmp");
        Garp.special[0] = IMG_Load("Personnages/Garp/Garp5.bmp");
        Garp.special[1] = IMG_Load("Personnages/Garp/Garp6.bmp");
        Garp.special[2] = IMG_Load("Personnages/Garp/Garp7.bmp");
        Garp.special2[0] = IMG_Load("Personnages/Garp/Garp5b.bmp");
        Garp.special2[1] = IMG_Load("Personnages/Garp/Garp6b.bmp");
        Garp.special2[2] = IMG_Load("Personnages/Garp/Garp7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Garp", couleurBlanche);
        *J = Garp;
    }

    if(*perso == SMOKER)
    {
        Smoker.mort = IMG_Load("Personnages/Smoker/Smoker0.bmp");
        Smoker.mort2 = IMG_Load("Personnages/Smoker/Smoker0b.bmp");
        Smoker.normal = IMG_Load("Personnages/Smoker/Smoker1.bmp");
        Smoker.normal2 = IMG_Load("Personnages/Smoker/Smoker1b.bmp");
        Smoker.deplacement = IMG_Load("Personnages/Smoker/Smoker2.bmp");
        Smoker.deplacement2 = IMG_Load("Personnages/Smoker/Smoker2b.bmp");
        Smoker.attaque = IMG_Load("Personnages/Smoker/Smoker3.bmp");
        Smoker.attaque2 = IMG_Load("Personnages/Smoker/Smoker3b.bmp");
        Smoker.defense = IMG_Load("Personnages/Smoker/Smoker4.bmp");
        Smoker.defense2 = IMG_Load("Personnages/Smoker/Smoker4b.bmp");
        Smoker.special[0] = IMG_Load("Personnages/Smoker/Smoker5.bmp");
        Smoker.special[1] = IMG_Load("Personnages/Smoker/Smoker6.bmp");
        Smoker.special[2] = IMG_Load("Personnages/Smoker/Smoker7.bmp");
        Smoker.special2[0] = IMG_Load("Personnages/Smoker/Smoker5b.bmp");
        Smoker.special2[1] = IMG_Load("Personnages/Smoker/Smoker6b.bmp");
        Smoker.special2[2] = IMG_Load("Personnages/Smoker/Smoker7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Smoker", couleurBlanche);
        *J = Smoker;
    }

    if(*perso == T_BONE)
    {
        TBone.mort = IMG_Load("Personnages/TBone/TBone0.bmp");
        TBone.mort2 = IMG_Load("Personnages/TBone/TBone0b.bmp");
        TBone.normal = IMG_Load("Personnages/TBone/TBone1.bmp");
        TBone.normal2 = IMG_Load("Personnages/TBone/TBone1b.bmp");
        TBone.deplacement = IMG_Load("Personnages/TBone/TBone2.bmp");
        TBone.deplacement2 = IMG_Load("Personnages/TBone/TBone2b.bmp");
        TBone.attaque = IMG_Load("Personnages/TBone/TBone3.bmp");
        TBone.attaque2 = IMG_Load("Personnages/TBone/TBone3b.bmp");
        TBone.defense = IMG_Load("Personnages/TBone/TBone4.bmp");
        TBone.defense2 = IMG_Load("Personnages/TBone/TBone4b.bmp");
        TBone.special[0] = IMG_Load("Personnages/TBone/TBone5.bmp");
        TBone.special[1] = IMG_Load("Personnages/TBone/TBone6.bmp");
        TBone.special[2] = IMG_Load("Personnages/TBone/TBone7.bmp");
        TBone.special2[0] = IMG_Load("Personnages/TBone/TBone5b.bmp");
        TBone.special2[1] = IMG_Load("Personnages/TBone/TBone6b.bmp");
        TBone.special2[2] = IMG_Load("Personnages/TBone/TBone7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "TBone", couleurBlanche);
        *J = TBone;
    }

    if(*perso == RYUMA)
    {
        Ryuma.mort = IMG_Load("Personnages/Ryuma/Ryuma0.bmp");
        Ryuma.mort2 = IMG_Load("Personnages/Ryuma/Ryuma0b.bmp");
        Ryuma.normal = IMG_Load("Personnages/Ryuma/Ryuma1.bmp");
        Ryuma.normal2 = IMG_Load("Personnages/Ryuma/Ryuma1b.bmp");
        Ryuma.deplacement = IMG_Load("Personnages/Ryuma/Ryuma2.bmp");
        Ryuma.deplacement2 = IMG_Load("Personnages/Ryuma/Ryuma2b.bmp");
        Ryuma.attaque = IMG_Load("Personnages/Ryuma/Ryuma3.bmp");
        Ryuma.attaque2 = IMG_Load("Personnages/Ryuma/Ryuma3b.bmp");
        Ryuma.defense = IMG_Load("Personnages/Ryuma/Ryuma4.bmp");
        Ryuma.defense2 = IMG_Load("Personnages/Ryuma/Ryuma4b.bmp");
        Ryuma.special[0] = IMG_Load("Personnages/Ryuma/Ryuma5.bmp");
        Ryuma.special[1] = IMG_Load("Personnages/Ryuma/Ryuma6.bmp");
        Ryuma.special[2] = IMG_Load("Personnages/Ryuma/Ryuma7.bmp");
        Ryuma.special2[0] = IMG_Load("Personnages/Ryuma/Ryuma5b.bmp");
        Ryuma.special2[1] = IMG_Load("Personnages/Ryuma/Ryuma6b.bmp");
        Ryuma.special2[2] = IMG_Load("Personnages/Ryuma/Ryuma7b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Ryuma", couleurBlanche);
        *J = Ryuma;
    }

    if(*perso == BARTOLOMEO)
    {
        Bartolomeo.mort = IMG_Load("Personnages/Bartolomeo/Bartolomeo0.bmp");
        Bartolomeo.mort2 = IMG_Load("Personnages/Bartolomeo/Bartolomeo0b.bmp");
        Bartolomeo.normal = IMG_Load("Personnages/Bartolomeo/Bartolomeo1.bmp");
        Bartolomeo.normal2 = IMG_Load("Personnages/Bartolomeo/Bartolomeo1b.bmp");
        Bartolomeo.deplacement = IMG_Load("Personnages/Bartolomeo/Bartolomeo2.bmp");
        Bartolomeo.deplacement2 = IMG_Load("Personnages/Bartolomeo/Bartolomeo2b.bmp");
        Bartolomeo.attaque = IMG_Load("Personnages/Bartolomeo/Bartolomeo3.bmp");
        Bartolomeo.attaque2 = IMG_Load("Personnages/Bartolomeo/Bartolomeo3b.bmp");
        Bartolomeo.defense = IMG_Load("Personnages/Bartolomeo/Bartolomeo4.bmp");
        Bartolomeo.defense2 = IMG_Load("Personnages/Bartolomeo/Bartolomeo4b.bmp");
        Bartolomeo.special[0] = IMG_Load("Personnages/Bartolomeo/Bartolomeo5.bmp");
        Bartolomeo.special[1] = IMG_Load("Personnages/Bartolomeo/Bartolomeo6.bmp");
        Bartolomeo.special2[0] = IMG_Load("Personnages/Bartolomeo/Bartolomeo5b.bmp");
        Bartolomeo.special2[1] = IMG_Load("Personnages/Bartolomeo/Bartolomeo6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Bartolomeo", couleurBlanche);
        *J = Bartolomeo;
    }

    if(*perso == LUCCI)
    {
        Lucci.mort = IMG_Load("Personnages/Lucci/Lucci0.bmp");
        Lucci.mort2 = IMG_Load("Personnages/Lucci/Lucci0b.bmp");
        Lucci.normal = IMG_Load("Personnages/Lucci/Lucci1.bmp");
        Lucci.normal2 = IMG_Load("Personnages/Lucci/Lucci1b.bmp");
        Lucci.deplacement = IMG_Load("Personnages/Lucci/Lucci2.bmp");
        Lucci.deplacement2 = IMG_Load("Personnages/Lucci/Lucci2b.bmp");
        Lucci.attaque = IMG_Load("Personnages/Lucci/Lucci3.bmp");
        Lucci.attaque2 = IMG_Load("Personnages/Lucci/Lucci3b.bmp");
        Lucci.defense = IMG_Load("Personnages/Lucci/Lucci4.bmp");
        Lucci.defense2 = IMG_Load("Personnages/Lucci/Lucci4b.bmp");
        Lucci.special[0] = IMG_Load("Personnages/Lucci/Lucci5.bmp");
        Lucci.special[1] = IMG_Load("Personnages/Lucci/Lucci6.bmp");
        Lucci.special2[0] = IMG_Load("Personnages/Lucci/Lucci5b.bmp");
        Lucci.special2[1] = IMG_Load("Personnages/Lucci/Lucci6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Lucci", couleurBlanche);
        *J = Lucci;
    }

    if(*perso == CESAR)
    {
        Cesar.mort = IMG_Load("Personnages/Cesar/Cesar0.bmp");
        Cesar.mort2 = IMG_Load("Personnages/Cesar/Cesar0b.bmp");
        Cesar.normal = IMG_Load("Personnages/Cesar/Cesar1.bmp");
        Cesar.normal2 = IMG_Load("Personnages/Cesar/Cesar1b.bmp");
        Cesar.deplacement = IMG_Load("Personnages/Cesar/Cesar2.bmp");
        Cesar.deplacement2 = IMG_Load("Personnages/Cesar/Cesar2b.bmp");
        Cesar.attaque = IMG_Load("Personnages/Cesar/Cesar3.bmp");
        Cesar.attaque2 = IMG_Load("Personnages/Cesar/Cesar3b.bmp");
        Cesar.defense = IMG_Load("Personnages/Cesar/Cesar4.bmp");
        Cesar.defense2 = IMG_Load("Personnages/Cesar/Cesar4b.bmp");
        Cesar.special[0] = IMG_Load("Personnages/Cesar/Cesar5.bmp");
        Cesar.special[1] = IMG_Load("Personnages/Cesar/Cesar6.bmp");
        Cesar.special2[0] = IMG_Load("Personnages/Cesar/Cesar5b.bmp");
        Cesar.special2[1] = IMG_Load("Personnages/Cesar/Cesar6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Cesar", couleurBlanche);
        *J = Cesar;
    }

    if(*perso == HODY)
    {
        Hody.mort = IMG_Load("Personnages/Hody/Hody0.bmp");
        Hody.mort2 = IMG_Load("Personnages/Hody/Hody0b.bmp");
        Hody.normal = IMG_Load("Personnages/Hody/Hody1.bmp");
        Hody.normal2 = IMG_Load("Personnages/Hody/Hody1b.bmp");
        Hody.deplacement = IMG_Load("Personnages/Hody/Hody2.bmp");
        Hody.deplacement2 = IMG_Load("Personnages/Hody/Hody2b.bmp");
        Hody.attaque = IMG_Load("Personnages/Hody/Hody3.bmp");
        Hody.attaque2 = IMG_Load("Personnages/Hody/Hody3b.bmp");
        Hody.defense = IMG_Load("Personnages/Hody/Hody4.bmp");
        Hody.defense2 = IMG_Load("Personnages/Hody/Hody4b.bmp");
        Hody.special[0] = IMG_Load("Personnages/Hody/Hody5.bmp");
        Hody.special[1] = IMG_Load("Personnages/Hody/Hody6.bmp");
        Hody.special[2] = IMG_Load("Personnages/Hody/Hody7.bmp");
        Hody.special[3] = IMG_Load("Personnages/Hody/Hody8.bmp");
        Hody.special2[0] = IMG_Load("Personnages/Hody/Hody5b.bmp");
        Hody.special2[1] = IMG_Load("Personnages/Hody/Hody6b.bmp");
        Hody.special2[2] = IMG_Load("Personnages/Hody/Hody7b.bmp");
        Hody.special2[3] = IMG_Load("Personnages/Hody/Hody8b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Hody", couleurBlanche);
        *J = Hody;
    }

    if(*perso == BAGGY)
    {
        Baggy.mort = IMG_Load("Personnages/Baggy/Baggy0.bmp");
        Baggy.mort2 = IMG_Load("Personnages/Baggy/Baggy0b.bmp");
        Baggy.normal = IMG_Load("Personnages/Baggy/Baggy1.bmp");
        Baggy.normal2 = IMG_Load("Personnages/Baggy/Baggy1b.bmp");
        Baggy.deplacement = IMG_Load("Personnages/Baggy/Baggy2.bmp");
        Baggy.deplacement2 = IMG_Load("Personnages/Baggy/Baggy2b.bmp");
        Baggy.attaque = IMG_Load("Personnages/Baggy/Baggy3.bmp");
        Baggy.attaque2 = IMG_Load("Personnages/Baggy/Baggy3b.bmp");
        Baggy.defense = IMG_Load("Personnages/Baggy/Baggy4.bmp");
        Baggy.defense2 = IMG_Load("Personnages/Baggy/Baggy4b.bmp");
        Baggy.special[0] = IMG_Load("Personnages/Baggy/Baggy5.bmp");
        Baggy.special[1] = IMG_Load("Personnages/Baggy/Baggy6.bmp");
        Baggy.special2[0] = IMG_Load("Personnages/Baggy/Baggy5b.bmp");
        Baggy.special2[1] = IMG_Load("Personnages/Baggy/Baggy6b.bmp");

        *nom=TTF_RenderText_Blended(policeNom, "Baggy", couleurBlanche);
        *J = Baggy;
    }

    TTF_CloseFont(policeNom);

    return *J;
}
