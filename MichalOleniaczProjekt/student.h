//
// Created by Michał Oleniacz on 05/06/2023.
//

#ifndef PROJEKT_STUDENT_H
#define PROJEKT_STUDENT_H

#include "error.h"

#define NO_FIELDS 6
#define MAX_DESERIALIZE_BATCH 512

enum Studies {
	IT,
	MATH,
	CHEM,
	PSY,
	SOCIAL,
	OTHER
};

typedef struct {
	char* lastName;
	int birthYear;
	Studies studies;
} Student;

Student* initStudent(const char *lastName, int birthYear, Studies studies);
Student* initEmptyStudent();
void freeStudent(void** s);
void serializeStudent(void* s, FILE* file);
void** deserializeStudents(FILE* file);
void printStudent(Student* student);
Studies getStudiesId(const char *value);
char *getStudyFieldName(Studies id);
bool searchByName(void* data, void* searchResult);
bool searchByStudy(void* data, void* searchResult);
bool searchByYear(void* data, void* searchResult);

#endif //PROJEKT_STUDENT_H
