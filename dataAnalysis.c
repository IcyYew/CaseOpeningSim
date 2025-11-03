#include "dataAnalysis.h"

double calculateEV(const CaseDef *c) {
	double ev = 0.0;
	for (size_t i = 0; i < c->itemCount; ++i) {
		const CaseItem* item = &c->items[i];
		ev += item->probability * item->value;
	}
	return ev;
}

double calculateTheoreticalROI(double caseCost, double ev) {
	if (caseCost == 0.0 || ev < 0.0) {
		return 0.0;
	}
	return (ev / caseCost) * 100;
}