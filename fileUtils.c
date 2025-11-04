#include "fileUtils.h"

bool fileExists(const char* fileName) {
	if (access(fileName, F_OK) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool readFromFile(const char* fileName, int numCases, CaseDef** outCases) {
	FILE* fP;
	char buffer[256];
	fP = fopen(fileName, "r");
	while(fgets(buffer, sizeof(buffer), fP) != NULL) {
		printf("%s", buffer);
	}		
	
	fclose(fP);
	return true;
}

// Supported modes:
// w: if file exists, overwrite, if file doesnt exist, create new
// a: if file opens, opens in append mode, if file doesnt exist new file made.
bool writeToFile(const char* fileName, const char* mode);