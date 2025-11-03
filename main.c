#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_FUNDS = 1000

typedef struct VW_GAMBIT_CASE {
	float cost = 5.3;
	float s1P = 0.01;
	float s1V = 169.23;
	float s2P = 0.19;
	float S2V = 10.41;
	float s3P = 0.10;
	float s3V = 4.55;
	float s4P = 0.20;
	float s4V = 0.74;
	float s5P = .10;
	float s5V = 2.37;
	float s6P = .20;
	float s6V = 1.16;
	float s7P = 0.20;
	float s7V = 0.16;
}


int main() {
	float funds = BASE_FUNDS;
	int numCases = 0;
	while(funds > 0) {
		printf("Input num cases to open: ");
		scanf("%d", &numCases);
		if (numCases == 0) {
			break;
		}
		
	}
	printf("Thanks for playing!");
	return 0;
}