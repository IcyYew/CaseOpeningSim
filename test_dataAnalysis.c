#include <stdio.h>
#include "dataAnalysis.h"
#include "case.h"

int main(void) {
	CaseItem items[] = {
		{"1", 0.7, 0.05},
			{"2", 0.2, 1.0},
				{"3", 0.09, 10.0},
					{"4", 0.01, 150.0}
	};
	CaseDef testCase = {
		"Test case",
		3.6,
		4,
		items
	};
	
	double ev = calculateEV(&testCase);
	double roi = calculateTheoreticalROI(testCase.cost, ev);
	
	printf("Expected value: %.4f\n", ev);
	printf("Theoretical ROI: %.2f%%\n", roi);
	if (ev > 0 && roi > 0) {
		printf("PASS");
	}
	else {
		printf("FAIL");
	}
	return 0;
}