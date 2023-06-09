//
// Created by Michał Oleniacz on 08/06/2023.
//

#include "interface.h"
#include "stack.h"
#include "student.h"
#include "utils.h"
#include "stdio.h"
#include <string.h>

#define SEARCH_OPTIONS_COUNT 5

static const char* searchOptions[SEARCH_OPTIONS_COUNT] = {
		"Search options:",
		"1 \t Search by name",
		"2 \t Search by subject",
		"3 \t Search by birth year",
		"4 \t Cancel",
};

void printSearchMenu()
{
	for (int i = 0; i < SEARCH_OPTIONS_COUNT; i++)
		printf("%s\n", searchOptions[i]);
}


void addToStack(Stack* stack)
{
	char lastname[512], studies[512];
	int year = 0;

	printf("Last name:\n");
	scanf_s("%s", lastname);

	size_t size = (strlen(lastname) + 1) * sizeof(char);
	char *lastnamePtr = (char *)malloc(size);
	if (lastnamePtr == NULL) handleMallocFailure("addToStack/Surname");
	strcpy_s(lastnamePtr, size, lastname);

	printf("Field of study: (IT, CHEM, MATH, PSY, others will be categorized as OTHER\n");
	scanf_s("%s", studies);

	Studies studiesId = getStudiesId(studies);

	printf("Birth year:\n");
	scanf_s("%d", &year);

	Student* newStudent = initStudent(lastname, year, studiesId);

	pushStack(stack, (void**)newStudent);

	return;
}

Student *popFromStack(Stack* stack)
{
	if (stack == NULL) {
		printf("Stack does not exist!\n");
		return NULL;
	}
	if (stack->size == 0) {
		printf("Empty Stack.\n");
		return NULL;
	}
	Node* topNode = popStack(stack);
	Student* student = (Student*)topNode->data;
	return student;
}

Student *peekAtStack(Stack* stack)
{
	if (stack == NULL)
		return NULL;

	if (stack->size == 0) {
		printf("Empty Stack.\n");
		return NULL;
	}

	Node* topNode = peekStack(stack);
	Student* student = (Student*)topNode->data;
	return student;
}

void printFullStack(Stack* stack)
{
	if (stack == NULL)
		return;

	if (stack->size == 0) {
		printf("Empty Stack.\n");
		return;
	}

	printf("Printing Stack\n");

	Node* tmp = stack->top;
	while (tmp != NULL) {
		printStudent((Student*)tmp->data);
		tmp = tmp->next;
	}
}

Student* searchInStack(Stack* stack, Student* searchStruct, bool(*compareFn)(void*, void*))
{
	Node* result = searchStack(stack, searchStruct, compareFn);
	if (result == NULL)
		return NULL;
	return (Student*)result->data;
};

void printTopNode(Stack* stack)
{
	Student* student = peekAtStack(stack);
	if (student == NULL)
		return;
	printStudent(student);
}

void handleSearch(Stack* stack)
{
	printSearchMenu();
	int selection = getSelection(SEARCH_OPTIONS_COUNT);

	Student compareStudentStruct;
	void *result = NULL;

	switch (selection) {
	case 1:
		char lastname[512];

		printf("Name:\n");
		scanf_s("%s", lastname);

		compareStudentStruct.lastName = lastname;

		result = searchInStack(stack, &compareStudentStruct, searchByName);
		break;
	case 2:
		char studies[512];

		printf("Studies subject:\n");
		scanf_s("%s", studies);

		compareStudentStruct.studies = getStudiesId(studies);
		result = searchInStack(stack, &compareStudentStruct, searchByStudy);
		break;
	case 3:
		int year;

		printf("Year:\n");
		scanf_s("%d", &year);

		compareStudentStruct.birthYear = year;
		result = searchInStack(stack, &compareStudentStruct, searchByYear);
		break;
	case 4:
		return;
	}

	if (result != NULL)
		printStudent((Student*)result);
	else
		printf("No matches found!\n");

	return;
}

void removeStack(Stack** stack)
{
	destroyStack(stack, freeStudent);
	return;
}

void saveStack(Stack* stack)
{
	FILE* file;
	fopen_s(&file, "students.bin", "wb");
	if (file == NULL) handleFileOpenFailure("saveStack:");
	serializeStack(stack, file, serializeStudent);
	if (file != NULL) fclose(file);
	return;
}

Stack* readStack(Stack *stack)
{
	FILE* file;
	fopen_s(&file, "students.bin", "rb");
	if (file == NULL) handleFileOpenFailure("saveStack:");
	if (stack != NULL) {
		destroyStack(&stack, freeStudent);
	}

	Stack* newStack = deserializeStack(file, deserializeStudents);

	// printStudent((Student*)stack->top->data);

	return newStack;
}
