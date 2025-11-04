#include "ui.h"
#include "validation.h"
#include "fileUtils.h"


int modeSelectUIRunner(void) {
	char* modeSelectString = "Select MODE: \n1. SIMULATION\n2. IMPORT NEW CASE\n3. STATISTICAL ANALYSIS ON LOG FILE\nInput the number of your selection: ";
	return readIntInRange(modeSelectString, 1, 3);
}

void shutdownUIRunner(const char* errorMsg) {
	if (errorMsg == "") {
		errorMsg = "No error message, bad programmer!";
	}
	printf("----------SHUTDOWN----------\n\nYou broke me :(\n\n%s", errorMsg);
	exit(EXIT_FAILURE);
}

void simulationUIRunner(void) {
	int numRuns;
	printf("----------SIMULATION----------\n\n");
	numRuns = readIntInRange("Input number of runs:", 1, 1000);
	printf("Number of runs selected: %d\n", numRuns);
	printf("Running...\n");
	
}

void caseImportUIRunner(void) {
	printf("----------CASE IMPORT----------\n\n");
	char* fileName = validFileName("Enter CSV file name: ");
	
}

void statisticsUIRunner(void) {
	shutdownUIRunner("PENDING MODULE");
}