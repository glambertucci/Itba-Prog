
Al_tetris : Main.c al_backend_init.c al_events.c front_allegro.c front_init_allegro.c game_start.c matrix_manipulation.c matrix_validation.c misc_functions.c scored.c states_allegro.c
	gcc  Main.c al_backend_init.c al_events.c front_allegro.c front_init_allegro.c game_start.c matrix_manipulation.c matrix_validation.c misc_functions.c scored.c states_allegro.c  `pkg-config --libs allegro-5` `pkg-config --libs allegro_color-5` `pkg-config --libs allegro_image-5` `pkg-config --libs allegro_primitives-5` `pkg-config --libs allegro_acodec-5` `pkg-config --libs allegro_audio-5` `pkg-config --libs allegro_dialog-5` `pkg-config --libs allegro_font-5` `pkg-config --libs allegro_ttf-5` -o tetris


Pi_tetris : Main.c al_backend_init.c al_events.c front_pi.c front_init_pi.c game_start.c matrix_manipulation.c matrix_validation.c misc_functions.c scored.c states_pi.c
	gcc  Main.c al_backend_init.c al_events.c front_pi.c front_init_pi.c game_start.c matrix_manipulation.c matrix_validation.c misc_functions.c scored.c states_pi.c  `pkg-config --libs allegro-5` joydrv.o disdrv.o termlib.c -o tetris

