#include "stack.h"

#include <iostream>

int main() {
	Stack<int> stack;
	std::cout << "Is stack empty? " << std::boolalpha << stack.empty() << std::endl;
	std::cout << "Pushing elements in stack (10, 29, 14, 37)..." << std::endl;
	stack.push(10);
	stack.push(29);
	stack.push(14);
	stack.push(37);
	std::cout << "Size of stack: " << stack.size() << std::endl;
	std::cout << "Top of stack: " << stack.top() << std::endl;
	std::cout << "Delete element from stack..." << std::endl;
	stack.pop();
	std::cout << "Top of stack: " << stack.top() << std::endl;
	std::cout << "Size of stack: " << stack.size() << std::endl;

	return 0;
}