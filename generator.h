#ifndef GENERATOR_H
#define GENERATOR_H
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#include <Wincrypt.h>

// Initialize PRNG
// Seed xoshiro256++ with Wincrypt
int genInit(void);
// Reset xoshiro state
void genCleanup(void);
// Main random num generator
// Returns a 64-bit value
uint64_t genNext(void);
// random int in [0, max-1]
int genNextInRange(int max);

#endif