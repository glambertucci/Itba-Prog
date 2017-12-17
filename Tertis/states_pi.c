#include "general.h"
#ifdef RASP_PI
#include "states_pi.h"
#include "joydrv.h"

void menu_events (FRONTEND* front_utils, GAME_UTILS* gamevars) { //Esta funcion toma los eventos durante el
    //estado de menu   
    static bool is_not_first_time = true; //para saber si es la primera vez que se empieza y el continue sirva como start
    static bool is_first_tetris = true;
   
    ALLEGRO_EVENT event;    
    jswitch_t switchval; 
    joystick_update();
    jcoord_t joy_coord= joystick_get_coord();
    jcoord_t * joy;
    joy =&joy_coord;
    
    if(is_first_tetris == true) {
        is_first_tetris = false;
        draw_tetris();
        al_rest (3);
    }

            switch(what_direction(joy)) {
                
                case LEFT:
                    if(front_utils->selected_op>START){ //Selección de opción del menu
                        front_utils->selected_op += MOVEUP;
                    }
                    break;
                    
                case RIGHT:
                    if(front_utils->selected_op<QUIT){
                        front_utils->selected_op += MOVEDOWN;
                    }
                    break;
            }
        if ( switchval=joystick_get_switch_value())
        { while (joystick_get_switch_value()){joystick_update();}
            switch(front_utils->selected_op) 
            {
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

void playing_events(FRONTEND* front_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]) 
{
    
    ALLEGRO_EVENT event; //Esta funcion toma los eventos durante el estado playing
    SCORE score_counter = 0;
    bool quickset = false;

    al_get_next_event(front_utils->ev_utils.queue, &event); 
    jswitch_t switchval; 
    joystick_update();
     joystick_get_coord();
    jcoord_t  joy = joystick_get_coord();
   

            switch(what_direction(&joy)) 
            {
                
              //EN EL DEFAULT HAY QUE FIJARSE KEY PRESSED
                    
                case LEFT: //La flecha derecha y la flecha izquierda mueven las piezas horizontalmente.
                    if(checkMove(matrix, LEFT)) 
                    {
                        move(matrix, LEFT);
                        gamevars->draw = true;
                    }
                    break;
                    
                case RIGHT:
                    if(checkMove(matrix, RIGHT)) 
                    {
                        move(matrix, RIGHT);
                        gamevars->draw = true;
                    }
                    break;
                    
                case UP: //La flecha arriba rota la pieza.
                    
                    if(checkRotate(matrix)) //Si se puede rotar sin más, lo hará.
                    {
                        rotate(matrix);
                        gamevars->draw = true;
                    }
                    
              //      En caso de no poder rotar, se evalúa si es por estar cerca de una pared o bloque y se trabaja acorde.
               //      NOTA: Se diferencia el stick por sufrir de un caso particular debido a su forma. 
                    
                    else if(gamevars->currentpiece.type != STICK){
                        if(OK == rotateWall(matrix, gamevars, LEFT)){} //Caso pared izquierda
                        else if(OK == rotateWall(matrix,gamevars,RIGHT)){} //Caso pared derecha
                    }
                    
                    else{ //Caso particular, si se tratase del STICK.
                        
                        // La lógica de RotateWall se ve superada por el stick,
                 //        pues esta es la única pieza que no puede rotar aún estando 
             //            * totalmente separada de una pared o conjunto de bloques. 
              //           * La solución, sencilla, es manualmente detectar si no se 
               //          * puede rotar pero si se puede mover exactamente una vez 
               //          * para la izquierda, y luego trabajar la pieza para
               //          *acomodarla en el espacio y rotarla en caso de ser posible.
                        
                        
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
                    
                case DOWN: //La flecha abajo hará caer la pieza.
                    
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
                default:
                    if ( switchval=joystick_get_switch_value())
                    {while(joystick_get_switch_value()){joystick_update();}//espero a que suelte
                        gamevars->state = MENU;
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

int8_t what_direction ( jcoord_t * joy )//Te dice para que lado estas tocando el joystick
{
    int8_t direction = 9;
	static int8_t prev_dir=12;

    if (joy->x > TILT)
       direction = LEFT;      
    else if (joy->x < -TILT)
        direction = RIGHT;
    else if (joy->y > TILT)
        direction =UP; 
    else if (joy->y < -TILT)
        direction = DOWN;
       
    if (prev_dir == direction)
	{
		direction=9;	
	}
	else
	{
		prev_dir= direction;		
	}
    return direction;
}
#endif
