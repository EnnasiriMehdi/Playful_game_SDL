#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <string.h>
#include <windows.h>
#include <mysql.h>
#include"fonction.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <math.h>



/*
/  Projet_C
/
/  Created by Namizata Sangaré on 02/02/2020.
/  Copyright © 2020 Namizata Sangaré and Ennasiri Mehdi. All rights reserved.
*/


/* gcc src/main.c src/fonction.h src/foctions.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lmysqlclient -lSDL2_ttf pour compiler en ligne de cmd */
/* ajouter -mwindows pour lancer le pgm sans la ligne de cmd */


/* parametre possible dans SDL_CreateRenderer

SDL_RENDERER_SOFTWARE ---> utilisation du processeur (PAR DEFAUT)
SDL_RENDERER_ACCELERATED ---> acceleration materielle (utilisation de la carte graphinque)
SDL_RENDERER_PRESENTVSYNC ---> synchronisation verticale
SDL_RENDERER_TARGETTEXTURE ---> ciblage d'une texture precise

*/

/* creation de la fenetre et du rendu directement

SDL_CreateWindowAndRenderer(largeur window, hauteur window, flags creation fenetre, &fenetre, &rendu)

*/

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 700



/*void SDL_ExitWithError(const char *message);*/

/*
typedef struct {
    SDL_Texture *texture;
    int on;
} new_texture;

typedef struct {
    SDL_Rect rect;
} rect_struct;

*/
Mix_Music *wave = NULL;

