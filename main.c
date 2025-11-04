#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"
#include "ui.h"

int main() {
	int modeSelect = modeSelectUIRunner();
	switch(modeSelect) {
		case 1:
			simulationUIRunner();
			break;
		case 2:
			caseImportUIRunner();
			break;
		case 3:
			statisticsUIRunner();
			break;
		default:
			printf("should never reach\n");
			break;
	}
}