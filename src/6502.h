#include <stdint.h>

const int MEMSIZE = 128;

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
void cpuRun   (struct c6502* cpu);
void cpuReset (struct c6502* cpu);
void incProgramCounter(struct c6502* cpu);

// these are just for reference at the moment
// Address Modes
//uint8_t immediate(c6502*);
//uint8_t zeropage(c6502*);
//uint8_t zeropageX(c6502*);
//uint8_t absolute(c6502*);
//uint8_t absoluteX(c6502*);
//uint8_t absoluteY(c6502*);
//uint8_t indirectX(c6502*);
//uint8_t indirectY(c6502*);

// DEBUG
void dumpVals();
