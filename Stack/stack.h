#ifndef STACK_H
#define STACK_H

#include "list.h"

template <typename T>
class Stack {
public:
	Stack();
	bool empty();
	int size();
	void push(const T&);
	void pop();
	T top();
private:
	List<T> list;
};

#include "stack.tpp"

#endif // STACK_H