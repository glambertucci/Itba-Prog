
Al_tetris : Main.o al_backend_init.o al_events.o front_allegro.o front_init_allegro.o game_start.o matrix_manipulation.o matrix_validation.o misc_functions.o scored.o states_allegro.o
	gcc  Main.o al_backend_init.o al_events.o front_allegro.o front_init_allegro.o game_start.o matrix_manipulation.o matrix_validation.o misc_functions.o scored.o states_allegro.o  `pkg-config --libs allegro-5` `pkg-config --libs allegro_color-5` `pkg-config --libs allegro_image-5` `pkg-config --libs allegro_primitives-5` `pkg-config --libs allegro_acodec-5` `pkg-config --libs allegro_audio-5` `pkg-config --libs allegro_dialog-5` `pkg-config --libs allegro_font-5` `pkg-config --libs allegro_ttf-5` -o tetris


Pi_tetris : Main.o al_backend_init.o al_events.o front_pi.o front_init_pi.o game_start.o matrix_manipulation.o matrix_validation.o misc_functions.o scored.o states_pi.o
	gcc  Main.o al_backend_init.o al_events.o front_pi.o front_init_pi.o game_start.o matrix_manipulation.o matrix_validation.o misc_functions.o scored.o states_pi.o  `pkg-config --libs allegro-5` joydrv.o disdrv.o termlib.c -o tetris

Main.o:	Main.c general.h
	gcc -c Main.c -o Main.o

al_backend_init.o : al_backend_init.c al_backend_init.h
	gcc -c al_backend_init.c -o al_backend_init.o

al_events.o : al_events.c al_events.h
	gcc -c al_events.c -o al_events.o

front_allegro.o : front_allegro.c front_allegro.h
	gcc -c front_allegro.c -o front_allegro.o

front_init_allegro.o : front_init_allegro.c front_init_allegro.h
	gcc -c front_init_allegro.c -o front_init_allegro.o

game_start.o : game_start.c game_start.h
	gcc -c game_start.c -o game_start.o

matrix_manipulation.o : matrix_manipulation.c matrix_manipulation.h
	gcc -c matrix_manipulation.c -o matrix_manipulation.o

matrix_validation.o : matrix_validation.c matrix_validation.h
	gcc -c matrix_validation.c -o matrix_validation.o

misc_functions.o : misc_functions.c misc_functions.h
	gcc -c misc_functions.c -o misc_functions.o

scored.o : scored.c scored.h
	gcc -c scored.c -o scored.o

states_allegro.o : states_allegro.c states_allegro.h
	gcc -c states_allegro.c -o states_allegro.o

front_pi.o : front_pi.c front_pi.h
	gcc -c front_pi.c -o front_pi.o

states_pi.o : states_pi.c states_pi.h
	gcc -c states_pi.c -o states_pi.o

front_init_pi.o : front_init_pi.c front_init_pi.h
	gcc -c front_init_pi.c -o front_init_pi.o
clean :
	rm Main.o al_backend_init.o al_events.o front_allegro.o front_init_allegro.o game_start.o matrix_manipulation.o matrix_validation.o misc_functions.o scored.o states_allegro.o
