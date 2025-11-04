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
