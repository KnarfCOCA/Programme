#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>

void pause();

int main ( int argc, char** argv )
{
    int i=0, j=0, k=0, l=0;
    const int MAX = 255, MIN = 0;
    srand(time(NULL));

    SDL_Surface *ecran = NULL;

    SDL_Init( SDL_INIT_VIDEO );

    SDL_WM_SetIcon(SDL_LoadBMP("lac_en_montagne.bmp"), NULL);

    ecran = SDL_SetVideoMode(500, 300, 32, SDL_HWSURFACE);

    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Coca!", NULL);

    while(i!=256)
    {

        i = (rand() % (MAX - MIN + 1)) + MIN;
        j = (rand() % (MAX - MIN + 1)) + MIN;
        k = (rand() % (MAX - MIN + 1)) + MIN;

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, i, j, k));
        SDL_Flip(ecran);

        while(1)
        {
            l++;
        }

        l=0;

    }

    pause();

    SDL_Quit();

    return EXIT_SUCCESS;
}

void pause()
{
    int continuer = 1;

    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
