#ifndef VALIDATION_H
#define VALIDATION_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "fileUtils.h"
#include "miscUtils.h"

int readIntInRange(const char* prompt, int min, int max);
char* validCSVFileName(const char* prompt);
char* validInputCaseInfo(const char* prompt);
char* validInputCaseItem(const char* prompt);

#endif