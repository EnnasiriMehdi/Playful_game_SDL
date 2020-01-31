#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <windows.h>
#include <mysql.h>

/* gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lmysqlclient pour compiler en ligne de cmd */
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
#define WINDOW_HEIGHT 720

void SDL_ExitWithError(const char *message);


int main(int argc, char **argv)
{

    MYSQL *sock; /*sockets*/
    MYSQL_ROW row = NULL;   /* enregistrement (requete)*/
    MYSQL_RES *res = NULL; /* resultat de la requete */

    sock = mysql_init(0);  /* initialisation de la lib mysql */

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


    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* initialisation de la SDL */

    /* SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);  | sert a mettre plusieurs parametres */
    if(SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        SDL_ExitWithError(" initialisation SDL ");

    }

    /* execution du programme */

/* CREATION DE LA FENETRE DU PROGRAMME */
    window = SDL_CreateWindow("JS Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720,0);
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

    if(SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
    {
    }


    SDL_RenderPresent(renderer);

/* GESTION EVENEMENTS */

    SDL_bool progam_launched = SDL_TRUE;

    while(progam_launched)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
              {
                  switch(event.type)
                        {
                       /* case SDL_MOUSEMOTION:
                             event.motion.x ou xrel relative = deplacement relatif par rapport au dernier emplacement de la souris
                            printf("%d / %d\n", event.motion.x, event.motion.y);
                            continue; */
                        case SDL_MOUSEBUTTONDOWN:
                            /* event.motion.x ou xrel relative = deplacement relatif par rapport au dernier emplacement de la souris */
                            printf("clic en %d / %d\n", event.button.x, event.button.y);
                            break;

                        case SDL_KEYDOWN:
                            switch(event.key.keysym.sym)
                            {
                                case SDLK_b:
                                    printf("vous avez appuyé sur b");

                                    SDL_Surface *image = NULL;
                                    SDL_Texture *texture = NULL;

                                    image = SDL_LoadBMP("like.bmp");
                                    image->w = 100;
                                    image->h = 100;
                                    if(image == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de charger l'image");
    }
                                    texture = SDL_CreateTextureFromSurface(renderer, image);
                                    SDL_FreeSurface(image);

                                    SDL_Rect rectangle;

                                    SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h);

                                    rectangle.x = 50;
                                    rectangle.y = 50;

                                    SDL_RenderCopy(renderer, texture, NULL, &rectangle);

                                    SDL_RenderPresent(renderer);


                                    SDL_Delay(5000);
                                    SDL_DestroyTexture(texture);

                                    break; /*continue permet de continue la boucle alors que break sort de la boucle */
                            }
                        case SDL_QUIT:
                            progam_launched = SDL_FALSE;
                            break;


                         }
              }












    }



    if(SDL_RenderClear(renderer)!= 0)
    {
        SDL_ExitWithError("effecement rendu failed");
    }

    SDL_Surface *image2 = NULL;
    SDL_Texture *texture2 = NULL;

    image2 = SDL_LoadBMP("exemple.bmp");

    if(image2 == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de charger l'image");
    }

/* CREATION DE LA TEXTURE */

    texture2 = SDL_CreateTextureFromSurface(renderer, image2);
    SDL_FreeSurface(image2);
    if(texture2 == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de creer la texture");
    }

/* CHARGEMENT EN MEMOIRE DE LA TEXTURE */

    SDL_Rect rectangle;

    if(SDL_QueryTexture(texture2, NULL, NULL, &rectangle.w, &rectangle.h) !=0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de charger la texture");
    }

    rectangle.x = (WINDOW_WIDTH - rectangle.w) /2;
    rectangle.y = (WINDOW_HEIGHT - rectangle.h) /2;

    if(SDL_RenderCopy(renderer, texture2, NULL, &rectangle) !=0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible d'afficher la texture");
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);

    SDL_DestroyTexture(texture2);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}


void SDL_ExitWithError(const char *message)
{
    SDL_Log("erreur : %s > %s\n", message, SDL_GetError());
    SDL_Delay(5000);
    SDL_Quit();
    exit(EXIT_FAILURE);
}
