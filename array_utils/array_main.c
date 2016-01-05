#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"
#include <assert.h>

void create_array_test(){
	ArrayUtil array_1 = create(1, 6);
	ArrayUtil array_2 = create(1, 6);
	assert(array_1.typeSize == 1);
	assert(array_1.length == 6);
	assert(array_2.typeSize == 1);
	assert(array_2.length == 6);	
};

void arrays_areEqual_test(){
	ArrayUtil array_1 = create(1, 6);
	ArrayUtil array_2 = create(1, 6);
	assert(areEqual(array_1, array_2)==1);
};

void resize_array_test(){
	ArrayUtil array_1 = create(1, 6);
	assert(6==array_1.length);
	ArrayUtil array_2=resize(array_1,10);
	assert(array_2.length == 10);
};

void findIndex_test(){
	ArrayUtil array_1 = create(4, 6);
	int element=5;
	int *base = (int *) (array_1.base);
	base[1] = 5;
	printf("%d\n",findIndex(array_1,&element));
};

int main()
{
	create_array_test();
	arrays_areEqual_test();
	resize_array_test();
	findIndex_test();
	ArrayUtil array_1 = create(1, 6);
	dispose(array_1);
	return 0;
};
