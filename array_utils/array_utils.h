typedef struct {
	void * base;
	int typeSize;
	int length;
} ArrayUtil;

ArrayUtil create(int typeSize, int length);
int areEqual(ArrayUtil a, ArrayUtil b);
ArrayUtil resize(ArrayUtil util, int length);