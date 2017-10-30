#ifndef BITARRAY_H
#define BITARRAY_H

#include <stdint.h>
uint8_t* bitArrayInit(void);
//Inicializa el array de bits que utilizamos para guardar los valores del puerto A
void updateBitArray(uint8_t * array);
//Recibe un puntero a un array con elementos de 8 bits y actualiza su valor a los mismos del puerto A.

#endif
