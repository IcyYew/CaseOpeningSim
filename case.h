#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#ifndef CASE_H
#define CASE_H


// Struct for each item in a case
typedef struct {
	char name[64];
	double probability;
	double value;
} CaseItem;

// Struct for each case containing item_count items
typedef struct {
	char name[64];
	double cost;
	size_t itemCount;
	CaseItem* items;
} CaseDef;

int loadCasesFromCSV(const char* fileName, CaseDef** out_cases, size_t* out_count);
void freeAllCases(CaseDef* cases, size_t count);

#endif

