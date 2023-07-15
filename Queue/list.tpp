#include "list.h"
#include <iostream>
#include <stdexcept>

template <typename T>
List<T>::List() : head{nullptr}, tail{nullptr} {}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
	if (this == &other) {
		return *this;
	}
	clear();
	Node* current = other.head;
	while (current) {
		push_back(current->value);
		current = current->next;
	}
	return *this;
}

template <typename T>
bool List<T>::find(const T& val) {
	bool flag = false;
	Node* current = head;
	while (current) {
		if (current->value == val) {
			flag = true;
			break;
		}
		current = current->next;
	}
	return flag;
}

template <typename T>
void List<T>::traverse() {
	Node* current = head;
	while (current) {
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

template <typename T>
bool List<T>::empty() {
	if (!head && !tail) {
		return true;
	}
	return false;
}

template <typename T>
int List<T>::size() {
	int s = 0;
	Node* current = head;
	while (current) {
		current = current->next;
		s++;
	}
	return s;
}

template <typename T>
void List<T>::clear() {
	if (empty()) {
		return;
	}
	while (head) {
		pop_back();
	}
}

template <typename T>
T List<T>::front() {
	if (empty()) {
		throw std::runtime_error("List is empty.");
	}
	return head->value;
}

template <typename T>
T List<T>::back() {
	if (empty()) {
		throw std::runtime_error("List is empty.");
	}
	return tail->value;
}

template <typename T>
void List<T>::push_front(const T& val) {
	Node* newNode = new Node(val);
	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

template <typename T>
void List<T>::push_back(const T& val) {
	Node* newNode = new Node(val);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

template <typename T>
void List<T>::pop_front() {
	if (!head) {
		throw std::runtime_error("List is empty.");
	}
	Node* tmp = head;
	head = head->next;
	if (head) {
		head->prev = nullptr;
	}
	else {
		tail = nullptr;
	}
	delete tmp;
}

template <typename T>
void List<T>::pop_back() {
	if (empty()) {
		throw std::runtime_error("List is empty.");
	}
	Node* tmp = tail;
	tail = tail->prev;
	if (tail) {
		tail->next = nullptr;
	}
	else {
		head = nullptr;
	}
	delete tmp;
}

template <typename T>
void List<T>::erase(int pos) {
	if (empty()) {
		throw std::runtime_error("List is empty.");
	}
	if (pos < 0 || pos >= size()) {
		throw std::out_of_range("Index out of range.");
	}
	if (pos == 0) {
		pop_front();
		return;
	}
	if (pos == size() - 1) {
		pop_back();
		return;
	}
	Node* current = head;
	int k = 0;
	while (current && k != pos) {
		current = current->next;
		k++;
	}
	if (current) {
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
	}
}

template <typename T>
void List<T>::insert(int pos, const T& val) {
	if (empty()) {
		throw std::runtime_error("List is empty.");
	}
	if (pos < 0 || pos > size()) {
		throw std::out_of_range("Index out of range.");
	}
	if (pos == 0) {
		push_front(val);
		return;
	}
	if (pos == size()) {
		push_back(val);
		return;
	}
	Node* current = head;
	int k = 0;
	while (current && k != pos) {
		current = current->next;
		k++;
	}
	if (current) {
		Node* newNode = new Node(val);
		newNode->prev = current->prev;
		newNode->next = current;
		current->prev->next = newNode;
		current->prev = newNode;
	}
}

template <typename T>
T& List<T>::getHeadValue() const {
	return head->value;
}