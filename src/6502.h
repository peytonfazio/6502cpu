#include <stdint.h>

uint8_t memory[128];

struct c6502 {
    //bus
    uint8_t  dataBus;
    uint16_t addressBus;

    // registers
    uint16_t programCounter;
    uint8_t  accumulator;
    uint8_t  regX;
    uint8_t  regY;
    uint8_t  statReg;
    uint8_t  stackPointer;
};

// Basic Functions

void cpuRun   (c6502*);
void cpuReset (c6502*);
