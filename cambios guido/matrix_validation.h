/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matrix_validation.h
 * Author: alan
 *
 * Created on December 3, 2017, 12:20 AM
 */

#ifndef MATRIX_VALIDATION_H
#define MATRIX_VALIDATION_H

#ifdef __cplusplus
extern "C" {
#endif

int check_fall(PIECE tablero [TABLE_FIL][TABLE_COL]);
//devuelve OK NOT_OK o NO_NEW
//
bool checkMove (PIECE matrix[TABLE_FIL][TABLE_COL], bool dir);
//
bool checkRotate(PIECE matrix[TABLE_FIL][TABLE_COL]);
//
bool can_i_copy (PIECE tablero [TABLE_FIL][TABLE_COL]);
//


#ifdef __cplusplus
}
#endif

#endif /* MATRIX_VALIDATION_H */

