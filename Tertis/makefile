
Al_tetris : Main.c al_backend_init.c al_events.c front_allegro.c front_init_allegro.c game_start.c matrix_manipulation.c matrix_validation.c misc_functions.c scored.c states_allegro.c
	gcc  Main.o al_backend_init.o al_events.o front_allegro.o front_init_allegro.o game_start.o matrix_manipulation.o matrix_validation.o misc_functions.o scored.o states_allegro.o  `pkg-config --libs allegro-5` `pkg-config --libs allegro_color-5` `pkg-config --libs allegro_image-5` `pkg-config --libs allegro_primitives-5` `pkg-config --libs allegro_acodec-5` `pkg-config --libs allegro_audio-5` `pkg-config --libs allegro_dialog-5` `pkg-config --libs allegro_font-5` `pkg-config --libs allegro_ttf-5` -o tetris


Pi_tetris : Main.c al_backend_init.c al_events.c front_pi.c front_init_pi.c game_start.c matrix_manipulation.c matrix_validation.c misc_functions.c scored.c states_pi.c
	gcc  Main.o al_backend_init.o al_events.o front_pi.o front_init_pi.o game_start.o matrix_manipulation.o matrix_validation.o misc_functions.o scored.o states_pi.o  `pkg-config --libs allegro-5` joydrv.o disdrv.o termlib.c -o tetris

0 :	Main.c general.h
	gcc -c Main.c

1 : al_backend_init.c al_backend_init.h
	gcc -c al_backend_init.c

2 : al_events.c al_events.h
	gcc -c al_events.c

3 : front_allegro.c front_allegro.h
	gcc -c front_allegro.c

4 : front_init_allegro.c front_init_allegro.h
	gcc -c front_init_allegro.c

5 : game_start.c game_start.h
	gcc -c game_start.c

6 : matrix_manipulation.c matrix_manipulation.h
	gcc -c matrix_manipulation.c

7 : matrix_validation.c matrix_validation.h
	gcc -c matrix_validation.c

8: misc_functions.c misc_functions.h
	gcc -c misc_functions.c

9 : scored.c scored.h
	gcc -c scored.c

10 : states_allegro.c states_allegro.h
	gcc -c states_allegro.c

11 : front_pi.c front_pi.h
	gcc -c front_pi.c

12 : states_pi.c states_pi.h
	gcc -c states_pi.c

13 : front_init_pi.c front_init_pi.h
	gcc -c front_init_pi.c
