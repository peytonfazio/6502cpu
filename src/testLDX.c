#include "memory.h"
#include "6502.h"

int main() {
    
    init_memory();
    struct c6502 cpu;
    for(int i = 0; i < MEMORY.size; ++i) {
        write(i, 0);
    }

    cpu.regY = 4;

write(0x00, 0xA2); write(0x01, 0x01);  // LDX #$01 → X=1

write(0x02, 0xA6); write(0x03, 0x40);   // LDX $40
write(0x40, 0x02);                      // → X=2

write(0x04, 0xB6); write(0x05, 0x40);   // LDX $40,Y ($40+4=$44)
write(0x44, 0x03);                      // → X=3

write(0x06, 0xAE); write(0x07, 0x50); write(0x08, 0x00); // LDX $0050
write(0x50, 0x04);                      // → X=4

write(0x09, 0xBE); write(0x0A, 0x50); write(0x0B, 0x00); // LDX $0050,Y ($54)
write(0x54, 0x05);                      // → X=5

// Indirect-Y variant using LDX ($NN),Y (hypothetical - 6502 doesn't have this!)
// Since 6502 lacks LDX indirect, we'll demonstrate with LDA ($NN),Y → X
write(0x0C, 0xB1); write(0x0D, 0x60);   // LDA ($60),Y → A
write(0x60, 0x70); write(0x61, 0x00);   // Points to $0070
write(0x74, 0x06);                      // $70 + Y=4 → $74 → A=6
write(0x0E, 0xAA);                      // TAX (transfer A to X) → X=6

// Alternative for missing LDX indirect: Use zeropage,X
write(0x0F, 0xB5); write(0x10, 0x80);   // LDA $80,X (X=5 → $85)
write(0x85, 0x07);                      // → A=7
write(0x11, 0xAA);                      // TAX → X=7

// Absolute,X
write(0x12, 0xBD); write(0x13, 0x80); write(0x14, 0x00); // LDA $0080,X (X=7 → $87)
write(0x87, 0x08);                      // → A=8
write(0x15, 0xAA);                      // TAX → X=8



    cpuRun(&cpu);

    return 0;
}
