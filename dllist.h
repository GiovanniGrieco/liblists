/*
 * dllist.c - NULL terminated double linked list
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
#pragma once

#define SUCCESS		0
#define ENOTFOUND	404

struct ex__dlNodeContent {
	char	*label;
	int	val;
};
typedef struct ex__dlNodeContent DLNodeData;

struct dlnode {
	struct dlnode *prev;
	DLNodeData  content;
	struct dlnode *next;
};
typedef struct dlnode  DLNode;
typedef struct dlnode* DLList;

/*
 * Add a node to the list
 * PARAMS:
 *	- Target list
 *	- Data to associate to the new node
 * OUTPUT:
 *	- Target list with the new node as the first
 */
DLList dllist_addNode(DLList, DLNodeData);

/*
 * Add a bunch of nodes to the list in one call
 * PARAMS:
 *	- Target list
 *	- Number of nodes to add
 *    ... Data to associate to the new nodes
 * OUTPUT:
 *	- Target list with the new nodes as the first
 */
DLList dllist_addNodes(DLList, int, ...);

/*
 * Insert a node to X position. In case X is bigger than the length of the list,
 * null nodes will be added
 * PARAMS:
 *	- Target list
 *	- Position to insert the node
 *	- Data to associate to the new node
 * OUTPUT:
 *	- Updated list
 */
DLList dllist_insertNode(DLList, unsigned int, DLNodeData);

/*
 * Delete node from Nth position
 * PARAMS:
 *	- Target list
 *	- Nth node to edit
 *	- Data to associate to the node
 * OUTPUT:
 *	- SUCCESS || (Error code)
 */
int dllist_editNode(DLList, unsigned int, DLNodeData);

/*
 * Destroy list
 * PARAMS:
 *	- Target list
 */
void dllist_destroy(DLList);

/*
 * Get list length
 * PARAMS:
 *	- Target list
 * OUTPUT:
 *	- List length
 */
unsigned int dllist_length(DLList);

/*
 * Exchange a couple of nodes
 * PARAMS:
 *	- Target list
 *	- Xth node to be exchanged
 *	- Yth node to be exchanged
 * OUTPUT:
 *	- SUCCESS || (Error code)
 */
int dllist_xchg(DLList, unsigned int, unsigned int);
