/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   front_init_allegro.h
 * Author: alan
 *
 * Created on December 3, 2017, 12:28 AM
 */
#ifdef ALLEGRO  
#ifndef FRONT_INIT_ALLEGRO_H
#define FRONT_INIT_ALLEGRO_H

#define FONTSIZE 40
    
bool frontend_init(FRONTEND* front_utils);
//
void frontend_destroy(FRONTEND* front_utils);


#endif /* FRONT_INIT_ALLEGRO_H */

#endif
