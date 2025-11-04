#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
bool fileExists(const char* fileName);

bool readFromFile(const char* fileName, int numCases);

// Supported modes:
// w: if file exists, overwrite, if file doesnt exist, create new
// a: if file opens, opens in append mode, if file doesnt exist new file made.
bool writeToFile(const char* fileName, const char* mode);

#endif