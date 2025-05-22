#include "memory.h"
#include "6502.h"

int main() {
    
    init_memory();
    struct c6502 cpu;
    for(int i = 0; i < MEMORY.size; ++i) {
        write(i, 0);
    }

    cpu.regX = 3;
    cpu.regY = 4;

write(0x00, 0xA9); write(0x01, 0x01);  // LDA #$01 → A=1

write(0x02, 0xA5); write(0x03, 0x40);   // LDA $40
write(0x40, 0x02);                      // → A=2

write(0x04, 0xB5); write(0x05, 0x40);   // LDA $40,X ($43)
write(0x43, 0x03);                      // → A=3

write(0x06, 0xAD); write(0x07, 0x50); write(0x08, 0x00); // LDA $0050
write(0x50, 0x04);                      // → A=4

write(0x09, 0xBD); write(0x0A, 0x50); write(0x0B, 0x00); // LDA $0050,X ($53)
write(0x53, 0x05);                      // → A=5

write(0x0C, 0xB9); write(0x0D, 0x50); write(0x0E, 0x00); // LDA $0050,Y ($54)
write(0x54, 0x06);                      // → A=6

// INDIRECT-X: Base $60 + X=3 → $63 (points to $70)
write(0x0F, 0xA1); write(0x10, 0x60);
write(0x63, 0x70); write(0x64, 0x00);  // Pointer to $0070
write(0x70, 0x07);                      // → A=7

// INDIRECT-Y: Base $65 (points to $71) + Y=4 → $75
write(0x11, 0xB1); write(0x12, 0x65);
write(0x65, 0x71); write(0x66, 0x00);  // Pointer to $0071
write(0x75, 0x08);                      // → A=8

    cpuRun(&cpu);

    return 0;
}
