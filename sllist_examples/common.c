/*
 * sllist example
 * Common functions available to examples
 */

#include "common.h"

void __printList(SLList list)
{
	puts("Nodes:");
	SLList i = list;
	do {
		printf("\t> %s, %d\n", i->content.label, i->content.val);
	} while ((i = i->next) != NULL);
}

SLList __initExampleList()
{
	return sllist_addNodes(NULL, 3,
		(SLNodeData) {
			.label 	= "Example1",
			.val 	= 333
		},
		(SLNodeData) {
			.label 	= "Example2",
			.val 	= 444
		},
		(SLNodeData) {
			.label 	= "Example3",
			.val 	= 999
		}
	);
}

unsigned int __searchForContent(SLList list, int mode, SLNodeData needle) {
	SLList i = list;
	int	pos = 1,
		check_label = (!mode || mode == 1) ? 1 : 0,
		check_val   = (!mode || mode == 2) ? 1 : 0;

	do {
		if ((!strcmp(needle.label, i->content.label) ||
		     !check_label) &&
		    (needle.val == i->content.val || !check_val))
			return pos;
		pos++;
	} while((i = i->next) != NULL);

	return 0; // node not found
}
