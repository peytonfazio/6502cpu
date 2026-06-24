#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdio.h>
#include "memory.h"

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

// DEBUG
void dumpVals(struct c6502* cpu);


// ADDRESSING MODES
uint8_t immediate(struct c6502* cpu);
uint8_t absolute(struct c6502* cpu);
uint8_t zeropage(struct c6502* cpu);
uint8_t zeropageX(struct c6502* cpu);
uint8_t zeropageY(struct c6502* cpu);
uint8_t absoluteX(struct c6502* cpu);
uint8_t absoluteY(struct c6502* cpu);
uint8_t indirect(struct c6502* cpu);
uint8_t indirectX(struct c6502* cpu);
uint8_t indirectY(struct c6502* cpu);

#endif
