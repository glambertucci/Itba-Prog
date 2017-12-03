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

#ifndef FRONT_INIT_ALLEGRO_H
#define FRONT_INIT_ALLEGRO_H

#ifdef __cplusplus
extern "C" {
#endif

void frontend_init(FRONTEND* front_utils, AL_UTILS* al_utils);
//
void frontend_destroy(FRONTEND* front_utils);
//


#ifdef __cplusplus
}
#endif

#endif /* FRONT_INIT_ALLEGRO_H */

