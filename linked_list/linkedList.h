typedef struct element{
	void * value;
	struct element * next;
} Element;

typedef struct{
	Element * first; 
	Element * last;
	int length; 
} LinkedList;

typedef void (*ElementProcessor)(void *);

LinkedList createList();

int add_to_list(LinkedList * list,void * value);

void *get_first_element(LinkedList list);

void *get_last_element(LinkedList list);

void forEach(LinkedList list, ElementProcessor func);

void * getElementAt(LinkedList list, int no);

int indexOf(LinkedList list, void * element);

// void * deleteElementAt(LinkedList * list, int)