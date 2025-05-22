#ifndef STANDARD_INS_H
#define STANDARD_INS_H

#include "6502.h"
#include <stdint.h>

struct bindIns {
    void (*ins)(uint8_t, struct c6502*);
    uint8_t (*addr)(struct c6502*);
};

// load accumulator
static inline void LDA(uint8_t data, struct c6502* cpu) { cpu->accumulator = data; }
static inline void LDX(uint8_t data, struct c6502* cpu) { cpu->regX = data; }
static inline void LDY(uint8_t data, struct c6502* cpu) { cpu->regY = data; }

static struct bindIns instructions[255] = { 
	// LDA Instructions
	[0xA9] = {LDA, immediate},
	[0xA5] = {LDA, zeropage},
	[0xB5] = {LDA, zeropageX},
	[0xAD] = {LDA, absolute},
	[0xBD] = {LDA, absoluteX},
	[0xB9] = {LDA, absoluteY},
	[0xA1] = {LDA, indirectX},
	[0xB1] = {LDA, indirectY},

        // LDX Instructions
	[0xA2] = {LDX, immediate},
        [0xA6] = {LDX, zeropage},
        [0xB6] = {LDX, zeropageY},
        [0xAE] = {LDX, absolute},
        [0xBE] = {LDX, absoluteY},

	// LDY Instructions
	[0xA0] = {LDY, immediate},
	[0xA4] = {LDY, zeropage},
	[0xB4] = {LDY, zeropageX},
	[0xAC] = {LDY, absolute},
	[0xBC] = {LDY, absoluteX},

};

#endif
