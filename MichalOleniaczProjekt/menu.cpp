//
// Created by Michał Oleniacz on 05/06/2023.
//

#include "menu.h"
#include "interface.h"
#include "utils.h"

#define OPTIONS_COUNT 9


static const char* options[OPTIONS_COUNT] = {
		"Stack options:",
		"1 \t Print stack",
		"2 \t Push to stack",
		"3 \t Pop from stack",
		"4 \t Peak at stack",
		"5 \t Serialize stack",
		"6 \t Deserialize stack",
		"7 \t Search in stack",
		"8 \t Exit",
};

void printMenu()
{
	for (int i = 0; i < OPTIONS_COUNT; i++)
		printf("%s\n", options[i]);
}


short handleSelection(Stack** stack)
{
	int selection = getSelection(OPTIONS_COUNT);
	switch (selection) {
	case 1:
		printFullStack(*stack);
		break;
	case 2:
		addToStack(*stack);
		break;
	case 3:
		popFromStack(*stack);
		break;
	case 4:
		printTopNode(*stack);
		break;
	case 5:
		saveStack(*stack);
		break;
	case 6:
		*stack = readStack(*stack);
		break;
	case 7:
		handleSearch(*stack);
		break;
	case 8:
		removeStack(stack);
		return -1;
	default:
		return 0;
	}

	return 0;
}

void startWithMenu(Stack** stack)
{
	while (true) {
		printMenu();
		if (handleSelection(stack) == -1)
			break;
	}
}



