//
// Created by Michał Oleniacz on 06/06/2023.
//

#include "error.h"

void handleMallocFailure(const char *shortLog)
{
	printf("%s\tMemory Allocation Failure! Exiting...", shortLog);
	exit(EXIT_FAILURE);
}

void handleOutOfRange(const char *shortLog)
{
	printf("%s\tIndex out of range! Exiting...", shortLog);
	exit(EXIT_FAILURE);
}

void handleFileOpenFailure(const char *shortLog)
{
	printf("%s\tFailed to open file! Exiting...", shortLog);
	exit(EXIT_FAILURE);
}