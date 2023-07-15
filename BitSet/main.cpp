#include "bitset.h"

#include <iostream>

int main() {
	BitSet<unsigned long> bitset(25);
	bitset.print_bits();
	bitset.set(1);
	bitset.set(4);
	bitset.set(23);
	bitset.set(17);
	bitset.set(11);
	bitset.print_bits();
	bitset.reset(11);
	bitset.print_bits();

	return 0;
}