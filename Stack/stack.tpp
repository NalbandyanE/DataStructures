#include "stack.h"

template <typename T>
Stack<T>::Stack() = default;

template <typename T>
bool Stack<T>::empty() {
	return list.empty();
}

template <typename T>
int Stack<T>::size() {
	return list.size();
}

template <typename T>
void Stack<T>::push(const T& val) {
	list.push_back(val);
}

template <typename T>
void Stack<T>::pop() {
	list.pop_back();
}

template <typename T>
T Stack<T>::top() {
	return list.back();
}