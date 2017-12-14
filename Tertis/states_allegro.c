#include <allegro5/allegro5.h>  
#include <allegro5/allegro_color.h> 
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include "al_events.h"

#include "general.h"
#include "states_allegro.h"
#include "matrix_manipulation.h"
#include "matrix_validation.h"
#include "misc_functions.h"
#include "scored.h"


void playing_events(FRONTEND* front_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]) {
    
    ALLEGRO_EVENT event; //Esta funcion toma los eventos durante el estado playing
    SCORE score_counter = 0;
    bool quickset = false;
    
    
    
    if (gamevars->prev_state != gamevars->state ){ //Cambiamos la música si estabamos en el menu
        al_stop_samples();
        al_play_sample (front_utils->samples[0],0.75,0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL); 
        gamevars->prev_state = gamevars->state;
    }
    
    if(al_get_next_event(front_utils->ev_utils.queue, &event)) { 
        
        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { //Si se cierra la ventana, termina el juego.
            gamevars->quit = true;
        }
        
        if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
            
            switch(event.keyboard.keycode) 
            {
                
                case ALLEGRO_KEY_ESCAPE: // ESC es el botón de pausa.
                    gamevars->state = MENU;
                    break;
                    
                case ALLEGRO_KEY_LEFT: //La flecha derecha y la flecha izquierda mueven las piezas horizontalmente.
                    if(checkMove(matrix, LEFT)) 
                    {
                        move(matrix, LEFT);
                        gamevars->draw = true;
                    }
                    break;
                    
                case ALLEGRO_KEY_RIGHT:
                    if(checkMove(matrix, RIGHT)) 
                    {
                        move(matrix, RIGHT);
                        gamevars->draw = true;
                    }
                    break;
                    
                case ALLEGRO_KEY_UP: //La flecha arriba rota la pieza.
                    
                    if(checkRotate(matrix)) //Si se puede rotar sin más, lo hará.
                    {
                        rotate(matrix);
                        gamevars->draw = true;
                    }
                    
                    /*En caso de no poder rotar, se evalúa si es por estar cerca de una pared o bloque y se trabaja acorde.
                     NOTA: Se diferencia el stick por sufrir de un caso particular debido a su forma. */
                    
                    else if(gamevars->currentpiece.type != STICK){
                        if(OK == rotateWall(matrix, gamevars, LEFT)){} //Caso pared izquierda
                        else if(OK == rotateWall(matrix,gamevars,RIGHT)){} //Caso pared derecha
                    }
                    
                    else{ //Caso particular, si se tratase del STICK.
                        
                        /* La lógica de RotateWall se ve superada por el stick,
                         pues esta es la única pieza que no puede rotar aún estando 
                         * totalmente separada de una pared o conjunto de bloques. 
                         * La solución, sencilla, es manualmente detectar si no se 
                         * puede rotar pero si se puede mover exactamente una vez 
                         * para la izquierda, y luego trabajar la pieza para
                         *acomodarla en el espacio y rotarla en caso de ser posible.*/
                        
                        
                        if(checkMove(matrix,LEFT)){ 
                            move(matrix,LEFT); 
                            if(checkRotate(matrix)){ //Si se puede mover para la izquierda
                                rotate(matrix); //Pero no puede rotar....
                                gamevars->draw = true;
                            }
                            else if(checkMove(matrix,LEFT)){
                                if(checkRotate(matrix)){
                                    rotate(matrix);
                                    gamevars->draw = true;
                                }
                                else if(checkMove(matrix,LEFT)){
                                    move(matrix,LEFT);
                                    if(checkRotate(matrix)){
                                        rotate(matrix);
                                        gamevars->draw = true;
                                    }
                                    else{
                                        move(matrix,RIGHT);
                                        move(matrix,RIGHT);
                                    }
                                }
                            }
                            else{ //...Vendra aqui, donde regresará a su posición e intentará moverse a la izquierda.
                                move(matrix,RIGHT);
                                rotateWall(matrix,gamevars,RIGHT);
                            }    
                        }
                        else{
                            rotateWall(matrix,gamevars,RIGHT);
                        }
                    }
                    break;
                    
                case ALLEGRO_KEY_DOWN: //La flecha abajo hará caer la pieza.
                    
                    if(check_fall(matrix)){
                        al_stop_timer(front_utils->ev_utils.timer); //Se frena el timer para que se reinicie.                     
                        while(check_fall(matrix)) //De lo contrario comparte el tiempo restante hasta bajar que tenía antes de caer.
                        {
                            fall(matrix); //Caerá mientras pueda.
                        }
                        gamevars->draw = true;
                        al_start_timer(front_utils->ev_utils.timer);
                    }
                    
                    else{
                        quickset = true; //Fija la pieza si ya no puede caer.
                    } 
                    
                    break;
            }
        }
    }
    
    if(event.type == ALLEGRO_EVENT_TIMER || quickset == true ) 
    {
        //   printf("HOLA\n");//DEBUG
        if(OK == check_fall(matrix)) 
        {                            //Si se puede caer la pieza, cae
            fall(matrix);
            gamevars->draw = true;  
        }
        
        else 
        {                            //Si no, se congela todo, se ve si hay linea completa y si la hay se borra, se suma score
            all_static(matrix);             //y se aumenta la velocidad si es necesario.
            
            if(score_counter = scored(matrix))
            {
                while(scored(matrix)) //still_score es un bool por lo que se repetirá hasta que ya no haya filas
                {
                    calculate_lines(matrix);   //...que eliminar, logrando eliminar todas simultáneamente.
                }
                gamevars->draw = true; 
                add_score(score_counter, gamevars);
                calculate_new_velocity(&front_utils->ev_utils, gamevars);
                change_velocity(&front_utils->ev_utils);
            }
            
            else {
                
                if(can_i_copy(matrix)){ //Se fija si se puede copiar una nueva pieza a la matriz    
                    copy_piece_to_mat(matrix, piece_mat,gamevars); //copiamos la pieza a la matriz
                    clean_piece_mat(piece_mat);
                    next_piece(gamevars); //calculamos la proxima pieza
                    fill_mat_piece(piece_mat, gamevars->nextpiece); //llenamos la matriz de pieza con la nueva
                }
                else{
                    copy_piece_to_mat(matrix, piece_mat, gamevars);
                    gamevars->lose = true; //Si no se puede caer, ni copiar una nueva pieza, se pierde   
                    gamevars->quit = true; // y se sale del juego
                    gamevars->restart = true;
                }
            }
        }
        
        if(quickset){
            al_stop_timer(front_utils->ev_utils.timer);
            al_start_timer(front_utils->ev_utils.timer); //Evitamos que la nueva pieza arrastre el tiempo de la fijada.
        }
    }
}

