#ifndef DATA_ANALYSIS_H
#define DATA_ANALYSIS_H
#include "case.h"

double calculateEV(const CaseDef *c);

double calculateTheoreticalROI(double caseCost, double ev);

#endif