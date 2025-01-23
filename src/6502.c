#include "6502.h"

// Read Write funcs for operation
uint8_t read(uint16_t addr)                { return memory[addr]; }
void    write(uint16_t addr, uint8_t data) { memory[addr] = data; }

uint8_t immediate(struct c6502* cpu) {
    incProgramCounter(cpu);
    return cpu->dataBus;
}

uint8_t absolute(struct c6502* cpu) {
    incProgramCounter(cpu); 
    uint8_t lbyte = cpu->dataBus;
    
    incProgramCounter(cpu);
    uint8_t hbyte = cpu->dataBus;

    uint16_t fullAddress = lbyte + (hbyte << 8);
    cpu->addressBus = fullAddress;
    cpu->dataBus = read(cpu->addressBus);

    return cpu->dataBus;
}

uint8_t zeropage(struct c6502* cpu) {
    incProgramCounter(cpu);

    cpu->addressBus = 0;
    cpu->addressBus += cpu->dataBus;

    cpu->dataBus = read(cpu->addressBus);
    return cpu->dataBus;
}

uint8_t zeropageX(struct c6502* cpu) {
    incProgramCounter(cpu);

    cpu->addressBus = 0;
    cpu->addressBus += cpu->dataBus + cpu->regX;

    cpu->dataBus = read(cpu->addressBus);
    return cpu->dataBus;
}

uint8_t zeropageY(struct c6502* cpu) {
    incProgramCounter(cpu);

    cpu->addressBus = 0;
    cpu->addressBus += cpu->dataBus + cpu->regY;

    cpu->dataBus = read(cpu->addressBus);
    return cpu->dataBus;
}

uint8_t absoluteX(struct 6502* cpu) {
    incProgramCounter(cpu); 
    uint8_t lbyte = cpu->dataBus;
    
    incProgramCounter(cpu);
    uint8_t hbyte = cpu->dataBus;

    uint16_t fullAddress = lbyte + (hbyte << 8);
    cpu->addressBus = fullAddress + cpu->regX;
    cpu->dataBus = read(cpu->addressBus);
}

uint8_t absoluteY(struct 6502* cpu) {
    incProgramCounter(cpu); 
    uint8_t lbyte = cpu->dataBus;
    
    incProgramCounter(cpu);
    uint8_t hbyte = cpu->dataBus;

    uint16_t fullAddress = lbyte + (hbyte << 8);
    cpu->addressBus = fullAddress + cpu->regY;
    cpu->dataBus = read(cpu->addressBus);
}



void cpuRun(struct c6502* cpu) {
    // TODO: 
    // start the program counter moving and data reading/writing
    // read at program counter get instruction
    // function based on address mode
    
    while (cpu->programCounter < MEMSIZE) {
        cpu->dataBus = read(cpu->addressBus);
        // do functions
        incProgramCounter(cpu);

    }
}
void cpuReset(struct c6502* cpu) { 
    // TODO: 
    // reset all values
}



void incProgramCounter(struct c6502* cpu) {
    cpu->programCounter++;
    cpu->addressBus = cpu->programCounter;
    cpu->dataBus = read(cpu->addressBus);
}

