/*
 * sllist example
 * Generate 3 nodes, invert the order and print the list
 */

#include "common.h"

int main()
{
	SLList list = __initExampleList();

	list = sllist_invert(list);

	__printList(list);

	sllist_destroy(list);
	return 0;
}
