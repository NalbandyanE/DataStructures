#include "queue.h"
#include <iostream>

int main() {
	Queue<int> queue;
	queue.enqueue(12);
	queue.enqueue(17);
	queue.enqueue(19);
	queue.enqueue(11);
	std::cout << queue.peekFront() << std::endl;
	queue.dequeue();
	std::cout << queue.peekFront() << std::endl;

	return 0;
}