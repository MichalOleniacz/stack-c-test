//
// Created by Michał Oleniacz on 06/06/2023.
//

#ifndef PROJEKT_ERROR_H
#define PROJEKT_ERROR_H

#include <stdio.h>
#include <stdlib.h>

void handleMallocFailure(const char *shortLog);
void handleOutOfRange(const char *shortLog);
void handleFileOpenFailure(const char *shortLog);

#endif //PROJEKT_ERROR_H
