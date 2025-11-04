#include "ui.h"


int modeSelectUIRunner(void) {
	char* modeSelectString = "Select MODE: \n1. SIMULATION\n2. IMPORT NEW CASE\n3. STATISTICAL ANALYSIS ON LOG FILE\n4. USER INPUT CASE\n0. EXIT\nInput the number of your selection: ";
	return readIntInRange(modeSelectString, 0, 4);
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

/*
TODO: ADD PROPER VALIDATION ON INPUTS~!
TEMPORARY SOLUTION
*/
void userInputCaseUIRunner(void) {
	char temp[256];
	CaseDef c;
	printf("----------INPUT CASE----------\n\n");
	printf("Input: caseName,caseCost,itemCount\n");
	if (scanf("%255s", temp) != 1) {
		printf("input error\n");
		stdinConsumer();
		return;
	}
	stdinConsumer();
	if (!parseCaseInfo(temp, &c)) {
		printf("Failed to parse case info\n");
		free(c.items);
		return;
	}
	for(size_t i = 0; i < c.itemCount; ++i) {
		printf("\nInput item %zu: itemName,itemProbability,itemValue\n", i + 1);
		if (scanf("%255s", temp) != 1) {
			printf("Input error\n");
			stdinConsumer();
			free(c.items);
			return;
		}
		stdinConsumer();
		if (!parseCaseItem(temp, &c.items[i])) {
			printf("Failed to parse item %zu.\n", i + 1);
			free(c.items);
			return;
		}
	}
	// ADD TO DATABASE, EVENTUALLY
	printf("\nCase '%s' loaded with %zu items. Cost: %.2f\n", c.name, c.itemCount, c.cost);
	double caseEV = calculateEV(&c);
	printf("Case EV: %.2f\nCase ROI: %.2f\n", caseEV, calculateTheoreticalROI(c.cost, caseEV));
	free(c.items);
}

void caseImportUIRunner(void) {
	printf("----------CASE IMPORT----------\n\n");
	char* fileName = validCSVFileName("Enter CSV file name: ");
	printf("Case successfully imported!\n");
}

void statisticsUIRunner(void) {
	shutdownUIRunner("PENDING MODULE");
}