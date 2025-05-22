#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

typedef struct {
    const int size;
    uint8_t* memoryArray;
} memory;

extern memory MEMORY;

uint8_t read(uint16_t);
void write(uint16_t, uint8_t);

void init_memory();
#endif
