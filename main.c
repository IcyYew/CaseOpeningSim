#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"

int main() {
	printf("Select MODE: \n1. SIMULATION\n2. IMPORT NEW CASE\n3. STATISTICAL ANALYSIS ON LOG FILE\n");
	printf("Input the number of your selection: ");
	int modeSelect = 0;
	do {
		if (scanf("%d", &modeSelect) != 1) {
			//non-int input, clean stdin
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
			modeSelect = 0;
		}
	}while (!validateInt(modeSelect));
}