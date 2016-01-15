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

typedef int (MatchFunc)(void* , void* );

typedef void (*ConvertFunc)(void* , void* , void* );

typedef void* (Reducer)(void* hint, void* previousItem, void* item);

LinkedList createList();

int add_to_list(LinkedList * list,void * value);

void *get_first_element(LinkedList list);

void *get_last_element(LinkedList list);

void forEach(LinkedList list, ElementProcessor func);

void * getElementAt(LinkedList list, int no);

int indexOf(LinkedList list, void * element);

void * deleteElementAt(LinkedList * list, int);

void printList(LinkedList);

int dividedBy(void * hint, void* element);

int asArray(LinkedList list, void ** array, int maxElements);

LinkedList filter(LinkedList list, MatchFunc function, void * hint);

LinkedList reverse(LinkedList list);

LinkedList map(LinkedList, ConvertFunc, void * );
