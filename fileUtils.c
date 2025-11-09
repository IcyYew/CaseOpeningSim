#include "fileUtils.h"

bool fileExists(const char* fileName) {
	if (access(fileName, F_OK) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool readFromFile(const char* fileName, int numCases) {
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
bool writeToFile(CaseDef* c, const char* fileName, const char* mode) {
	char buffer[512];
	FILE* fP;
	fP = fopen(fileName, mode);
	if (caseStringify(c, buffer, sizeof(buffer))) {
		fputs(buffer, fP);
		fputc('\n', fP);
	}
	fclose(fP);
	return true;
}