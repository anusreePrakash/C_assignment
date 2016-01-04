#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

ArrayUtil create(int typeSize, int length){
	ArrayUtil array;
	array.base = calloc (length , typeSize);
	array.typeSize = typeSize;
	array.length = length;
	return array;
};

int areEqual(ArrayUtil array_1, ArrayUtil array_2){
	if(memcmp(array_1.base, array_2.base,array_1.length) == 0)
		return 1;
	return 0;
};

ArrayUtil resize(ArrayUtil util, int length){
	ArrayUtil *newUtil = realloc (util.base , length * util.typeSize);
	return *newUtil;
};