#include "case.h"
#include "fileUtils.h"
#include "validation.h"

/* CSV format:
*  (caseName,cost,itemCount(n),item0name,item0probability,item0value,item1name,item1probability,item1value,...,item(n-1)name,item(n-1)probability,item(n-1)value)
*/
int loadCasesFromCSV(const char* fileName, CaseDef** outCases, size_t* outCount) {
	int numCases;
	numCases = readIntInRange("Input number of cases in CSV file", 1, 1000);
	readFromFile(fileName, numCases);
	return 0;
}



void freeAllCases(CaseDef* cases, size_t count) {
	
}

