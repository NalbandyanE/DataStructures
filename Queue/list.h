#ifndef List_H
#define List_H

template <typename T>
class List {
public:
	List();
	List& operator=(const List&);
	bool find(const T&);
	void traverse();
	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
	void erase(int);
	void insert(int,const T&);
	bool empty();
	int size();
	void clear();
	T front();
	T back();
	T& getHeadValue() const;
private:
	struct Node {
		T value;
		Node* next;
		Node* prev;
		Node(T val) : value{val}, next{nullptr}, prev{nullptr} {}
	};
	Node* head;
	Node* tail;
};

#include "list.tpp"

#endif // LIST_H