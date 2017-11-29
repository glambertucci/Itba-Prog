/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linedelete.h
 * Author: alan
 *
 * Created on November 19, 2017, 9:06 PM
 */

#ifndef LINEDELETE_H
#define LINEDELETE_H

#include "general.h"
void calculate_lines(PIECE matrix[TABLE_FIL][TABLE_COL]);
void delete_line(PIECE matrix[TABLE_FIL][TABLE_COL], uint8_t fila);
void calculate_new_velocity(AL_UTILS* al_utils);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* LINEDELETE_H */

