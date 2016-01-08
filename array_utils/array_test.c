#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"
#include <assert.h>


void test_create_array(){
	ArrayUtil array_1 = create(1, 6);
	ArrayUtil array_2 = create(1, 6);
	assert(array_1.typeSize == 1);
	assert(array_1.length == 6);
	assert(array_2.typeSize == 1);
	assert(array_2.length == 6);	
};

void test_arrays_areEqual(){
	ArrayUtil array_1 = create(1, 6);
	ArrayUtil array_2 = create(1, 6);
	assert(areEqual(array_1, array_2)==1);
};

void test_resize_array(){
	ArrayUtil array_1 = create(1, 6);
	assert(6==array_1.length);
	ArrayUtil array_2=resize(array_1,10);
	assert(array_2.length == 10);
};

void test_findIndex(){
	ArrayUtil array_1 = create(4, 6);
	int element=5;
	int *base = (int *) (array_1.base);
	base[1] = 5;
	assert(findIndex(array_1,&element)==1);
};

int isEven(void *hint, void *item){
	int numberPtr = *(int *)item;
	if(numberPtr % 2 == 0)
		return 1;
	return 0;
};

int isDivisible(void *hint, void *item){
	int *hintElement = ((int*)hint);
	int number = * ((int*) item);
	if(number % *hintElement == 0)
			return 1;
	return 0;
};

void test_findFirst(){
	ArrayUtil util = create(4,6);
	int * base = (int *) util.base;
	base[0] = 1;
	base[1] = 6;
	base[2] = 4;
	int h=2;
	void *hint=&h;
	void  *value =findFirst(util, &isEven, hint);
	assert(*(int *) value == 6);
	void  *result =findFirst(util, &isDivisible, hint);
	assert(*(int *) result == 6);
};

void test_findLast(){
	ArrayUtil util = create(4,6);
	int * base = (int *) util.base;
	base[0] = 1;
	base[1] = 9;
	base[2] = 3;
	base[3] = 2;
	base[4] = 9;
	base[5] = 89;
	int number = 2;
	void * hint = &number;
	int result = *(int * )findLast(util, &isEven, hint);
	assert(result == 2);
	int value = *(int * )findLast(util, &isDivisible, hint);
	assert(value == 2);
};

void test_count(){
	ArrayUtil util = create(4,6);
	int *base = (int *)util.base;
	base[0] = 11;
	base[1] = 22;
	base[2] = 33;
	base[3] = 44;
	base[4] = 58;
	base[5] = 66;
	int no = 2;
	void * hint = &no;
	int value = count(util, &isEven, hint);
	assert(value == 4);
	int result = count(util, &isDivisible, hint);
	assert(result == 4);
};

void test_filter(){
	ArrayUtil util = create(4,6);
	int *base = (int *)util.base;
	base[0] = 11;
	base[1] = 22;
	base[2] = 33;
	base[3] = 44;
	base[4] = 58;
	base[5] = 66;
	int result[] = {22,44,58,66};
	ArrayUtil dest = create(8, 2);
	assert(filter(util, &isEven, NULL, dest.base, dest.length )==2);
	int **temp = dest.base;
	for (int i = 0; i < dest.length; ++i){
		assert(**temp == result[i]);
		temp++;
	}
};

void halves(void* hint, void* sourceItem, void* destinationItem){
	int source = *((int *) sourceItem);
	int *dest = (int *)destinationItem;
	*dest = source/2;
}


void test_map(){
	ArrayUtil source = create(4,4);
	int *base = (int *)source.base;
	base[0] = 12;
	base[1] = 22;
	base[2] = 32;
	base[3] = 42;
	ArrayUtil destination = create(4,4);
	int number = 2;
	void *hint = &number;
	map(source, destination, &halves, hint);	
	int dest = *((int *)destination.base);
	assert(6 == dest);
};

void twice(void * hint, void * item){
	int value = *((int *) item) * 2;
	*(int *)item = value;
};


void test_forEach(){
	ArrayUtil util = create(4,4);
	int *base = util.base;
	base[0] = 12;
	base[1] = 22;
	base[2] = 32;
	base[3] = 42;
	int number = 2;
	void *hint = &number;
	forEach(util, &twice, hint);
	assert(24 == base[0]);
	assert(44 == base[1]);
	assert(64 == base[2]);
	assert(84 == base[3]);
};

void* greater(void* hint, void* previousItem, void* item){
	int *previous = (int *) previousItem;
	int *second = (int *) item;
	if(*previous >= *second)
		return previousItem;
	return item;
}

void test_reduce(){
	ArrayUtil util = create(4,4);
	int *base = util.base;
	base[0] = 12;
	base[1] = 22;
	base[2] = 32;
	base[3] = 42;
	int number = 2;
	void *hint = &number;
	int result = *((int *) reduce(util, &greater, hint, base));
	assert(result == 42);
};

int main(){
	test_reduce();
	return 0;
};




