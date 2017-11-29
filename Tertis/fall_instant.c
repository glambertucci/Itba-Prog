/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "general.h"
#include "fall_instant.h"
#include "fall.h"
#include "check_fall.h"
#include "all_static.h"

void fall_instant(PIECE matrix[TABLE_FIL][TABLE_COL]){
    
    while(check_fall(matrix)){
        fall(matrix);
        all_static(matrix);
    }
    
}