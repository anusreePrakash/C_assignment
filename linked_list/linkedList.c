#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

LinkedList createList(){
	LinkedList LIST;
	LIST.first = NULL;
	LIST.last = NULL;
	LIST.length = 0;
	return LIST;
};

int add_to_list(LinkedList * LIST,void * value){
	Element *ele = malloc (sizeof(Element));
	ele -> value = value;
	ele -> next = NULL;
	if(LIST -> first == NULL)
		LIST -> first = LIST -> last = ele;
	else{
		LIST -> last -> next = ele;
		LIST -> last = ele;
	}
	LIST -> length++;
	return LIST -> length;
};

void *get_first_element(LinkedList LIST){
	if(LIST.first -> value == NULL)
		printf("list is empty");
	return LIST.first -> value;
};

void *get_last_element(LinkedList LIST){
	if(LIST.last -> value == NULL)
		printf("list is empty");
	return LIST.last -> value;
};

void forEach(LinkedList list, ElementProcessor func){
	for(int i = 0; i< list.length; i++){
		func(list.first -> value);
		list.first = list.first -> next;
	}
};

void * getElementAt(LinkedList list, int index){
	for(int i = 0; i< list.length; i++){
		if(index == i)
			return list.first -> value;
		list.first = list.first -> next;
	}
	return NULL;
};

int indexOf(LinkedList list, void * element){
	for(int i = 0; i < list.length; i++){
		if(element == list.first -> value)
			return i;
		list.first = list.first -> next;
	}
	return -1;
};
void * deleteElementAt(LinkedList * list, int index){
	Element *head = list -> first;
	void *valueAtHead ;
	if(index >= list -> length || index < 0)
		return NULL;
	if(index == 0){
		valueAtHead = head -> value;
		list -> first  = head -> next;
		list -> length--;
		return valueAtHead;
	}

	else{
		for(int i = 0; i<index-1; i++){
			head=head->next;
		}      
	valueAtHead = head -> next -> value;
	head->next  = head -> next -> next;
	list -> length--;
		return valueAtHead;
	}
	return NULL;
};

void printList(LinkedList list){
	Element *ele = list.first;
	while(ele!=NULL){
		printf("%d\n", *(int *)ele->value);
		ele = ele->next;
	}
}

	













