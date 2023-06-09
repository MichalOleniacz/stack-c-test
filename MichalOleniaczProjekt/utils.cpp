//
// Created by Michał Oleniacz on 08/06/2023.
//

#include "utils.h"
#include "stdio.h"

bool inRangeEq(int val, int l, int h)
{
	if (val >= l && val <= h)
		return true;
	return false;
}

bool inRange(int val, int l, int h)
{
	if (val >= l && val < h)
		return true;
	return false;
}

int getSelection(int maxRange)
{
	int selection;
	scanf_s("%d", &selection);
	if (!inRange(selection, 1, maxRange)) {
		printf("Selection out of range! Valid options are: 1..7, please try again:\n");
		selection = getSelection(maxRange);
	}
	return selection;
}

void appendEOF(FILE* datafile)
{

}