#include "6502.h"
#include "standardIns.h"
#include <stdio.h>

void cpuRun(struct c6502* cpu) {

    // TODO: 
    // start the program counter moving and data reading/writing
    // read at program counter get instruction
    // function based on address mode
    
    while (cpu->programCounter < MEMORY.size) {
	cpu->dataBus = read(cpu->addressBus);
        dumpVals(cpu);
        struct bindIns current = instructions[cpu->dataBus];
	current.ins(current.addr(cpu), cpu);
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
    dumpVals(cpu);
}

void dumpVals(struct c6502* cpu) {
    printf("=== 6502 CPU State ===\n");
    
    // Bus state
    printf("Bus:\n");
    printf("  Data Bus:    0x%02X\n", cpu->dataBus);
    printf("  Address Bus: 0x%04X\n", cpu->addressBus);
    
    // Registers
    printf("\nRegisters:\n");
    printf("  Program Counter (PC): 0x%04X\n", cpu->programCounter);
    printf("  Accumulator (A):      0x%02X\n", cpu->accumulator);
    printf("  X Register:           0x%02X\n", cpu->regX);
    printf("  Y Register:           0x%02X\n", cpu->regY);
    
    // Status Register (flag-by-flag breakdown)
    printf("\nStatus Register (P): 0x%02X\n", cpu->statReg);
    printf("  [N] Negative:    %d\n", (cpu->statReg >> 7) & 1);
    printf("  [V] Overflow:    %d\n", (cpu->statReg >> 6) & 1);
    printf("  [ ] Unused:      %d\n", (cpu->statReg >> 5) & 1);
    printf("  [B] Break:       %d\n", (cpu->statReg >> 4) & 1);
    printf("  [D] Decimal:     %d\n", (cpu->statReg >> 3) & 1);
    printf("  [I] Interrupt:   %d\n", (cpu->statReg >> 2) & 1);
    printf("  [Z] Zero:        %d\n", (cpu->statReg >> 1) & 1);
    printf("  [C] Carry:       %d\n", cpu->statReg & 1);
    
    // Stack
    printf("\nStack Pointer (S): 0x%02X\n", cpu->stackPointer);
    printf("(Effective stack address: 0x01%02X)\n", 0x100 + cpu->stackPointer);
}

