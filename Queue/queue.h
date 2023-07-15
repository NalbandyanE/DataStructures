#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

template <typename T>
class Queue {
public:
	Queue();
	bool empty();
	void enqueue(const T&);
	void dequeue();
	T& peekFront();
private:
	List<T> list;
};

#include "queue.tpp"

#endif // QUEUE_H