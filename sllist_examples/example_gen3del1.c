/*
 * sllist example
 * Generate 3 elements, deletes one and print the list
 */

#include "common.h"

int main()
{
	SLList list = __initExampleList();

	sllist_delNode(list, 2);

	__printList(list);

	sllist_destroy(list);
	return 0;
}
