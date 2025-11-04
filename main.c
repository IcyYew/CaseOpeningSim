#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"
#include "ui.h"

int main() {
	int modeSelect = modeSelectUIRunner();
	while(1) {
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
			case 4:
				niceShutdownUIRunner();
			default:
				// never reached
				break;
		}
		modeSelect = modeSelectUIRunner();
	}
}