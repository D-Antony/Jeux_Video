#include "prototypes.h"

Text texte;

void initText(void)
{
    texte.affi_text = loadText("./include/police/comic.ttf");
}

SDL_Texture* loadText(char* name)
{
    SDL_Surface* loadedText = NULL;
    SDL_Texture* text_affi = NULL;
    TTF_Font* font = NULL;
    font = TTF_OpenFont(name, 20);

    SDL_Color TextColor; // gestion de la couleur de notre texte
    TextColor.r = 255;
    TextColor.g = 255;
    TextColor.b = 255;

    if (font != NULL) // si la font a pu etre charge
    {
        SDL_Surface* loadedText = TTF_RenderText_Solid(font, "Les touches : Q / D / A / Shift(s) / Espace !", TextColor);

        SDL_Rect DstRect;
        DstRect.x = 42;
        DstRect.y = 50;
        DstRect.w = loadedText->w;
        DstRect.h = loadedText->h;

        text_affi = SDL_CreateTextureFromSurface(getrenderer(), loadedText);

        SDL_FreeSurface(loadedText); // liberation de la memoire
        SDL_RenderCopy(getrenderer(), text_affi, NULL, &DstRect); // copie le rectangle du texte sur la fenetre
        TTF_CloseFont(font); // on libere l'espace memoire de la font
    }
    else
    {
        printf("La font n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());
        fprintf(stdout, "Message d’erreur (%s) (avec le chargement de la font)\n", SDL_GetError()); // ecrit le message d'erreur dans un fichier txt externe
    }

    return text_affi;
}