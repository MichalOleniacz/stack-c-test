#include <iostream>
#include "stack.h"
#include "menu.h"

int main()
{
	//    int STACK_ID = 1;
	Stack* stack = initStack();

	startWithMenu(&stack);
	return 0;
}
