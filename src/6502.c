// Read Write funcs for operation
uint8_t read(uint16_t addr)                { return memory[addr]; }
void    write(uint16_t addr, uint8_t data) { memory[addr] = data; }

void cpuRun(c6502* cpu) {
    // TODO: 
    // start the program counter moving and data reading/writing
    // read at program counter get instruction
    // function based on address mode
    
    while (programCounter < MEMSIZE) {
        dataBus = read(addressBus);
        // do functions
        incProgramCounter();

    }
}
void cpuReset(c6502* cpu) { 
    // TODO: 
    // reset all values
}

uint8_t immediate() {
    incProgramCounter();
    return dataBus;
}

uint8_t absolute() {
    incProgramCounter(); 
    uint8_t LBYTE = dataBus;
    
    incProgramCounter();
    uint8_t HBYTE = dataBus;

    uint16_t fullAddress = LBYTE + (HBYTE << 8);
    addressBus = fullAddress;
    dataBus = read(addressBus);

    return dataBus;
}

uint8_t zeropage() {
    incProgramCounter();

    addressBus = 0;
    addressBus += dataBus;

    dataBus = read(addressBus);
    return dataBus;
}

uint8_t absoluteX() {

}

void incProgramCounter() {
    programCounter++;
    addressBus = programCounter;
    dataBus = read(addressBus);
}
