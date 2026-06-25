#include "../memory.h"
#include "../6502.h"

int main() {
    
    init_memory();
    struct c6502 cpu;
    for(int i = 0; i < MEMORY.size; ++i) {
        write(i, 0);
    }
    
    cpu.addressBus = 0;
    cpu.programCounter = 0;
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

    cpuRun(&cpu);

    return 0;
}
