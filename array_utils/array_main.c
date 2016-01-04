#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"
#include <assert.h>

int main(){
	ArrayUtil a = create(1, 6);
	assert(a.typeSize == 1);
	assert(a.length == 6);
	ArrayUtil b = create(1, 6);
	assert(b.typeSize == 1);
	assert(b.length == 6);
	areEqual(a, b);
	assert(a.length == b.length);
	ArrayUtil newArray =  resize(a, 10);
	assert(newArray.length == 10);
	int element = 8;
	findIndex(a, &element);
	int element2 = 0;
	assert(findIndex(a, &element2) == 0);
};