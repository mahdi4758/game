#ifndef TEXTE_H
#define TEXTE_H
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>

typedef struct{
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface *surfaceTexte;
	SDL_Color textColor;
}text;

void initText(text *t); 
void initText1(text *t);
void initfText(text *t); 
void initfText1(text *t);
void initText2(text *t);
void initfText2(text *t);
void freeText(text t);
void displayText(text t, SDL_Surface *screen, char ch[]);

#endif
