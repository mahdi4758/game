game: main.o image.o texte.o buttons.o
	gcc main.o image.o texte.o buttons.o -o game -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o: main.c
	gcc -c main.c -g
image.o: image.c
	gcc -c image.c -g
texte.o: texte.c
	gcc -c texte.c -g
buttons.o: buttons.c
	gcc -c buttons.c -g
