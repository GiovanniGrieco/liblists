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
#pragma once

#define SUCCESS 	0
#define ENOTFOUND 	404

/*
 * NOTES:
 * List structure:
 *  - Always begin counting from 1, not zero
 *  - To enumerate lists, please order the list from the oldest to the newest
 *  - This part is type-agnostic, so we are free to change the structure of
 *	SLNodeData and nothing else.
 */

struct ex__slNodeContent {
	char	*label;
	int 	val;
};
typedef struct ex__slNodeContent SLNodeData;

struct slnode {
	SLNodeData content;
	struct slnode *next;
};
typedef struct slnode  SLNode;
typedef struct slnode* SLList;

/*
 * Add a node to the list
 * PARAMS:
 * 	- Target list
 * 	- Data to associate to the new node
 * OUTPUT:
 *	- Target list with the new node as the first
 */
SLList sllist_addNode(SLList, SLNodeData);

/*
 * Add a bunch of nodes to the list in one call
 * PARAMS:
 *	- Target list
 *	- Number of nodes to add
 *    ... Data to associate to the new nodes
 * OUTPUT:
 * 	- Target list with the new nodes as the first
 */
SLList sllist_addNodes(SLList, int, ...);

/*
 * Insert node to X position. In case X is bigger than the length of the list,
 * null nodes will be added
 * PARAMS:
 *	- Target list
 *	- Position to insert the node
 *	- Data to associate to the new node
 * OUTPUT:
 *	- Updated list
 */
SLList sllist_insertNode(SLList, unsigned int, SLNodeData);

/*
 * Delete node from Nth position
 * PARAMS:
 * 	- Target list
 * 	- Index of the node to remove
 * OUTPUT:
 * 	- SUCCESS || (Error code)
 */
int sllist_delNode(SLList, unsigned int);

/*
 * Change content of Nth node of the list.
 * PARAMS:
 * 	- Target list
 *	- Nth node to edit
 *	- Data to associate to the node
 * OUTPUT:
 *	- SUCCESS || (Error code)
 */
int sllist_editNode(SLList, unsigned int, SLNodeData);

/*
 * Destroy list
 * PARAMS:
 * 	- Target list
 */
void sllist_destroy(SLList);

/*
 * Get list length
 * PARAMS:
 * 	- Target list
 * OUTPUT:
 *	- List length
 */
unsigned int sllist_length(SLList);

/* Invert order of nodes of the list
 * PARAMS:
 *	- Target list
 * OUTPUT:
 *	- Inverted list
 */
SLList sllist_invert(SLList);

/*
 * Exchange a couple of nodes
 * PARAMS:
 * 	- Target list
 *	- Xth node to be exchanged
 *	- Yth node to be exchanged
 * OUTPUT:
 *	- SUCCESS || (Error code)
 */
int sllist_xchg(SLList, unsigned int, unsigned int);
