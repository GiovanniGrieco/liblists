/*
 * sllist.c - NULL terminated single linked list
 *
 * Copyright (C) 2016  Giovanni Grieco <giovanni.grc96@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 * I left here my email address. Feel free to contact me in case something is
 * wrong or just to give me a symbolic "f___ you" if you think my coding skills
 * are terrible. I'm working hard on improving myself, so critiques are welcomed
 */

#include <stdlib.h>	// malloc, free
#include <stdarg.h>	// variadic functions

#include "sllist.h"

SLList sllist_addNode(SLList list, SLNodeData content)
{
	SLList newNode = malloc(sizeof(SLNode));

	newNode->content = content;
	newNode->next	 = list;

	return newNode;
}

SLList sllist_addNodes(SLList list, int nNodes, ...)
{
	va_list nodes;

	va_start(nodes, nNodes);
	while (nNodes--) {
		list = sllist_addNode(list, va_arg(nodes, SLNodeData));
	}
	va_end(nodes);

	return list;
}

SLList sllist_insertNode(SLList list, unsigned int X, SLNodeData content)
{
	SLList 	node_index = list,
		node_prev  = NULL;

	unsigned int	i = 1,
			llen = sllist_length(list);
	while (llen--) {
		if (i == X) {
			SLList newNode = malloc(sizeof(SLNode));
			newNode->content = content;
			newNode->next	 = node_index;

			node_prev->next = newNode;

			return list;
		}

		node_prev  = node_index;
		node_index = node_index->next;
		i++;
	}

	X = X - i;
	while (X--) {
		list = sllist_addNode(list, (SLNodeData) {NULL});
	}

	list = sllist_addNode(list, content);

	// it's impossible to go ahead the first node
	return list;
}

int sllist_delNode(SLList list, unsigned int n)
{
	SLList  node_prev = NULL,
		node_2del = list;

	// search Nth node in the list
	unsigned int i = 1;
	while (i < n && node_2del != NULL) {
		node_prev = node_2del;
		node_2del = node_2del->next;
		i++;
	}

	if (node_2del == NULL)
		return ENOTFOUND;

	node_prev->next = node_2del->next;
	free(node_2del);

	return SUCCESS;
}

int sllist_editNode(SLList list, unsigned int X, SLNodeData content)
{
	unsigned int llen = sllist_length(list);

	for (unsigned int i = 1; i <= llen; i++) {
		if (i == X) {
			list->content = content;
			return SUCCESS;
		}

		list = list->next;
	}

	return ENOTFOUND;
}

void sllist_destroy(SLList list)
{
	// 2 pointers to save position while destroying it
	SLList i = list;

	while (list != NULL) {
		i = list->next;
		free(list);
		list = i;
	}
}

unsigned int sllist_length(SLList list)
{
	int i = 0;
	while (list != NULL) {
		i++;
		list = list->next;
	}
	return i;
}

SLList sllist_invert(SLList list)
{
	SLList  inverted = NULL,
		oldList = list;

	do {
		inverted = sllist_addNode(inverted, list->content);
	} while ((list = list->next) != NULL);

	sllist_destroy(oldList);

	return inverted;
}

int sllist_xchg(SLList list, unsigned int X, unsigned int Y)
{
	SLNodeData *node_prev = NULL;
	unsigned int llen = sllist_length(list),
		     i = 1;

	/*
	 * First cycle checks if X or Y exists; if so then we proceed to the
	 * second cycle which checks the other and exchange them.
	 */

	do {
		if (i == X || i == Y)
			node_prev = &list->content;

		i++;
		list = list->next;
	} while (i <= llen && node_prev == NULL);

	while (i <= llen) {
		if (i == X || i == Y) {
			// temporary auxiliry to exchange
			SLNodeData aux = *node_prev;

			*node_prev = list->content;
			list->content = aux;

			return SUCCESS;
		}

		i++;
		list = list->next;
	}

	// il ciclo è terminato senza scambi
	return ENOTFOUND;
}
