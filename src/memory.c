#include "memory.h"
#include <stdlib.h>

memory MEMORY = {.size = 128, .memoryArray = 0 };



uint8_t read(uint16_t address) { return MEMORY.memoryArray[address]; }
void    write(uint16_t address, uint8_t data) { MEMORY.memoryArray[address] = data; }
void init_memory() { 
	MEMORY.memoryArray = (uint8_t*)malloc(MEMORY.size * sizeof(uint8_t));
}
