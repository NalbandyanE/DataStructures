#ifndef BITSET_H
#define BITSET_H

template <typename T>
class BitSet {
public:
	BitSet(unsigned long);
	void setSize(unsigned long);
	unsigned long getSize() const;
	void setBit_count(unsigned long);
	unsigned long getBit_count() const;
	void setArray_size(unsigned long);
	unsigned long getArray_size() const;
	void set(unsigned long);
	void reset(unsigned long);
	bool bit(unsigned long) const;
	void print_bits() const;
	~BitSet();
private:
	unsigned long size;
	unsigned long bit_count;
	unsigned long array_size;
	T* bit_array;
};

#include "bitset.tpp"

#endif // BITSET_H