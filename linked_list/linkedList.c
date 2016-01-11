#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(){
	LinkedList LIST;
	LIST.first = NULL;
	LIST.last = NULL;
	LIST.length = 0;
	return LIST;
};

int add_to_list(LinkedList * LIST,void * value){
	Element *ele = (Element *) malloc (sizeof(Element));
	ele -> value = value;
	ele -> next = NULL;
	if(ele -> next == NULL)
		LIST -> first = LIST -> last = ele;
	else{
		ele -> next = LIST -> last;
		LIST -> last = ele;
	}
	LIST -> length++;
	return LIST -> length;
};