/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   al_backend_init.h
 * Author: alan
 *
 * Created on December 3, 2017, 12:26 AM
 */

#ifndef AL_BACKEND_INIT_H
#define AL_BACKEND_INIT_H

#include "general.h"

bool events_init (EV_UTILS* ev_utils);
//
void events_destroy(EV_UTILS* ev_utils);
//
void change_velocity(EV_UTILS* ev_utils);
//

#endif /* AL_BACKEND_INIT_H */
