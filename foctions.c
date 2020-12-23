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


void test ()
{
    printf("salut");
     
}

void SDL_ExitWithError(const char *message)
{
    printf("nopeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");
    SDL_Log("erreur : %s > %s\n", message, SDL_GetError());
    SDL_Delay(5000);
    
}

void dessine_grille(SDL_Renderer* renderer, int width, int height)
{
int x1 = 0;
int y1 = 0;
int x2 = 0;
int y2 = height;

while ( x1 <= width)
	{ 
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	x1 += 50;
	x2 += 50;
	}
x1 = 0; 
x2 = width; 
y2 = 0;

while ( y1 <= height)
	{ 
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	y1 += 50;
	y2 += 50;
	}
}

/*int alea()
{
int nombre = 0;
srand(time(NULL));
nombre = (float)rand() / (float)RAND_MAX;
} */


void attack_js_meteor(SDL_Renderer* renderer, character *js, character  *hero, spell *spell, new_texture * screen_two, new_texture * game_over, rect_struct map_rect[][14], new_texture * perso, new_texture * monstre)
{
js->pa -= spell->pa;
hero->pdv -= spell->value;
    for (int time = 0; time < 5; time++)
    {
			    
                            if (time < 4 && time % 2 == 0 )
                            {
                            spell->rect.y = hero->pos.y - 50;
                            spell->rect.x = hero->pos.x;
			    	if ( time == 2)
				{
				spell->rect.y = hero->pos.y;
				}
			    dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
			    redessine_map(map_rect,renderer,game_over);
			    SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js->pos);
			    SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
                            SDL_RenderCopy(renderer, spell->texture, NULL, &spell->rect);
			    SDL_RenderPresent(renderer);	    
			    SDL_Delay(250);
                            }
                            else
                            {
                            spell->rect.y = hero->pos.y - 50;
                            spell->rect.x = hero->pos.x;
                            SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, &spell->rect);
			    SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
                            }
			    
			    printf(" pv hero : %d " , hero->pdv);

	SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, &spell->rect);
	SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
        redessine_map(map_rect,renderer,game_over);
        dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
        SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js->pos);                   
        SDL_RenderPresent(renderer);
	SDL_RenderClear;
    }
}

void attack_js_morsure(SDL_Renderer* renderer, character *js, character  *hero, spell *spell, new_texture * screen_two, new_texture * game_over, rect_struct map_rect[][14], new_texture * perso, new_texture * monstre)
{
js->pa -= spell->pa;
hero->pdv -= spell->value;
    for (int time = 0; time < 5; time++)
    {
			    
                            if (time < 4 && time % 2 == 0 )
                            {
                            spell->rect.y = hero->pos.y - 50;
                            spell->rect.x = hero->pos.x;
			    	if ( time == 2)
				{
				spell->rect.y = hero->pos.y;
				}
			    dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
			    redessine_map(map_rect,renderer,game_over);
			    SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js->pos);
			    SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
                            SDL_RenderCopy(renderer, spell->texture, NULL, &spell->rect);
			    SDL_RenderPresent(renderer);	    
			    SDL_Delay(250);
                            }
                            else
                            {
                            spell->rect.y = hero->pos.y - 50;
                            spell->rect.x = hero->pos.x;
                            SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, &spell->rect);
			    SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
                            }
			   
			    printf(" pv hero : %d " , hero->pdv);

	SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, &spell->rect);
	SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
        redessine_map(map_rect,renderer,game_over);
        dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
        SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js->pos);                   
        SDL_RenderPresent(renderer);
	SDL_RenderClear;
    }
}

void redessine_map(rect_struct map_rect[][14],SDL_Renderer* renderer,new_texture * game_over)
{

for (int map_x = 0 ; map_x < 24 ; map_x++)
                            {
                                for (int map_y = 0 ; map_y < 14 ; map_y++)
                                {
                                if(map_rect[map_x][map_y].state == 1)
                                    {

                                        SDL_RenderCopy(renderer, game_over->texture, NULL, &map_rect[map_x][map_y].rect);
                                    }
                                }
                            }
}

