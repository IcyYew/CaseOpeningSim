#include "ui.h"


int modeSelectUIRunner(void) {
	char* modeSelectString = "Select MODE: \n1. SIMULATION\n2. IMPORT NEW CASE\n3. STATISTICAL ANALYSIS ON LOG FILE\n4. EXIT\nInput the number of your selection: ";
	return readIntInRange(modeSelectString, 1, 4);
}

void shutdownUIRunner(const char* errorMsg) {
	if (errorMsg == "") {
		errorMsg = "No error message, bad programmer!";
	}
	printf("----------SHUTDOWN----------\n\nYou broke me :(\n\n%s", errorMsg);
	exit(EXIT_FAILURE);
}

void niceShutdownUIRunner() {
	printf("---------------------\n");
	printf("Have a nice day! :D\n");
	printf("---------------------");
	exit(0);
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
	char* fileName = validCSVFileName("Enter CSV file name: ");
	loadCasesFromCSV();
	printf("Case successfully imported!\n");
	
}

void statisticsUIRunner(void) {
	shutdownUIRunner("PENDING MODULE");
}