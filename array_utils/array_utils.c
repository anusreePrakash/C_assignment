#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

ArrayUtil create(int typeSize, int length){
	ArrayUtil array;
	array.base =  calloc (length , typeSize);
	array.typeSize = typeSize;
	array.length = length;
	return array;
};

int areEqual(ArrayUtil array_1, ArrayUtil array_2){
	if((memcmp(array_1.base, array_2.base,array_1.length) == 0) && (array_1.length == array_2.length) && (array_1.typeSize == array_2.typeSize))
		return 1;
	return 0;
};

ArrayUtil resize(ArrayUtil util, int length){
	util.base = realloc (util.base , length * util.typeSize);
	util.length = length;
	return util;
};

int findIndex(ArrayUtil util, void * element){
	for (int i = 0; i < util.length; ++i){
		if(*(int *)(util.base+i) == *(int *)element)
			return i;
	};
		return -1;
};

void dispose(ArrayUtil util){
	free(util.base);
	util.typeSize = 0;
	util.length = 0;
};
