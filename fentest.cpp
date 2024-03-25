#include "fenwick.h"
#include <cassert>
#include <iostream>

int main() {
	FenwickTree fen(100);
	
	fen.update(1, 1);
	fen.update(2, 2);
	fen.update(3, 3);
	fen.update(4, 4);
	fen.update(5, 5);
	
	assert(fen.rsq(1) == 1);
	assert(fen.rsq(2) == 1+2);
	assert(fen.rsq(3) == 1+2+3);
	
	assert(fen.rsq(1, 1) == 1);
	assert(fen.rsq(1, 2) == 1+2);
	assert(fen.rsq(1, 3) == 1+2+3);
	
	return 0;
}