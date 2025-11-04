#ifndef VALIDATION_H
#define VALIDATION_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int readIntInRange(const char* prompt, int min, int max);
char* validCSVFileName(const char* prompt);

#endif