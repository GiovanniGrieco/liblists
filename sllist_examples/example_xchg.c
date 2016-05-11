/*
 * sllist example
 * Generate 3 nodes, exhange node 2 with 3 and print list
 */

#include "common.h"

int main()
{
	SLList list = __initExampleList();

	int retCode = 0;
	if (!(retCode = sllist_xchg(list, 2, 3))) {
		__printList(list);
	} else {
		puts("*** Error while exchanging nodes");
		switch (retCode) {
		case 404:
			puts("\tNode not found");
		}
	}

	sllist_destroy(list);
	return 0;
}
