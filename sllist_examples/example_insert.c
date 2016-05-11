/*
 * sllist example
 * Generate 3 nodes, insert another one at position 2 and print the list
 */

#include "common.h"

int main()
{
	SLList list = __initExampleList();

	SLNodeData insert = {
		.label  = "Here I am!",
		.val 	= 111
	};

	list = sllist_insertNode(list, 2, insert);

	__printList(list);

	sllist_destroy(list);
	return 0;
}
