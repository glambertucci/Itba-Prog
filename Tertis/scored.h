/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   scored.h
 * Author: guido
 *
 * Created on November 12, 2017, 8:10 PM
 */

#ifndef SCORED_H
#define SCORED_H
#include "general.h"

bool scored (PIECE tablero [TABLE_FIL][TABLE_COL]);
// scored recibe la matriz del juego tablero, sirve para avisar si se hizo una linea, pone un identificaor (define) en la linea que hizo punto 
void add_score (int lines_destoyed);
//agrega puntos al score 
int get_score (void);
//devuelve el puntaje actual
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* SCORED_H */

