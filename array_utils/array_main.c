#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

int main(){
	ArrayUtil a = create(1, 6);
	ArrayUtil b = create(1, 6);
	areEqual(a, b);
	resize(a, 10);
}