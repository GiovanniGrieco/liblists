/*
 * sllist example
 * Common functions available to examples
 */
#pragma once

#include <stdio.h>
#include <string.h>

#include "../sllist.h"

void __printList(SLList);
SLList __initExampleList();
unsigned int __searchForContent(SLList, int, SLNodeData);
