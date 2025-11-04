#include "validation.h"
#include "fileUtils.h"

int readIntInRange(const char* prompt, int min, int max) {
	int value;
	int result;
	int c;
	while (1) {
		printf("%s", prompt);
		result = scanf("%d", &value);
		if (result != 1) {
			printf("Invalid input type\n");
			while ((c = getchar()) != '\n' && c != EOF) {}
			continue;
		}
		
		if (value < min || value > max) {
			printf("Input out of range\n");
			while ((c = getchar()) != '\n' && c != EOF) {}
			continue;
		}
		
		while ((c = getchar()) != '\n' && c != EOF) {}
		return value;
	}
}

char* validCSVFileName(const char* prompt) {
	char temp[256];
	
	while(1) {
		printf"%s", prompt);
		if(scanf("%255s", temp) != 1) {
			printf("File name input error\n");
			continue;
		}
		
		if (fileExists(temp)) {
			char* fName = malloc(strlen(temp) + 1);
			if (!fName) {
				perror("malloc fail");
				exit(EXIT_FAILURE);
			}
			strcpy(fName, temp);
			return fName;
		}
		else {
			printf("No file found by: %s\nTry again.\n", temp);
		}
	}
}
