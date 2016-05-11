/*
 * sllist example
 * Generate 3 nodes, search for a content and print the position
 */

#include "common.h"

int main()
{
	SLList list = __initExampleList();

	int pos = __searchForContent(list, 0, (SLNodeData) {
		.label = "Example2",
		.val   = 444
	});

	printf("Position of the node: %d\n", pos);

	sllist_destroy(list);
	return 0;
}
