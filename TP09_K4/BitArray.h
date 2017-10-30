#ifndef BITARRAY_H
#define BITARRAY_H

#include <stdint.h>
uint8_t* bitArrayInit(void);
//Inicializa el array de bits que utilizamos para guardar los valores del puerto A
void updateBitArray(uint8_t * array);

#endif
