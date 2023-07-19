#ifndef BLOCKARRAY_H
#define BLOCKARRAY_H

#include <vector>

template <typename T>
class BlockArray {
public:
	BlockArray();
	~BlockArray();
	void push_back(const T&);
	const T& operator[](int) const;
	int size() const;
	void print();
	bool empty();
	void clear();
	void pop_back();
	void insert(int, const T&);
	void erase(int); 
private:
	struct Block {
		int blockSize;
		T* arr;
		int s;
		Block() : blockSize{8}, arr{new T[blockSize]}, s{0} {}
		bool isFull() const {return s == blockSize;}
	};
	std::vector<Block*> blocks;
};

#include "blockarray.tpp"

#endif // BLOCKARRAY_H