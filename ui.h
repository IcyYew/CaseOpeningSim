#ifndef UI_H
#define UI_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "validation.h"
#include "fileUtils.h"
#include "dataAnalysis.h"
#include "miscUtils.h"

int modeSelectUIRunner(void);

void shutdownUIRunner(const char* errorMsg);
void niceShutdownUIRunner();

void simulationUIRunner(void);

void caseImportUIRunner(void);
void userInputCaseUIRunner(void);

void statisticsUIRunner(void);

#endif