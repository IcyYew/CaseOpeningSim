#include "miscUtils.h"


void stdinConsumer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}


int parseCaseInfo(char* caseInfo, CaseDef *out) {
	char* tok = strtok(caseInfo, ",");
	char* endPtr;
	if (!tok){
		return 0;
	}
	strncpy(out->name, tok, sizeof(out->name) - 1);
	out->name[sizeof(out->name) - 1] = '\0';
	tok = strtok(NULL, ",");
	if (!tok){
		return 0;
	}
	out->cost = atof(tok);
	
	tok = strtok(NULL, ",");
	if (!tok){
		return 0;
	}
	out->itemCount = (size_t)strtoumax(tok, &endPtr, 10);
	if (endPtr == tok || out->itemCount == 0) {
		return 0;
	}
	// allocate memory for items array
	out->items = calloc(out->itemCount, sizeof(CaseItem));
	if (!out->items) {
		perror("calloc failed");
		return 0;
	}
	return 1;
}
int parseCaseItem(char* itemInfo, CaseItem *out) {
	char* tok = strtok(itemInfo, ",");
	if (!tok){
		return 0;
	}
	strncpy(out->name, tok, sizeof(out->name) - 1);
	out->name[sizeof(out->name) - 1] = '\0';
	tok = strtok(NULL, ",");
	if (!tok){
		return 0;
	}
	out->probability = atof(tok);
	
	tok = strtok(NULL, ",");
	if (!tok){
		return 0;
	}
	out->value = atof(tok);
	return 1;
}