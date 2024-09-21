// Read Write funcs for operation
uint8_t read(uint16_t addr)                { return memory[addr]; }
void    write(uint16_t addr, uint8_t data) { memory[addr] = data; }

void cpuRun(c6502* cpu) {
    /* TODO: 

       start the program counter moving and data reading/writing

    */
}
void cpuReset(c6502* cpu) {}
