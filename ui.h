#ifndef UI_H
#define UI_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int modeSelectUIRunner(void);

void shutdownUIRunner(const char* errorMsg);

void simulationUIRunner(void);

void caseImportUIRunner(void);

void statisticsUIRunner(void);

#endif