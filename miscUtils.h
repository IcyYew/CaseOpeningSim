#ifndef MISC_UTILS_H
#define MISC_UTILS_H
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "case.h"

void stdinConsumer(void);

int parseCaseInfo(char* caseInfo, CaseDef *out);
int parseCaseItem(char* itemInfo, CaseItem *out);
int caseStringify(CaseDef* c, char* out, size_t outSize);
#endif