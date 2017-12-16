/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   front_init_pi.h
 * Author: alan
 *
 * Created on December 3, 2017, 12:24 AM
 */
#ifdef RASP_PI
#ifndef FRONT_INIT_PI_H
#define FRONT_INIT_PI_H
void frontend_destroy(FRONTEND* front_utils);
void frontend_init(FRONTEND* front_utils, EV_UTILS* al_utils);
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* FRONT_INIT_PI_H */

#endif