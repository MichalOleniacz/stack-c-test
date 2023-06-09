//
// Created by Michał Oleniacz on 05/06/2023.
//

#include "node.h"
#include "stdlib.h"

Node* initNode(void *data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) handleMallocFailure("initNode/Node:");

	node->data = data;
	node->next = NULL;

	return node;
}

void destroyNode(Node** node, void(*destroyData)(void**))
{
	if (*node == NULL)
		return;

	destroyData((void**)&((*node)->data));
	if (node == NULL)
		return;
	free(*node);
	*node = NULL;
}



