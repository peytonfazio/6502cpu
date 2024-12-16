#include <stdint.h>

const uint MEMSIZE = 128;

uint8_t memory[MEMSIZE];

struct c6502 {
    //bus
    uint8_t  dataBus;
    uint16_t addressBus = 0;

    // registers
    uint16_t programCounter = 0;
    uint8_t  accumulator;
    uint8_t  regX;
    uint8_t  regY;
    uint8_t  statReg;
    uint8_t  stackPointer;
};

// Basic CPU Functions
void cpuRun   (c6502*);
void cpuReset (c6502*);
void incProgramCounter();

// Address Modes
uint8_t immediate();
uint8_t zeropage();
uint8_t zeropageX();
uint8_t absolute();
uint8_t absoluteX();
uint8_t absoluteY();
uint8_t indirectX();
uint8_t indirectY();

// DEBUG
void dumpVals();
