#include "bitset.h"
#include <stdexcept>
#include <iostream>

template <typename T>
BitSet<T>::BitSet(unsigned long s) 
	: size{s}, 
	bit_count{64}, 
	array_size{s / bit_count + 1}, 
	bit_array{new T[array_size]}
{
}

template <typename T>
void BitSet<T>::setSize(unsigned long s) {
	size = s;
}

template <typename T>
unsigned long BitSet<T>::getSize() const {
	return size;
}

template <typename T>
void BitSet<T>::setBit_count(unsigned long bc) {
	bit_count = bc;
}

template <typename T>
unsigned long BitSet<T>::getBit_count() const {
	return bit_count;
}

template <typename T>
void BitSet<T>::setArray_size(unsigned long as) {
	array_size = as;
}

template <typename T>
unsigned long BitSet<T>::getArray_size() const {
	return array_size;
}

template <typename T>
void BitSet<T>::set(unsigned long index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range{"Index out of range."};
	}
	bit_array[index / bit_count] |= 1 << (index % bit_count); 
}

template <typename T>
void BitSet<T>::reset(unsigned long index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range{"Index out of range."};
	}
	bit_array[index / bit_count] &= ~(1 << (index % bit_count));
}

template <typename T>
bool BitSet<T>::bit(unsigned long index) const {
	return (bit_array[index / bit_count] & (1 << (index % bit_count))) != 0;
}

template <typename T>
void BitSet<T>::print_bits() const {
	for (int i = size - 1; i >= 0; --i) {
		std::cout << bit(i);
	}
	std::cout << std::endl;
}

template <typename T>
BitSet<T>::~BitSet() {
	delete[] bit_array;
}