int main(int argc, char **argv)
{

    int fullscreen = 0;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Texture *texture;
    SDL_Texture *message;
    SDL_Surface *menu = NULL;
    SDL_Surface *text = NULL;
    SDL_Surface *icon = IMG_Load("icon.jpg");
    if ( !icon ){
        printf("L'icon n'a pas pu être initialisé: %s\n", SDL_GetError());
    }

    SDL_Rect positionMenu, positionClic, positionText;
    SDL_Event event;
    int continuer = 1;

    //POLICE
    TTF_Font *font = NULL;
    SDL_Color colorBlack = { 0, 0, 0 }, colorWhite = { 255, 255, 255};
    TTF_Font *fontBig = NULL;

    //Init of the font
    window = SDL_CreateWindow("JS Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,0);
    if(window == NULL)
    {
        SDL_Log("erreur : fail création fenetre > %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    if ( renderer == NULL)
    {
        SDL_ExitWithError("creation rendu fail");
    }


       TTF_Init();
       font = TTF_OpenFont("DUNGRG__.TTF", 35);
       fontBig = TTF_OpenFont("DUNGRG__.TTF", 95);
       putenv("SDL_VIDEO_CENTERED=1"); //the window is centered

     //Init of the SDL


    //Init of SDL_Mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
        printf("L'API Mixer n'a pas pu être initialisé: %s\n", Mix_GetError());
        return -1;
    }
    if(TTF_Init() == -1) /* initialise la ttf */
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    if (acceuil(window,icon,menu,texture,renderer, &positionMenu, &positionClic, &positionText, wave, event) == 0)
    {
                    Mix_FreeMusic(wave);
                     SDL_FreeSurface(text);
                     SDL_FreeSurface(menu);
                     SDL_FreeSurface(icon);

                    SDL_DestroyRenderer(renderer);
                     SDL_DestroyWindow(window); //on libère la mémoire alloué
                     Mix_CloseAudio();
                     SDL_Quit(); //libère la SDL de la mémoire
                    exit (0);
    }

if (acceuil(window,icon,menu,texture,renderer, &positionMenu, &positionClic, &positionText, wave, event) == 1)
{


    MYSQL *sock; /*sockets*/
    MYSQL_ROW row = NULL;   /* enregitest();strement (requete)*/
    MYSQL_RES *res = NULL; /* resultat de la requete */

    sock = mysql_init(0);  /* initialisation de la lib mysql */
/*
    if (sock)
    {
        printf("mysql initialise !!");
    }
    else
    {
        printf("erreur");
    }

    char *host = "localhost";
    char *user = "root";
    char *password = "";
    char *namedb = "projet_c";

    if(mysql_real_connect(sock, host, user, password, namedb, 0, NULL, 0))
    {
        printf("connexion a la bdd reussi");
    }
    else
    {
        printf("connexion failed");
    }

    mysql_query(sock, "INSERT INTO question VALUES (4,'ca marche bien',0,0)");
*/
/*

    /* initialisation de la SDL */

    /* SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);  | sert a mettre plusieurs parametres */
 /*   if(SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        SDL_ExitWithError(" initialisation SDL ");

    } */

    /* execution du programme */

/* CREATION DE LA FENETRE DU PROGRAMME */




    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
    {
        SDL_ExitWithError("impossible de charger la couleur");
    }
/* ///////////////////////////////// ECRAN AVANT CBT /////////////////////////////////////////// */




    new_texture screen_two[6];
    screen_two[FOND].texture = IMG_LoadTexture(renderer,"img/fond.png");
/*

    new_texture screen_two[6];
    rect_struct screen_two_struct[6];

    new_texture life_js;
    life_js.pos.x = 0;
    life_js.pos.y = 0;
    life_js.pos.w = 1200;
    life_js.pos.h = 50;
    life_js.texture = IMG_LoadTexture(renderer,"img/life_js.png");
    new_texture life_hero;
    life_hero.pos.x = 1200;
    life_hero.pos.y = 550;
    life_hero.pos.w = 1200;
    life_hero.pos.h = 150;
    life_hero.texture = IMG_LoadTexture(renderer,"img/life_hero.png");
    new_texture blood;
    blood.texture = IMG_LoadTexture(renderer,"img/blood.png");

    screen_two[FOND].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two[CHARACTER].texture = IMG_LoadTexture(renderer,"img/bonhomme.png");
    screen_two[PLAY].texture = IMG_LoadTexture(renderer,"img/bonhomme.png");
    screen_two[ITEM].texture = IMG_LoadTexture(renderer,"img/bonhomme.png");
    screen_two[STATS_CHAR].texture = IMG_LoadTexture(renderer,"img/bonhomme.png");
    screen_two[STATS].texture = IMG_LoadTexture(renderer,"img/bonhomme.png");


    screen_two_struct[CHARACTER].rect.x = 50;
    screen_two_struct[CHARACTER].rect.y = 25;
    screen_two_struct[CHARACTER].rect.w = 400;
    screen_two_struct[CHARACTER].rect.h = 500;

    screen_two_struct[PLAY].rect.x = 125;
    screen_two_struct[PLAY].rect.y = 550;
    screen_two_struct[PLAY].rect.w = 250;
    screen_two_struct[PLAY].rect.h = 125;

    screen_two_struct[ITEM].rect.x = 510;
    screen_two_struct[ITEM].rect.y = 25;
    screen_two_struct[ITEM].rect.w = 250;
    screen_two_struct[ITEM].rect.h = 250;

    screen_two_struct[STATS_CHAR].rect.x = 800;
    screen_two_struct[STATS_CHAR].rect.y = 25;
    screen_two_struct[STATS_CHAR].rect.w = 350;
    screen_two_struct[STATS_CHAR].rect.h = 250;

    screen_two_struct[STATS].rect.x = 510;
    screen_two_struct[STATS].rect.y = 325;
    screen_two_struct[STATS].rect.w = 640;
    screen_two_struct[STATS].rect.h = 325;


    for(int test_screen_two_texture = 0; test_screen_two_texture < 6; test_screen_two_texture++ )
    {
    if(screen_two[test_screen_two_texture].texture == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de charger l'image");
    }
    }
    //texture = SDL_CreateTextureFromSurface(renderer, fond);
    //SDL_QueryTexture(texture, NULL, NULL, &rect_fond.w, &rect_fond.h);
    SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, NULL);
    SDL_RenderCopy(renderer, screen_two[CHARACTER].texture, NULL, &screen_two_struct[CHARACTER].rect);
    SDL_RenderCopy(renderer, screen_two[PLAY].texture, NULL, &screen_two_struct[PLAY].rect);
    SDL_RenderCopy(renderer, screen_two[ITEM].texture, NULL, &screen_two_struct[ITEM].rect);
    SDL_RenderCopy(renderer, screen_two[STATS_CHAR].texture, NULL, &screen_two_struct[STATS_CHAR].rect);
    SDL_RenderCopy(renderer, screen_two[STATS].texture, NULL, &screen_two_struct[STATS].rect);


    new_texture screen_two_icons[15];
    rect_struct screen_two_struct_icons[15];



    screen_two_icons[AMU].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[CEINTURE].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[CAPE].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[CHARAC].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[COIFFE].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[ANNEAU].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[BOTTES].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[ITEM1].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[ITEM2].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[ITEM3].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[ITEM4].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[ITEM5].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[ITEM6].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[ITEM7].texture = IMG_LoadTexture(renderer,"img/fond.png");
    screen_two_icons[ITEM8].texture = IMG_LoadTexture(renderer,"img/fond.png");

    screen_two_struct_icons[AMU].rect.h=80;
    screen_two_struct_icons[AMU].rect.w=80;
    screen_two_struct_icons[AMU].rect.x=65;
    screen_two_struct_icons[AMU].rect.y=45;

    screen_two_struct_icons[CEINTURE].rect.h=80;
    screen_two_struct_icons[CEINTURE].rect.w=80;
    screen_two_struct_icons[CEINTURE].rect.x=65;
    screen_two_struct_icons[CEINTURE].rect.y=135;

    screen_two_struct_icons[CAPE].rect.h=80;
    screen_two_struct_icons[CAPE].rect.w=80;
    screen_two_struct_icons[CAPE].rect.x=65;
    screen_two_struct_icons[CAPE].rect.y=225;

    screen_two_struct_icons[CHARAC].rect.h=260;
    screen_two_struct_icons[CHARAC].rect.w=180;
    screen_two_struct_icons[CHARAC].rect.x=160;
    screen_two_struct_icons[CHARAC].rect.y=45;

    screen_two_struct_icons[COIFFE].rect.h=80;
    screen_two_struct_icons[COIFFE].rect.w=80;
    screen_two_struct_icons[COIFFE].rect.x=355;
    screen_two_struct_icons[COIFFE].rect.y=45;

    screen_two_struct_icons[ANNEAU].rect.h=80;
    screen_two_struct_icons[ANNEAU].rect.w=80;
    screen_two_struct_icons[ANNEAU].rect.x=355;
    screen_two_struct_icons[ANNEAU].rect.y=135;

    screen_two_struct_icons[BOTTES].rect.h=80;
    screen_two_struct_icons[BOTTES].rect.w=80;
    screen_two_struct_icons[BOTTES].rect.x=355;
    screen_two_struct_icons[BOTTES].rect.y=225;

    screen_two_struct_icons[ITEM1].rect.h=75;
    screen_two_struct_icons[ITEM1].rect.w=75;
    screen_two_struct_icons[ITEM1].rect.x=70;
    screen_two_struct_icons[ITEM1].rect.y=345;

    screen_two_struct_icons[ITEM2].rect.h=75;
    screen_two_struct_icons[ITEM2].rect.w=75;
    screen_two_struct_icons[ITEM2].rect.x=165;
    screen_two_struct_icons[ITEM2].rect.y=345;

    screen_two_struct_icons[ITEM3].rect.h=75;
    screen_two_struct_icons[ITEM3].rect.w=75;
    screen_two_struct_icons[ITEM3].rect.x=260;
    screen_two_struct_icons[ITEM3].rect.y=345;

    screen_two_struct_icons[ITEM4].rect.h=75;
    screen_two_struct_icons[ITEM4].rect.w=75;
    screen_two_struct_icons[ITEM4].rect.x=355;
    screen_two_struct_icons[ITEM4].rect.y=345;

    screen_two_struct_icons[ITEM5].rect.h=75;
    screen_two_struct_icons[ITEM5].rect.w=75;
    screen_two_struct_icons[ITEM5].rect.x=70;
    screen_two_struct_icons[ITEM5].rect.y=430;

    screen_two_struct_icons[ITEM6].rect.h=75;
    screen_two_struct_icons[ITEM6].rect.w=75;
    screen_two_struct_icons[ITEM6].rect.x=165;
    screen_two_struct_icons[ITEM6].rect.y=430;

    screen_two_struct_icons[ITEM7].rect.h=75;
    screen_two_struct_icons[ITEM7].rect.w=75;
    screen_two_struct_icons[ITEM7].rect.x=260;
    screen_two_struct_icons[ITEM7].rect.y=430;

    screen_two_struct_icons[ITEM8].rect.h=75;
    screen_two_struct_icons[ITEM8].rect.w=75;
    screen_two_struct_icons[ITEM8].rect.x=355;
    screen_two_struct_icons[ITEM8].rect.y=430;


    SDL_RenderCopy(renderer, screen_two_icons[AMU].texture, NULL, &screen_two_struct_icons[AMU].rect);
    SDL_RenderCopy(renderer, screen_two_icons[CEINTURE].texture, NULL, &screen_two_struct_icons[CEINTURE].rect);
    SDL_RenderCopy(renderer, screen_two_icons[CAPE].texture, NULL, &screen_two_struct_icons[CAPE].rect);
    SDL_RenderCopy(renderer, screen_two_icons[CHARAC].texture, NULL, &screen_two_struct_icons[CHARAC].rect);
    SDL_RenderCopy(renderer, screen_two_icons[COIFFE].texture, NULL, &screen_two_struct_icons[COIFFE].rect);
    SDL_RenderCopy(renderer, screen_two_icons[ANNEAU].texture, NULL, &screen_two_struct_icons[ANNEAU].rect);
    SDL_RenderCopy(renderer, screen_two_icons[BOTTES].texture, NULL, &screen_two_struct_icons[BOTTES].rect);
    SDL_RenderCopy(renderer, screen_two_icons[ITEM1].texture, NULL, &screen_two_struct_icons[ITEM1].rect);
    SDL_RenderCopy(renderer, screen_two_icons[ITEM2].texture, NULL, &screen_two_struct_icons[ITEM2].rect);
    SDL_RenderCopy(renderer, screen_two_icons[ITEM3].texture, NULL, &screen_two_struct_icons[ITEM3].rect);
    SDL_RenderCopy(renderer, screen_two_icons[ITEM4].texture, NULL, &screen_two_struct_icons[ITEM4].rect);
    SDL_RenderCopy(renderer, screen_two_icons[ITEM5].texture, NULL, &screen_two_struct_icons[ITEM5].rect);
    SDL_RenderCopy(renderer, screen_two_icons[ITEM6].texture, NULL, &screen_two_struct_icons[ITEM6].rect);
    SDL_RenderCopy(renderer, screen_two_icons[ITEM7].texture, NULL, &screen_two_struct_icons[ITEM7].rect);
    SDL_RenderCopy(renderer, screen_two_icons[ITEM8].texture, NULL, &screen_two_struct_icons[ITEM8].rect);


    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

    SDL_Delay(3000); */
/* ///////////////////////////////// FIN  ECRAN AVANT CBT  /////////////////////////////////////////// */


/* ///////////////////////////////// ECRAN CBT /////////////////////////////////////////// */

new_texture perso[4];

if((perso[BAS].texture = IMG_LoadTexture(renderer, "img/perso_face.png")) == NULL)
{
    SDL_ExitWithError("le perso a pas chargé");
}
perso[HAUT].texture = IMG_LoadTexture(renderer, "img/perso_face.png");
perso[GAUCHE].texture = IMG_LoadTexture(renderer, "img/perso_face.png");
perso[DROITE].texture = IMG_LoadTexture(renderer, "img/perso_face.png");

new_texture monstre[4];

if((monstre[BAS].texture = IMG_LoadTexture(renderer, "img/monstre_face.png")) == NULL)
{
    SDL_ExitWithError("le perso a pas chargé");
}
monstre[HAUT].texture = IMG_LoadTexture(renderer, "img/monstre_face.png");
monstre[GAUCHE].texture = IMG_LoadTexture(renderer, "img/monstre_face.png");
monstre[DROITE].texture = IMG_LoadTexture(renderer, "img/monstre_face.png");


SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, NULL);
dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);

character js;             /* Parametrage du monstre */
js.pdv = 1500;
js.pdv_max = 1500;
js.pa = 15;
js.pm = 5;
js.po = 1500;
js.attack = 1500;
js.defense = 1500;
js.pos.x = 1100 ;
js.pos.y = 50 ;
js.pos.w = 50 ;
js.pos.h = 50 ;


character my_hero ;       /* Parametrage du perso */
my_hero.pdv = 1500;
my_hero.pdv_max = 1500;
my_hero.pa = 12;
my_hero.pm = 5;
my_hero.po = 1500;
my_hero.attack = 1500;
my_hero.defense = 1500;
my_hero.pos.x = 1100 ;
my_hero.pos.y = 50 ;
my_hero.pos.w = 50 ;
my_hero.pos.h = 50 ;

/* ////////////////////////////// Parametrage des sorts \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
spell heal;
heal.pa = 2;
heal.po = 0;
heal.value = 100;
heal.texture = IMG_LoadTexture(renderer,"img/coeur.png");
heal.rect.w = 50;
heal.rect.h = 50;

spell shuriken;
shuriken.pa = 3;
shuriken.po = 10;
shuriken.value = 100;
shuriken.texture = IMG_LoadTexture(renderer, "img/kunai.png");
shuriken.rect.w = 50;
shuriken.rect.h = 50;

spell slash;
slash.pa = 4;
slash.po = 2;
slash.value = 250;
slash.texture = IMG_LoadTexture(renderer, "img/slash.png");
slash.rect.w = 50;
slash.rect.h = 50;

spell meteor;
meteor.pa = 4;
meteor.po = 15;
meteor.value = 150;
meteor.texture = IMG_LoadTexture(renderer, "img/meteor.png");
meteor.rect.w = 50;
meteor.rect.h = 50;

spell morsure;
morsure.pa = 4;
morsure.po = 4;
morsure.value = 250;
morsure.texture = IMG_LoadTexture(renderer, "img/morsure.png");
morsure.rect.w = 50;
morsure.rect.h = 50;

/* ////////////////////////////// Parametrage des sorts \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
new_texture game_over;
game_over.texture = IMG_LoadTexture(renderer, "img/game_over.png");
game_over.pave =  IMG_LoadTexture(renderer, "img/sol.png");
rect_struct map_rect[24][14];

int alea_map = 0;
for(int map_x = 0; map_x < 24; map_x++)
    {
        for(int map_y = 0; map_y < 14; map_y++)
        {
            alea_map = rand()% (1+6);
            if (map_x == 22 && map_y == 1)
                {
                    js.pos.x=map_x*50;
                    js.pos.y=map_y*50;
                    map_rect[map_x][map_y].state=1;
                    SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js.pos);
                    printf(" %d / %d", js.pos.x, js.pos.y);
                    printf("salut");

                }
            else if (map_x == 2 && map_y == 12)
            {

                my_hero.pos.x=map_x*50;
                my_hero.pos.y=map_y*50;
                map_rect[map_x][map_y].state=1;
                SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &my_hero.pos);
                printf("salut");

            }
            else if(alea_map == 1 && map_x != 2 && map_y != 12 && map_x != 22 && map_y != 1)
            {

                map_rect[map_x][map_y].rect.h=50;
                map_rect[map_x][map_y].rect.w=50;
                map_rect[map_x][map_y].rect.x=map_x*50;
                map_rect[map_x][map_y].rect.y=map_y*50;
                map_rect[map_x][map_y].state=1;
                SDL_RenderCopy(renderer, game_over.texture, NULL, &map_rect[map_x][map_y].rect);
            }
            else{
                map_rect[map_x][map_y].state=0;
            }

        }
    }
SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js.pos);
SDL_RenderPresent(renderer);
SDL_RenderClear(renderer);

SDL_bool fight_launched = SDL_TRUE;
SDL_Event event_fight;

int res_monster_move_x = 0;
int res_monster_move_y = 0;
int alea_move ;
int stock_move_monster[js.pm][2];

/* SDL_Event event_click;*/
while(fight_launched)

{
    if(my_hero.pa == 0 && my_hero.pm == 0)
    {
        my_hero.pm = 5;
        my_hero.pa = 12;
        js.pa = 12;
        /* Le monstre joue */


        for(int i = 0; i < js.pm ; i ++ )
        {
            SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, NULL);
            res_monster_move_x = my_hero.pos.x - js.pos.x ;
            res_monster_move_y = my_hero.pos.y - js.pos.y ;

            if(res_monster_move_x != 0 || res_monster_move_y != 0 )
            {
                alea_move = rand() % 2 ;

                if(alea_move == 0 )
                {

                    if (map_rect[(js.pos.x + 50) / 50][js.pos.y / 50].state == 0 || map_rect[(js.pos.x - 50) / 50][js.pos.y / 50].state == 0 && (js.pos.x + 50) < 1200 && (js.pos.x - 50) >= 0   )
                    {
                        map_rect[js.pos.x / 50][js.pos.y / 50].state = 2;
                        printf(" %d \n", i);
                        stock_move_monster[i][0] = js.pos.x /50 ;
                        stock_move_monster[i][1] = js.pos.y /50 ;

                        if(res_monster_move_x > 0 && map_rect[(js.pos.x + 50) / 50][js.pos.y / 50].state == 0)
                        {
                            js.pos.x += 50;
                        }
                        else if (res_monster_move_x < 0 && map_rect[(js.pos.x - 50) / 50][js.pos.y / 50].state == 0)
                        {
                            js.pos.x -= 50;
                        }
                        else if( map_rect[js.pos.x / 50][(js.pos.y + 50) / 50].state == 0)
                        {
                            js.pos.y += 50;
                        }
                        else if ( map_rect[js.pos.x / 50][(js.pos.y  - 50) / 50].state == 0)
                        {
                            js.pos.y -= 50;
                        }
                    }
                }
                else
                {
                    if ((js.pos.y + 50) < 550 && (js.pos.y - 50) >= 100 && map_rect[js.pos.x / 50][(js.pos.y + 50)/ 50].state == 0 || map_rect[js.pos.x  / 50][(js.pos.y - 50) / 50].state == 0   )
                    {
                        (map_rect[js.pos.x / 50][js.pos.y / 50].state = 2);
                        printf(" %d \n", i);
                        stock_move_monster[i][0] = js.pos.x /50 ;
                        stock_move_monster[i][1] = js.pos.y /50 ;
                        if(res_monster_move_y > 0 && map_rect[js.pos.x / 50][(js.pos.y + 50) / 50].state == 0)
                        {
                            js.pos.y += 50;
                        }
                        else if (res_monster_move_y < 0 && map_rect[js.pos.x / 50][(js.pos.y  - 50) / 50].state == 0)
                        {
                            js.pos.y -= 50;
                        }
                        else if( map_rect[(js.pos.x + 50) / 50][js.pos.y / 50].state == 0)
                        {
                            js.pos.x += 50;
                        }
                        else if ( map_rect[(js.pos.x - 50) / 50][js.pos.y / 50].state == 0)
                        {
                            js.pos.x -= 50;
                        }

                    }
                }
                if ((abs(( my_hero.pos.x /50) - (js.pos.x /50) )+abs( (my_hero.pos.y / 50) - (js.pos.y /50)) ) <= morsure.po && js.pa >= morsure.pa )
                {
                    attack_js_morsure(renderer, &js, &my_hero, &morsure,screen_two,&game_over,map_rect, perso,monstre);
                }
                if ((abs(( my_hero.pos.x /50) - (js.pos.x /50) )+abs( (my_hero.pos.y / 50) - (js.pos.y /50)) ) <= meteor.po && js.pa >= meteor.pa )
                {
                    attack_js_meteor(renderer, &js, &my_hero, &meteor,screen_two,&game_over,map_rect, perso,monstre);
              }

                reset_map_chara(renderer, &js, &my_hero,map_rect, perso,monstre,&game_over);

            }
        }
        if ((abs(( my_hero.pos.x /50) - (js.pos.x /50) )+abs( (my_hero.pos.y / 50) - (js.pos.y /50)) ) <= morsure.po && js.pa >= morsure.pa )
                {
                    attack_js_morsure(renderer, &js, &my_hero, &morsure,screen_two,&game_over,map_rect, perso,monstre);
                }
        if ((abs(( my_hero.pos.x /50) - (js.pos.x /50) )+abs( (my_hero.pos.y / 50) - (js.pos.y /50)) ) <= meteor.po && js.pa >= meteor.pa )
        {
                    attack_js_meteor(renderer, &js, &my_hero, &meteor,screen_two,&game_over,map_rect, perso,monstre);
        }

        map_rect[js.pos.x / 50][js.pos.y / 50].state = 1;
        for (int i = 0; i < js.pm ; i ++)
        {
            map_rect[(stock_move_monster[i][0])][(stock_move_monster[i][1])].state = 0;
        }



    }
    if(my_hero.pdv <= 0 )
    {
        SDL_Texture * dead;
        dead = IMG_LoadTexture(renderer,"img/te.png");
        SDL_Rect end;
        end.x = 0;
        end.y = 0;
        end.w = 1200;
        end.h = 700;
        SDL_RenderCopy(renderer,dead,NULL,&end);
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
        SDL_RenderClear(renderer);

        fight_launched = SDL_FALSE;
    }
    if(js.pdv <= 0 )
    {
        SDL_Texture * win;
        win = IMG_LoadTexture(renderer,"img/trophy.png");
        SDL_Rect end;
        end.x = 0;
        end.y = 0;
        end.w = 1200;
        end.h = 700;
        SDL_RenderCopy(renderer,win,NULL,&end);
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
        SDL_RenderClear(renderer);
        fight_launched = SDL_FALSE;
    }

    while(SDL_WaitEvent(&event_fight))
    {
            switch(event_fight.type)
            {
            case SDL_KEYDOWN:

                    switch (event_fight.key.keysym.sym)
                    {
                    case SDLK_z:

                       if (my_hero.pm > 0 )
                        {
                        move_up(screen_two,renderer, &js, &my_hero,map_rect, perso,monstre,&game_over);
                        printf(" pm fffffffff : %d\n", my_hero.pm );
                        }

                    break;

                    case SDLK_d:

                        if (my_hero.pm > 0 )
                        {
                        move_right(screen_two,renderer, &js, &my_hero,map_rect, perso,monstre,&game_over);
                        printf(" pm fffffffff : %d\n", my_hero.pm );
                        }

                    break;

                    case SDLK_s:

                        if (my_hero.pm > 0 )
                        {
                        move_down(screen_two,renderer, &js, &my_hero,map_rect, perso,monstre,&game_over);
                        printf(" pm fffffffff : %d\n", my_hero.pm );
                        }

                    break;

                    case SDLK_q:
                        if (my_hero.pm > 0 )
                        {
                        move_left(screen_two,renderer, &js, &my_hero,map_rect, perso,monstre,&game_over);
                        printf(" pm fffffffff : %d\n", my_hero.pm );
                        }

                    break;

                    case SDLK_f:
                                        if (fullscreen == 0 )
                                        {
                                        SDL_SetWindowFullscreen( window,0); /* passer en full screen */
                                        fullscreen = 1 ;
                                        reset_map_chara(renderer, &js, &my_hero,map_rect, perso,monstre,&game_over);
                                        }
                                        else
                                        {
                                        SDL_SetWindowFullscreen( window,SDL_WINDOW_FULLSCREEN); /* passer en full screen */
                                        fullscreen = 0 ;
                                        reset_map_chara(renderer, &js, &my_hero,map_rect, perso,monstre,&game_over);
                                        }
                                        break;

                    case SDLK_h:

                        SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, NULL);

                        if ( my_hero.pa >= heal.pa)
                        {
                        printf(" %d \n", my_hero.pdv);
                        my_hero.pdv += 50;
                        if(my_hero.pdv > my_hero.pdv_max)
                        {
                            my_hero.pdv = my_hero.pdv_max;
                        }
                        printf(" %d \n", my_hero.pdv);
                         for (int time = 0; time < 5; time++)
                        {
                            if (time < 4 && time % 2 == 0 )
                            {
                            heal.rect.y = my_hero.pos.y - 50;
                            heal.rect.x = my_hero.pos.x;
                            SDL_RenderCopy(renderer, heal.texture, NULL, &heal.rect);
                            }
                            else
                            {
                            heal.rect.y = my_hero.pos.y - 50;
                            heal.rect.x = my_hero.pos.x;
                            SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, &heal.rect);
                            }

                            reset_map_chara(renderer, &js, &my_hero,map_rect, perso,monstre,&game_over);
                            /*redessine_map(map_rect,renderer,&game_over);
                        dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
                        SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js.pos);
                        SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &my_hero.pos);
                        SDL_RenderPresent(renderer);*/
                        SDL_Delay(250);
                        }}
                    break;

                    case SDLK_p:

                        my_hero.pa = 0;
                        my_hero.pm = 0;

                    break;

                    case SDLK_j:

                        SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, NULL);
                        if(my_hero.pa >= shuriken.pa)
                        {
                        attack_hero_shuriken(renderer, &js, &my_hero, &shuriken,screen_two,&game_over,map_rect, perso,monstre);
                        }

                    break;

                    case SDLK_k:

                        SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, NULL);
                        if (my_hero.pa >= slash.pa)
                        {
                        attack_hero_shuriken(renderer, &js, &my_hero, &slash,screen_two,&game_over,map_rect, perso,monstre);
                        }
                     break;

                    }break;

                break;

                case SDL_QUIT:
                    fight_launched = SDL_FALSE;
                break;
/*
            case :
                break;

            case :
                break;

            case :
                break;

            case :
                break; */
            }break;

    }
}}
/* ///////////////////////////////// FIN ECRAN CBT /////////////////////////////////////////// */
}



