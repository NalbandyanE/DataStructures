#include "blockarray.h" 
#include <iostream>

template <typename T>
BlockArray<T>::BlockArray() {
	blocks.push_back(new Block());
}

template <typename T>
BlockArray<T>::~BlockArray() {
	for (int i = 0; i < blocks.size(); ++i) {
		delete blocks[i];
	}
}

template <typename T>
void BlockArray<T>::push_back(const T& value) {
	Block* lastBlock = blocks.back();
	if (lastBlock->isFull()) {
		blocks.push_back(new Block());
		lastBlock = blocks.back();
	}
	lastBlock->arr[lastBlock->s] = value;
	lastBlock->s++;
}

template <typename T>
const T& BlockArray<T>::operator[](int index) const {
	int blockIndex = index / blocks[0]->blockSize;
	int elementIndex = index % blocks[0]->blockSize;
	return blocks[blockIndex]->arr[elementIndex];
}

template <typename T>
int BlockArray<T>::size() const {
	return (blocks.size() - 1) * blocks[0]->blockSize + blocks.back()->s;
}

template <typename T>
void BlockArray<T>::print() {
	for (int i = 0; i < blocks.size(); ++i) {
		std::cout << "Block " << i << ": ";
		for (int j = 0; j < blocks[i]->s; ++j) {
            std::cout << blocks[i]->arr[j] << " ";
        }
        std::cout << std::endl;
	}
}

template <typename T>
bool BlockArray<T>::empty() {
	return size() == 0;
}

template <typename T>
void BlockArray<T>::clear() {
	for (int i = 0; i < blocks.size(); ++i) {
		delete blocks[i]->arr;
		delete blocks[i];
	}
	blocks.clear();
	blocks.push_back(new Block());
}

template <typename T>
void BlockArray<T>::pop_back() {
	if (empty()) {
		return;
	}
	Block* lastBlock = blocks.back();
	lastBlock->s--;
	if (lastBlock->s == 0 && blocks.size() > 1) {
		delete[] lastBlock->arr;
		delete lastBlock;
		blocks.pop_back();
	}
}

template <typename T>
void BlockArray<T>::insert(int index, const T& val) {
	if (index < 0 || index > size()) {
		throw std::out_of_range{"Index out of range."};
	}
	int blockIndex = index / blocks[0]->blockSize;
    	int elementIndex = index % blocks[0]->blockSize;
    	for (int i = blocks[blockIndex]->s; i > elementIndex; --i) {
        	blocks[blockIndex]->arr[i] = blocks[blockIndex]->arr[i - 1];
    	}
    	blocks[blockIndex]->arr[elementIndex] = val;
    	blocks[blockIndex]->s++;
    	if (blocks[blockIndex]->isFull()) {
        	blocks.insert(blocks.begin() + blockIndex + 1, new Block());
        	Block* nextBlock = blocks[blockIndex + 1];
        	nextBlock->arr[0] = blocks[blockIndex]->arr[blocks[blockIndex]->blockSize - 1];
        	blocks[blockIndex]->s--;
        	nextBlock->s++;
    	}
}

template <typename T>
void BlockArray<T>::erase(int index) {
    	if (index < 0 || index >= size()) {
        	throw std::out_of_range("Index out of range");
    	}
    	int blockIndex = index / blocks[0]->blockSize;
    	int elementIndex = index % blocks[0]->blockSize;
    	for (int i = elementIndex; i < blocks[blockIndex]->s - 1; ++i) {
        	blocks[blockIndex]->arr[i] = blocks[blockIndex]->arr[i + 1];
    	}
    	blocks[blockIndex]->s--;
    	if (blocks[blockIndex]->s == 0 && blocks.size() > 1) {
        	delete[] blocks[blockIndex]->arr;
        	delete blocks[blockIndex];
        	blocks.erase(blocks.begin() + blockIndex);
    	}
}
