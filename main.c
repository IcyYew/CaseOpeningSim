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
			printf("Call UI module for importing case\n");
			break;
		case 3:
			printf("Call UI module for statistics\n");
			break;
		default:
			printf("should never reach\n");
			break;
	}
}