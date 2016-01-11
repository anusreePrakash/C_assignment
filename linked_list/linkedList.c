#include <stdio.h>
#include "stdlib.h"
#include "linkedList.h"

LinkedList createList(){
	LinkedList LIST;
	LIST.first = NULL;
	LIST.last = NULL;
	LIST.length = 0;
	return LIST;
};