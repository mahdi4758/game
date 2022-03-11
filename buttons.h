#ifndef BUTTONS_H
#define BUTTONS_H
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "image.h"
#include "texte.h"

void menu_buttons(SDL_Event e, int *a, int *p, int *done, Mix_Chunk *c, SDL_Surface *s, int *f, int *v, int *i, Mix_Music *mms, Mix_Music *ss, int *k);
void mainMenu_display(SDL_Surface *s, int a, image b1, image p0, image s0, image q0, image p1, image q1, image s1, image fbg, int f, image Fp0, image Fs0, image Fq0, image Fp1, image Fs1, image Fq1, int i);
void menu_mousemotions(int p, SDL_Event e, int *a, int f, int *i);
int settings_mousemotions(int p, SDL_Event e, int f);
void menu_mouseclickdown(int *p, SDL_Event e, Mix_Chunk *c, int *done, int *f, SDL_Surface *s, int *v, Mix_Music *ss, Mix_Music *mms, int *k);
void playMenu_display(image bg1, SDL_Surface *s, int f, image fbg1, image re, image res, image fre, image fres, SDL_Event e, int p);
int play_mousemotions(int p, SDL_Event e, int f);
void settingsMenu_display(SDL_Event e, image bg1, SDL_Surface *s, text t, text fst, int f, image fbg1, text ft, image t0, text st, int p, image t0s, image t1, image t1s, text s1t, image pl0, image pl1, image mi0, image mi1, text fs1t, image fpl0, image fpl1, image fmi0, image fmi1, image re, image res, image fre, image fres, image h0, image h1, int k, image hbg, image fh0, image fh1, image fhbg);
void free_surfaces(image b1, image bg1, image fbg, image p0, image p1, image s0, image s1, image q0, image q1, image t0, image t0s, image t1, image t1s, image pl0, image pl1, image mi0, image mi1);
void free_surfaces1(image Fp0, image Fs0, image Fq0, image Fp1, image Fs1, image Fq1, image fpl0, image fpl1, image fmi0, image fmi1, image re, image res, image fre, image fres);
void free_surfaces2(image h0, image h1, image hbg, image fh0, image fh1, image fhbg);
void free_text_audio(text t, text ft, text st, Mix_Music *mms, Mix_Chunk *cs, text fst, text s1t, text fs1t, Mix_Music *ss);

#endif
