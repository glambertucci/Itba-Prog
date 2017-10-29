#ifndef TERMINALFRONT_H
#define TERMINALFRONT_H


void printPort(uint8_t *);
void message(uint8_t);
void blinkFunction(uint8_t * bitarray, uint8_t state);
void updateScreen(uint8_t bitArray[8], uint8_t state);

#endif
