#include "case.h"
#include "fileUtils.h"
#include "validation.h"

int loadCasesFromCSV(const char* fileName, CaseDef** outCases, size_t* outCount) {
	int numCases;
	numCases = readIntInRange("Input number of cases in CSV file", 1, 1000);
	readFromFile(fileName, numCases);
	return 0;
}



void freeAllCases(CaseDef* cases, size_t count) {
	
}

