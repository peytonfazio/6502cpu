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
	[0xA9] = {LDA, immediate},
	[0xA5] = {LDA, zeropage},

};

#endif
