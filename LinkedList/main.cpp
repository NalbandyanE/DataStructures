#include "list.h"
#include <iostream>

int main() {
	List<int> list;
	std::cout << "Is list empty? " << std::boolalpha << list.empty() << std::endl;
	std::cout << "Adding 5 in list" << std::endl;
	list.push_back(5);
	list.traverse();
	std::cout << "Adding 6 in list" << std::endl;
	list.push_back(6);
	list.traverse();
	std::cout << "Adding 7 in list" << std::endl;
	list.push_back(7);
	list.traverse();
	std::cout << "Adding 3 in front of list" << std::endl;
	list.push_front(3);
	list.traverse();
	std::cout << "Is list empty? " << std::boolalpha << list.empty() << std::endl;
	std::cout << "Erase element in position 2" << std::endl;
	list.erase(2);
	list.traverse();
	std::cout << "Inserting 8 in position 2" << std::endl;
	list.insert(2, 8);
	list.traverse();
	std::cout << "Sorting elements in list" << std::endl;
	list.sort();
	list.traverse();
	std::cout << "Reverse elements in list" << std::endl;
	list.reverse();
	list.traverse();
	std::cout << "Size of list: " << list.size() << std::endl;
	std::cout << "First element of list: " << list.front() << std::endl;
	std::cout << "Last element of list: " << list.back() << std::endl;
	std::cout << "Remove first element of list" << std::endl;
	list.pop_front();
	list.traverse();
	std::cout << "Remove last element of list" << std::endl;
	list.pop_back();
	list.traverse();
	std::cout << "Is there value 10 in list? " << std::boolalpha << list.find(10) << std::endl;
	std::cout << "Clear all elements from list" << std::endl;
	list.clear();
	std::cout << "Is list empty? " << std::boolalpha << list.empty() << std::endl;

	return 0;
}