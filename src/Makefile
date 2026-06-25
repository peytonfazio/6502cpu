# Compiler settings
CC = clang
CFLAGS = -Wall -Wextra -pedantic -std=c11 -g \
         -Weverything -Wno-padded -Wno-declaration-after-statement \
         -Wno-covered-switch-default -O2
LDFLAGS = 

# Project files
SRC_DIR = .
SRCS = 6502.c memory.c
HEADERS = 6502.h memory.h standardIns.h

# Targets
TARGETS = testLDA testLDX

# Default target
all: $(TARGETS)

# Individual test executables
testLDA: tests/testLDA.c $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ tests/testLDA.c $(SRCS)

testLDX: tests/testLDX.c $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ tests/testLDX.c $(SRCS)

# Dependencies
6502.o: 6502.c 6502.h memory.h standardIns.h
memory.o: memory.c memory.h

# Clean rule
clean:
	rm -r -f $(TARGETS) *.o *.dSYM

# Phony targets
.PHONY: all clean