void menu_events (FRONTEND* front_utils, GAME_UTILS* gamevars) { //Esta funcion toma los eventos durante el
    //estado de menu   
    static bool is_not_first_time = true; //para saber si es la primera vez que se empieza y el continue sirva como start
    ALLEGRO_EVENT event;
    
    
    
    
    if (gamevars->prev_state != gamevars->state )
    {
        al_stop_samples(); //Seteamos la música del menu
        al_play_sample (front_utils->samples[1],1.25,0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL); 
        gamevars->prev_state = gamevars->state;
    }
    
    
    
    if(al_get_next_event(front_utils->ev_utils.queue, &event)){
        
        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            
            switch(event.keyboard.keycode) {
                
                case ALLEGRO_KEY_UP:
                    if(front_utils->selected_op>START){ //Selección de opción del menu
                        front_utils->selected_op += MOVEUP;
                    }
                    break;
                    
                case ALLEGRO_KEY_DOWN:
                    if(front_utils->selected_op<QUIT){
                        front_utils->selected_op += MOVEDOWN;
                    }
                    break;
                    
                case ALLEGRO_KEY_ENTER:
                    switch(front_utils->selected_op) {
                        case START:
                            gamevars->restart = TRUE;
                            gamevars->quit = TRUE;
                            front_utils->selected_op = CONTINUE; //Default
                            is_not_first_time = true;
                            break;
                        case CONTINUE:
                            gamevars->state = PLAYING;
                            is_not_first_time = true;
                            break;
                        case QUIT:
                            gamevars->quit = TRUE;
                            break;
                    }
            }
        }
        
        if((event.mouse.x > MENUMARGIN && event.mouse.y > (STARTPOSY)) && //Selecciona la opción por el mouse
                (event.mouse.x < (STARTPOSXEND) && event.mouse.y < (STARTPOSYEND))){
            front_utils->selected_op = START;
            if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                gamevars->restart = TRUE; //Con esto, reinicio el juego.
                gamevars->quit = TRUE; //Con esto, salgo del primer loop.
                is_not_first_time = true;
                front_utils->selected_op = CONTINUE; //Lo paso a CONTINUE para que sea la opción por defecto al pausar la primera vez tras reiniciar.
            }
        }
        else if((event.mouse.x > MENUMARGIN && event.mouse.y > (CONTPOSY)) &&
                (event.mouse.x < (CONTPOSXEND) && event.mouse.y < (CONTPOSYEND))){
            front_utils->selected_op = CONTINUE;
            if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                gamevars->state = PLAYING;
                is_not_first_time = true;
            }
        }
        else if((event.mouse.x > MENUMARGIN && event.mouse.y > QUITPOSY) &&
                (event.mouse.x < QUITPOSXEND && event.mouse.y < QUITPOSYEND)){
            front_utils->selected_op = QUIT;
            if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                gamevars->quit = TRUE; 
            }
            
        }
        if((event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)){
            gamevars->quit = TRUE;
        }
    }
}