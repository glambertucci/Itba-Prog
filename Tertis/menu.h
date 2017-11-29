/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menu.h
 * Author: guido
 *
 * Created on November 25, 2017, 9:14 AM
 */

#ifndef MENU_H
#define MENU_H

#include <allegro5/events.h>

int menu(void);
//devuelve la opcion elegida , respecto al void, puede ser que en el futuro tengamos que cambiarlo a que reciba una cola de eventos.
enum{START,CONTINUE,QUIT};
#include "general.h"
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MENU_H */

