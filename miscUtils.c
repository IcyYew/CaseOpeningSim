#include "miscUtils.h"


void stdinConsumer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}