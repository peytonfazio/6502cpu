#ifndef CPU_H
#define CPU_H

#include <stdint.h>
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
static inline uint8_t immediate(struct c6502* cpu) {
    incProgramCounter(cpu);
    return cpu->dataBus;
}

static inline uint8_t absolute(struct c6502* cpu) {
    incProgramCounter(cpu);
    uint8_t lbyte = cpu->dataBus;
    
    incProgramCounter(cpu);
    uint8_t hbyte = cpu->dataBus;

    uint16_t fullAddress = lbyte + (hbyte << 8);
    cpu->addressBus = fullAddress;
    cpu->dataBus = read(cpu->addressBus);

    return cpu->dataBus;
}

static inline uint8_t zeropage(struct c6502* cpu) {
    incProgramCounter(cpu);

    cpu->addressBus = 0;
    cpu->addressBus += cpu->dataBus;

    cpu->dataBus = read(cpu->addressBus);
    return cpu->dataBus;
}

static inline uint8_t zeropageX(struct c6502* cpu) {
    incProgramCounter(cpu);

    cpu->addressBus = 0;
    cpu->addressBus += cpu->dataBus + cpu->regX;

    cpu->dataBus = read(cpu->addressBus);
    return cpu->dataBus;
}

static inline uint8_t zeropageY(struct c6502* cpu) {
    incProgramCounter(cpu);

    cpu->addressBus = 0;
    cpu->addressBus += cpu->dataBus + cpu->regY;

    cpu->dataBus = read(cpu->addressBus);
    return cpu->dataBus;
}

static inline uint8_t absoluteX(struct c6502* cpu) {
    incProgramCounter(cpu); 
    uint8_t lbyte = cpu->dataBus;
    
    incProgramCounter(cpu);
    uint8_t hbyte = cpu->dataBus;

    uint16_t fullAddress = lbyte + (hbyte << 8);
    cpu->addressBus = fullAddress + cpu->regX;
    cpu->dataBus = read(cpu->addressBus);

    return cpu->dataBus;
}

static inline uint8_t absoluteY(struct c6502* cpu) {
    incProgramCounter(cpu); 
    uint8_t lbyte = cpu->dataBus;
    
    incProgramCounter(cpu);
    uint8_t hbyte = cpu->dataBus;

    uint16_t fullAddress = lbyte + (hbyte << 8);
    cpu->addressBus = fullAddress + cpu->regY;
    cpu->dataBus = read(cpu->addressBus);

    return cpu->dataBus;
}

static inline uint8_t indirect(struct c6502* cpu) {
    incProgramCounter(cpu); 
    uint8_t lbyte = cpu->dataBus;
    
    incProgramCounter(cpu);
    uint8_t hbyte = cpu->dataBus;

    uint16_t fullAddress = lbyte + (hbyte << 8);
    cpu->addressBus = fullAddress;
    cpu->dataBus = read(cpu->addressBus);

    uint8_t indlByte = cpu->dataBus;

    cpu->addressBus += 1;
    cpu->dataBus = read(cpu->addressBus);

    uint8_t indhByte = cpu->dataBus;

    uint16_t indFullAddress = indlByte + (indhByte << 8);
    
    cpu->dataBus = read(indFullAddress);
    return cpu->dataBus;
}

static inline uint8_t indirectX(struct c6502* cpu) {
    incProgramCounter(cpu);

    cpu->addressBus = 0;
    cpu->addressBus += cpu->dataBus + cpu->regX;

    cpu->dataBus = read(cpu->addressBus);

    uint8_t indlByte = cpu->dataBus;

    cpu->addressBus += 1;
    cpu->dataBus = read(cpu->addressBus);

    uint8_t indhByte = cpu->dataBus;

    uint16_t indFullAddress = indlByte + (indhByte << 8);
    
    cpu->dataBus = read(indFullAddress);
    return cpu->dataBus;

}

static inline uint8_t indirectY(struct c6502* cpu) {
    incProgramCounter(cpu); 
    uint8_t lbyte = cpu->dataBus;
    
    incProgramCounter(cpu);
    uint8_t hbyte = cpu->dataBus;

    uint16_t fullAddress = lbyte + (hbyte << 8);
    cpu->addressBus = fullAddress;
    cpu->dataBus = read(cpu->addressBus);

    uint8_t indlByte = cpu->dataBus;

    cpu->addressBus += 1;
    cpu->dataBus = read(cpu->addressBus);

    uint8_t indhByte = cpu->dataBus;

    uint16_t indFullAddress = indlByte + (indhByte << 8);
    
    cpu->dataBus = read(indFullAddress + cpu->regY);
    return cpu->dataBus;
}

#endif
