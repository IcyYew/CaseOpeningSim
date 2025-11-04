#include "validation.h"

int readIntInRange(const char* prompt, int min, int max) {
	int value;
	int result;
	int c;
	while (1) {
		printf("%s", prompt);
		result = scanf("%d", &value);
		if (result != 1) {
			printf("Invalid input type\n");
			stdinConsumer();
			continue;
		}
		
		if (value < min || value > max) {
			printf("Input out of range\n");
			stdinConsumer();
			continue;
		}
		
		stdinConsumer();
		return value;
	}
}

char* validCSVFileName(const char* prompt) {
	char temp[256];
	char temp2[256];
	char* tok;
	
	while(1) {
		printf("%s", prompt);
		if(scanf("%255s", temp) != 1) {
			printf("File name input error\n");
			continue;
		}
		strcpy(temp2, temp);
		tok = strtok(temp2, ".");
		tok = strtok(NULL, ".");
		if (tok && fileExists(temp) && strcmp(tok, "csv") == 0) {
			char* fName = malloc(strlen(temp) + 1);
			if (!fName) {
				perror("malloc fail");
				exit(EXIT_FAILURE);
			}
			strcpy(fName, temp);
			stdinConsumer();
			return fName;
		}
		else {
			printf("No file found by: %s\nTry again.\n", temp);
		}
	}
}
/*
Implement these two later
*/
char* validInputCaseInfo(const char* prompt) {
}
char* validInputCaseItem(const char* prompt);
