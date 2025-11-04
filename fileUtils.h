#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool readFromFile(const char* fileName);

// Supported modes:
// w: if file exists, overwrite, if file doesnt exist, create new
// a: if file opens, opens in append mode, if file doesnt exist new file made.
bool writeToFile(const char* fileName, char* mode);

#endif