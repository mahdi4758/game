#include "image.h"
#include "texte.h"
#include "buttons.h"
#include <SDL/SDL_mixer.h>

/**
	You got to fix the Resolution for Fullscreen
		because every computer uses it 
			own resolution
**/

int main(int argc, char **argv[])
{
   //Initialisation	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	TTF_Init();

   //Variables declaration
	image p0, s0, q0, p1,q1, s1, Fp0, Fs0, Fq0, Fp1, Fs1, Fq1; // <--- Main Menu Pictures Variables
	image t0, t0s, t1, t1s, pl0, pl1, fpl0, fpl1, mi0, mi1, fmi0, fmi1, h0, h1, fh0, fh1; // <--- Settings Pictures Variables
	image bg, bg1, fbg, fbg1, hbg, fhbg; // <--- Background Pictures Variables
	image re, res, fre, fres; // <--- General Pictures Variables
	SDL_Surface *s; SDL_Event e;
	int done=1, a=0, p=0, i=1, f=1, v=100, k=0;
	text t, ft, st, fst, s1t, fs1t;
	Mix_Music *mms, *ss; Mix_Chunk *cs;
	atexit(SDL_Quit);

   //Setting up Screen
	s = SDL_SetVideoMode(1000, 500, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
	if(!s){
		printf("Unable to set 1000x500 video: %s\n", SDL_GetError());
		return 1;
	}
	SDL_WM_SetCaption("STRANDED", NULL);  //Set Name & Icon of the Window

   //Initialisations Variables
	initBackground(&bg); /**/ initBackground1(&bg1); /**/ init_f_Background(&fbg); /**/ init_f_Background1(&fbg1);
	initText(&t); initfText(&ft); initText1(&st); initfText1(&fst); initText2(&s1t); initfText2(&fs1t);
	initP0(&p0); /**/ initP1(&p1); /**/ initS0(&s0); /**/ initS1(&s1); /**/ initQ0(&q0); /**/ initQ1(&q1);
	initfP0(&Fp0); /**/ initfS0(&Fs0); /**/ initfQ0(&Fq0); /**/ initfP1(&Fp1); /**/ initfS1(&Fs1); /**/ initfQ1(&Fq1);
	initT0(&t0); /**/ initT1(&t1); /**/ initT0s(&t0s); /**/ initT1s(&t1s); /**/ initRe0(&re); /**/ initRe1(&res);
	initPlus0(&pl0); /**/ initPlus1(&pl1); /**/ initMinus0(&mi0); /**/ initMinus1(&mi1); /**/ initfPlus0(&fpl0); /**/ initfPlus1(&fpl1);
	initfMinus0(&fmi0); /**/ initfMinus1(&fmi1); /**/ initfRe0(&fre); /**/ initfRe1(&fres); /**/ hotkBackground(&hbg);
	initH0(&h0); /**/ initH1(&h1); /**/ initfH0(&fh0); /**/ initfH1(&fh1); /**/ fhotkBackground(&fhbg);

   //Sounds
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	mms = Mix_LoadMUS("Music/music.mp3"); ss = Mix_LoadMUS("Music/music.mp3");
	cs = Mix_LoadWAV("Music/Button click.wav");
	Mix_PlayMusic(mms, -1);

   //Game Loop
	while(done!=0){
		SDL_PollEvent(&e);
		switch(e.type){
		    case SDL_QUIT:
			done = 0;
			break;

	    //Keyboard Input
		    case SDL_KEYDOWN:
			menu_buttons(e, &a, &p, &done, cs, s, &f, &v, &i, mms, ss, &k);
			break;

	    //Mouse Input
		    case SDL_MOUSEMOTION:
			menu_mousemotions(p, e, &a, f, &i);
			break;
	    //Mouse Click Down
		    case SDL_MOUSEBUTTONDOWN:
			menu_mouseclickdown(&p, e, cs, &done, &f, s, &v, ss, mms, &k);
			break;
		}

	    //Main Menu
		if(p == 0){
		    mainMenu_display(s, a, bg, p0, s0, q0, p1, q1, s1, fbg, f, Fp0, Fs0, Fq0, Fp1, Fs1, Fq1, i);
	    //Play Menu
		}else if(p == 1){
		    playMenu_display(bg1, s, f, fbg1, re, res, fre, fres, e, p);
	    //Settings Menu
		}else if(p == 2){
		    settingsMenu_display(e, bg1, s, t, fst, f, fbg1, ft, t0, st, p, t0s, t1, t1s, s1t, pl0, pl1, mi0, mi1, fs1t, fpl0, fpl1, fmi0, fmi1, re, res, fre, fres, h0, h1, k, hbg, fh0, fh1, fhbg);
		}
	}

   //Free Surfaces
	free_surfaces(bg, bg1, fbg, p0, p1, s0, s1, q0, q1, t0, t0s, t1, t1s, pl0, pl1, mi0, mi1);
	free_surfaces1(Fp0, Fs0, Fq0, Fp1, Fs1, Fq1, fpl0, fpl1, fmi0, fmi1, re, res, fre, fres);
	free_surfaces2(h0, h1, hbg, fh0, fh1, fhbg);
	free_text_audio(t, ft, st, mms, cs, fst, s1t, fs1t, ss);
	SDL_Quit(); 

	return 0;
}
