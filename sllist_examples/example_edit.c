/*
 * sllist example
 * Generate 3 elements and print the list in order
 */

#include "common.h"

int main()
{
	SLList list = __initExampleList();

	SLNodeData edit = {
		.label = "edited!",
		.val   = 101
	};

	int retCode = 0;
	if (!(retCode = sllist_editNode(list, 2, edit))) {
		__printList(list);
	} else {
		puts("*** Error while editing node");
		switch (retCode) {
		case 404:
			puts("\tNode not found");
		}
	}

	sllist_destroy(list);
	return 0;
}
