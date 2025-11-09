#include "miscUtils.h"


void stdinConsumer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

int caseStringify(CaseDef* c, char* out, size_t outSize) {
	char stringified[256];
	if (!c || !out || outSize == 0) {
		return 0;
	}
	size_t used = 0;
	int written = snprintf(out, outSize, "%s,%.2f,%zu", c->name, c->cost, c->itemCount);
	if (written < 0 || (size_t)written >= outSize) {
		return 0;
	}
	used = (size_t)written;
	for (size_t i = 0; i < c->itemCount; ++i) {
		const CaseItem* it = &c->items[i];
		written = snprintf(out + used, outSize - used, ",%s,%.6f,%.2f", it->name, it->probability, it->value);
		if (written < 0 || (size_t)written >= outSize - used) {
			return 0;
		}
		used += (size_t)written;
	}
	return 1;
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