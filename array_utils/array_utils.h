typedef struct {
	void * base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int (MatchFunc) (void * , void *);

ArrayUtil create(int typeSize, int length);
int areEqual(ArrayUtil a, ArrayUtil b);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void* element);
void * findFirst(ArrayUtil util, MatchFunc * match, void* hint);
void dispose(ArrayUtil util);
