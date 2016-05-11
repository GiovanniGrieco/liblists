/*
 * sllist example
 * Generate 3 elements and print the list in order
 */

#include "common.h"

int main()
{
	SLList list = __initExampleList();

	__printList(list);

	sllist_destroy(list);
	return 0;
}
