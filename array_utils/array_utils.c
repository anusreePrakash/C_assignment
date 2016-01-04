#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

ArrayUtil create(int typeSize, int length){
	ArrayUtil *array;
	array = (void * ) calloc (length , typeSize);
	array->base = array;
	array->typeSize = typeSize;
	array->length = length;
	return *array;
};

int areEqual(ArrayUtil a, ArrayUtil b){
	return 0;
}
