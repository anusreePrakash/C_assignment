typedef struct element{
	void * value;
	struct element * next;
} Element;

typedef struct{
	Element * first;
	Element * last;
	int length; 
} LinkedList;

LinkedList createList();
int add_to_list(LinkedList * list,void * value);