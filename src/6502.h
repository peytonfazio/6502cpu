#include <stdint.h>

// TEMP MEMORY THING TO BE ABLE TO TEST
const uint MEMSIZE = 128;

uint8_t memory[MEMSIZE];

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

// Basic CPU Functions
void cpuRun   (c6502*);
void cpuReset (c6502*);
void incProgramCounter();


// Address Modes
uint8_t immediate(uint16_t addr);
uint8_t zeropage(uint16_t addr);
uint8_t zeropageX(uint16_t addr);
uint8_t absolute(uint16_t addr);
uint8_t absoluteX(uint16_t addr);
uint8_t absoluteY(uint16_t addr);
uint8_t indirectX(uint16_t addr);
uint8_t indirectY(uint16_t addr);

// Debug
void dumpVals();