void attack_hero_shuriken(SDL_Renderer* renderer, character *js, character  *hero, spell *spell, new_texture * screen_two, new_texture * game_over, rect_struct map_rect[][14], new_texture * perso, new_texture * monstre)
{

int test_attack_x_monster = 0;
int test_attack_y_monster = 0;
int test_attack_x_hero = 0;
int test_attack_y_hero = 0;
int test_attack_res = 0;
test_attack_x_monster = js->pos.x / 50 ;
test_attack_y_monster = js->pos.y / 50 ;
test_attack_x_hero = hero->pos.x / 50;
test_attack_y_hero = hero->pos.y / 50;
test_attack_res = abs(test_attack_x_monster - test_attack_x_hero) + abs(test_attack_y_monster - test_attack_y_hero);
if (test_attack_res <= spell->po)
{
    js->pdv -= spell->value;
    hero->pa -= spell->pa;
        for (int time = 0; time < 5; time++)
        {
    			  
                                if (time < 4 && time % 2 == 0 )
                                {

                                    spell->rect.x = js->pos.x - 50;
                                    spell->rect.y = js->pos.y;
                			    	if ( time == 2)
                        			{
                        				spell->rect.x = js->pos.x;
                        			}
                        		    dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
                        			redessine_map(map_rect,renderer,game_over);
                        			SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js->pos);
                        			SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
                                    SDL_RenderCopy(renderer, spell->texture, NULL, &spell->rect);
                        			SDL_RenderPresent(renderer);	    
                        			SDL_Delay(250);
                                    }
                                else
                                {
                                spell->rect.x = js->pos.x - 50;
                                spell->rect.y = js->pos.y;
                                SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, &spell->rect);
    			                SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
                                }
    			    
    			    printf(" pv js : %d " , js->pdv);

    	SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, &spell->rect);
    	SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
            redessine_map(map_rect,renderer,game_over);
            dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
            SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js->pos);                   
            SDL_RenderPresent(renderer);
    	SDL_RenderClear;
        }
    }
}
/*void blood(character * random, new_texture * blood,SDL_Renderer * renderer, int which )
{
    if ( which == 1 )
    {
        blood->pos.x = 351;
        blood->pos.y = 0;
        blood->pos.w = (389 * (random->pdv / random->pdv_max)) ;
        blood->pos.h = 50 ;
    }
    else
    {
        blood->pos.x = 221;
        blood->pos.y = 550;
        blood->pos.w = (202 * (random->pdv / random->pdv_max)) ;
        blood->pos.h = 150 ;
    }
    SDL_RenderCopy(renderer, blood->texture, NULL, &blood->pos);
}*/

void reset_map_chara(SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over)
{

    redessine_map(map_rect,renderer,game_over);
    dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
    SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js->pos);
    
    SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
    SDL_RenderPresent(renderer);
    SDL_Delay(250);
}

void move_left(new_texture * screen_two,SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over)
{
SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, NULL);
dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
map_rect[hero->pos.x / 50][hero->pos.y / 50].state = 0;
printf("vous avez appuyer sur Z");
if(map_rect[(hero->pos.x - 50) / 50][hero->pos.y / 50].state == 0 && hero->pos.x - 50 >= 0  )
{
    hero->pos.x = hero->pos.x - 50;
    redessine_map(map_rect,renderer,game_over);
    hero->pm --;
    SDL_RenderCopy(renderer, monstre[GAUCHE].texture, NULL, &js->pos);
    map_rect[hero->pos.x / 50][hero->pos.y / 50].state = 1;
    SDL_RenderCopy(renderer, perso[GAUCHE].texture, NULL, &hero->pos);
    SDL_RenderPresent(renderer);
}
}

void move_right(new_texture * screen_two,SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over)
{
SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, NULL);
dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
map_rect[hero->pos.x / 50][hero->pos.y / 50].state = 0;
printf("vous avez appuyer sur Z");
if(map_rect[(hero->pos.x + 50) / 50][hero->pos.y / 50].state == 0 && hero->pos.x + 50 < 1200  )
{
    hero->pos.x = hero->pos.x + 50;
    redessine_map(map_rect,renderer,game_over);
    hero->pm --;
    SDL_RenderCopy(renderer, monstre[DROITE].texture, NULL, &js->pos);
    map_rect[hero->pos.x / 50][hero->pos.y / 50].state = 1;
    SDL_RenderCopy(renderer, perso[DROITE].texture, NULL, &hero->pos);
    SDL_RenderPresent(renderer);
}
}

void move_up(new_texture * screen_two,SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over)
{
SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, NULL);
dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
map_rect[hero->pos.x / 50][hero->pos.y / 50].state = 0;
printf("vous avez appuyer sur Z");
if(map_rect[hero->pos.x  / 50][(hero->pos.y - 50) / 50].state == 0 && hero->pos.y - 50 >= 50  )
{
    hero->pos.y = hero->pos.y - 50;
    redessine_map(map_rect,renderer,game_over);
    hero->pm --;
    SDL_RenderCopy(renderer, monstre[HAUT].texture, NULL, &js->pos);
    map_rect[hero->pos.x / 50][hero->pos.y / 50].state = 1;
    SDL_RenderCopy(renderer, perso[HAUT].texture, NULL, &hero->pos);
    SDL_RenderPresent(renderer);
}
}

void move_down(new_texture * screen_two,SDL_Renderer* renderer, character *js, character  *hero,  rect_struct map_rect[][14], new_texture * perso, new_texture * monstre,new_texture * game_over)
{
SDL_RenderCopy(renderer, screen_two[FOND].texture, NULL, NULL);
dessine_grille(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
map_rect[hero->pos.x / 50][hero->pos.y / 50].state = 0;
printf("vous avez appuyer sur Z");
if(map_rect[hero->pos.x  / 50][(hero->pos.y + 50) / 50].state == 0 && hero->pos.y + 50 < 550  )
{
    hero->pos.y = hero->pos.y + 50;
    redessine_map(map_rect,renderer,game_over);
    hero->pm --;
    SDL_RenderCopy(renderer, monstre[BAS].texture, NULL, &js->pos);
    map_rect[hero->pos.x / 50][hero->pos.y / 50].state = 1;
    SDL_RenderCopy(renderer, perso[BAS].texture, NULL, &hero->pos);
    SDL_RenderPresent(renderer);
}
}