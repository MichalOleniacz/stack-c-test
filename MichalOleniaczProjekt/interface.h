//
// Created by Michał Oleniacz on 08/06/2023.
//

#ifndef PROJECT_INTERFACE_H
#define PROJECT_INTERFACE_H

#include "stack.h"
#include "student.h"

void addToStack(Stack* stack);
Student* popFromStack(Stack* stack);
Student* peekAtStack(Stack* stack);
void printTopNode(Stack* stack);
void printFullStack(Stack* stack);
void removeStack(Stack** stack);
void saveStack(Stack* stack);
Stack* readStack(Stack *stack);
void handleSearch(Stack* stack);
Student* searchInStack(Stack* stack, Student* searchStruct, bool(*compareFn)(void*, void*));


#endif //PROJECT_INTERFACE_H
