#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include <assert.h>
#include <string.h>

void test_createList(){
	assert(createList().first == NULL);
	assert(createList().last == NULL);
	assert(createList().length == 0);
};

void test_add_to_list(){
	LinkedList list = createList();
	int no = 3;
	void * value = &no;
	int list_length = add_to_list(&list, value);
	int element = *((int *)(list.first -> value));
	assert(element == 3);
	assert(list_length == 1);
	int no2 = 4;
	void * value2 = &no2;
	int k = *((int *)(list.first -> value));
	add_to_list(&list, &value2);
	int no3 = 5;
	void * value3 = &no3;
	add_to_list(&list, &value3);
	int no4 = 6;
	void * value4 = &no4;
	int length = add_to_list(&list, &value4);
	assert(length == 4);
};

void test_get_first_element(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	int firstElement = *((int *)get_first_element(list));
	assert(firstElement == 3);
};

void test_get_last_element(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	int lastElement = *((int *)get_last_element(list));
	assert(lastElement == 6);
};

void increment(void* element){
	int number = *((int *)element);
	*(int *)element = number+1;
};

void test_forEach(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	forEach(list,increment);
	int first = *((int *)list.last->value);
	assert(first == 7);
	assert(no == 4);
	assert(no2 == 5);
	assert(no3 == 6);
	assert(no4 == 7);
};

void test_getElementAt(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	int element = *(int *)(getElementAt(list, 2));
	assert(element == 5);
};

void test_indexOf(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	int index = indexOf(list, &no2);
	int index2 = indexOf(list, &no3);
	assert(index == 1);
	assert(index2 == 2);
};

void test_deleteElementAt(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	assert(deleteElementAt(&list, -1) == NULL);
	assert(deleteElementAt(&list, 11) == NULL);
};

void test_deleteElementAt_should_return_the_reference_of_the_first_element_if_index_is_0(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	int y = *(int *)deleteElementAt(&list, 0);
	assert(y == no);
	// printList(list);
};

void test_deleteElementAt_should_return_the_reference_at_the_deleted_node(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	int result = *(int *)deleteElementAt(&list, 2);
	assert(result == no3);
};

void test_asArray(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	void * array = calloc(list.length, sizeof(int));
	int maxElements = 4;
	int ArrayLength = asArray(list, array, maxElements);
	assert(ArrayLength == 4);
	for (int i = 0; i < maxElements; i++){
		assert(**(int **)array+i == *((int *)list.first -> value));
		list.first = list.first -> next;
	}
};

void test_filter(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	int hint = 2;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	LinkedList newList = filter(list, dividedBy, &hint);
	assert(*(int *) newList.first -> value == 4);
	assert(*(int *) newList.last -> value == 6);
	// printList(newList);	
};

void test_reverse(){
	LinkedList list = createList();
	int no = 3;
	int no2 = 4;
	int no3 = 5;
	int no4 = 6;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	LinkedList newList = reverse(list);
	assert(*(int *) newList.first -> value == 6);
	assert(*(int *) newList.last -> value == 3);
	// printList(newList);	
};

void halves(void* hint, void* sourceItem, void* destinationItem){
	int *dest = malloc(sizeof(int));
	*dest = (*(int *)sourceItem)/2; 
	memcpy(destinationItem, &dest, 8);
};

void test_map(){
	LinkedList list = createList();
	int no = 6;
	int no2 = 4;
	int no3 = 10;
	int no4 = 46;
	int hint = 2;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	LinkedList newList = map(list, halves, &hint);
	assert(*(int *) newList.first -> value == 3);
	assert(*(int *) newList.last -> value == 23);
};

void *greaterThan(void* hint, void* previousItem, void* item){
	int *previous = (int *) previousItem;
	int *second = (int *) item;
	if(*previous >= *second)
		return previousItem;
	return item;
}

void test_reduce(){
	LinkedList list = createList();
	int no = 6;
	int no2 = 4;
	int no3 = 10;
	int no4 = 46;
	int hint = 2;
	add_to_list(&list, &no);
	add_to_list(&list, &no2);
	add_to_list(&list, &no3);
	add_to_list(&list, &no4);
	int initialValue = 0;
	int greatest = *(int *)reduce(list, &greaterThan, &hint, &initialValue);
	assert(greatest == 46);
};