#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include <assert.h>

void test_createList(){
	assert(createList().first == NULL);
	assert(createList().last == NULL);
	assert(createList().length == 0);
};

void test_add_to_list(){
	LinkedList list;
	int no = 3;
	void * value = &no;
	int list_length = add_to_list(&list, &value);
	assert(list_length == 1);
	int no2 = 4;
	void * value2 = &no2;
	add_to_list(&list, &value2);
	int no3 = 5;
	void * value3 = &no3;
	add_to_list(&list, &value3);
	int no4 = 6;
	void * value4 = &no4;
	int length = add_to_list(&list, &value4);
	assert(length == 4);
};

