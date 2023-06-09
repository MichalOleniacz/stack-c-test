//
// Created by Michał Oleniacz on 05/06/2023.
//

#ifndef PROJEKT_NODE_H
#define PROJEKT_NODE_H

#include "error.h"

typedef struct Node {
	void *data;
	Node* next;
} Node;

Node* initNode(void *data);
void destroyNode(Node** node, void(*destroyData)(void**));

#endif //PROJEKT_NODE_H
