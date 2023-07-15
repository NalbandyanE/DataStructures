#include "queue.h"
#include <stdexcept>

template <typename T>
Queue<T>::Queue() = default;

template <typename T>
bool Queue<T>::empty() {
	return list.empty();
}

template <typename T>
void Queue<T>::enqueue(const T& val) {
	list.push_back(val);
}

template <typename T>
void Queue<T>::dequeue() {
	list.pop_front();
}

template <typename T>
T& Queue<T>::peekFront() {
	if (empty()) {
		throw std::runtime_error{"Queue is empty."};
	}
	return list.getHeadValue();
}