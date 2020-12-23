#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <string.h>
#include <windows.h>
#include <mysql.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <math.h>
#include <SDL_mixer.h>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 700

enum {FOND,CHARACTER,PLAY,ITEM,STATS_CHAR,STATS};
enum {AMU,CEINTURE,CAPE,CHARAC,COIFFE,ANNEAU,BOTTES,ITEM1,ITEM2,ITEM3,ITEM4,ITEM5,ITEM6,ITEM7,ITEM8};
enum {BAS,HAUT,GAUCHE,DROITE};




typedef struct {
    SDL_Texture *texture;
    SDL_Rect pos;
    SDL_Texture *pave;
    
} new_texture;

typedef struct {
    SDL_Rect rect;
    int state;
} rect_struct;

typedef struct {
    int pdv;
    int pdv_max;
    int pa;
    int po;
    int pm;
    int attack;
    int defense;
    SDL_Rect pos;
} character;

typedef struct {
    int pdv;
    int pa;
    int po;
    int pm;
    int attack;
    int defense;
    SDL_Rect pos;
} monster;

typedef struct {
    char *name[50];
    int pa;
    int po;
    int value;
    SDL_Texture *texture;
    SDL_Rect rect;
} spell;

int acceuil(SDL_Window * window, SDL_Surface * icon, SDL_Surface * menu, SDL_Texture * texture, SDL_Renderer * renderer,SDL_Rect * positionMenu, SDL_Rect * positionClic, SDL_Rect * positionText, Mix_Music * wave,SDL_Event event);
//void move_up(new_texture * screen_two,SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over,new_texture * blood,new_texture * hero_life,new_texture * js_life);
void move_down(new_texture * screen_two,SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over);
void move_right(new_texture * screen_two,SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over);
void move_left(new_texture * screen_two,SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over);
void reset_map_chara(SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over);
void attack_hero_shuriken(SDL_Renderer* renderer, character * js, character * hero, spell *spell, new_texture * screen_two, new_texture * game_over, rect_struct map_rect[][14], new_texture * perso, new_texture * monstre);
void attack_js_morsure(SDL_Renderer* renderer, character * js, character * hero, spell *spell, new_texture * screen_two, new_texture * game_over, rect_struct map_rect[][14], new_texture * perso, new_texture * monstre);
void attack_js_meteor(SDL_Renderer* renderer, character * js, character * hero, spell *spell, new_texture * screen_two, new_texture * game_over, rect_struct map_rect[][14], new_texture * perso, new_texture * monstre);
void test ();
void SDL_ExitWithError(const char *message);
void dessine_grille(SDL_Renderer* renderer, int width, int height);
void redessine_map(rect_struct map_rect[][14],SDL_Renderer* renderer,new_texture * game_over);
void move_up(new_texture * screen_two, SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over);
void blood(character * random, new_texture * blood,SDL_Renderer * renderer, int which );

void play (SDL_Window *ecran);
//to define the path to the music
#define MUSIC_MENU_PATH "music_menu.wav"

#endif


 /* for (int time = 0; time < 5; time++)
                        {
                            if (time < 4 )
                            {
                            heal.rect.y = my_hero.pos.y - 50;
                            heal.rect.x = my_hero.pos.x;
                            SDL_RenderCopy(renderer, heal.texture, NULL, &heal.rect);
                            }*/


