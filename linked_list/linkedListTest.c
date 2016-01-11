#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include <assert.h>

void test_createList(){
	createList();
	assert(createList().first == NULL);
}


// int main(){
	// LinkedList list;
	// int add_to_list(LinkedList *,void *);
	// get_last_element(LinkedList list);
	// forEach(LinkedList, ElementProcessor e)
// };