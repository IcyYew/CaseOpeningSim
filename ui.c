#include "ui.h"
#include "validation.h"


int modeSelectUIRunner(void) {
	char* modeSelectString = "Select MODE: \n1. SIMULATION\n2. IMPORT NEW CASE\n3. STATISTICAL ANALYSIS ON LOG FILE\nInput the number of your selection: ";
	return readIntInRange(modeSelectString, 1, 3);
}

void simulationUIRunner(void) {
	int numRuns;
	printf("----------SIMULATION----------\n\n");
	numRuns = readIntInRange("Input number of runs: ", 1, 1000);
	printf("Number of runs selected: %d", numRuns);
	printf("Running...");
	
}

void caseImportUIRunner(void) {
	
}

void statisticsUIRunner(void);