#include "blockarray.h"
#include <iostream>

int main() {
	BlockArray<int> blockArray;
	std::cout << "Is block array empty? " << std::boolalpha << blockArray.empty() << std::endl;
	std::cout << "Pushing elements in block array..." << std::endl;
	blockArray.push_back(5);
	blockArray.push_back(8);
	blockArray.push_back(1);
	blockArray.push_back(3);
	blockArray.push_back(12);
	blockArray.push_back(15);
	blockArray.push_back(36);
	blockArray.push_back(33);
	blockArray.push_back(11);
	blockArray.push_back(13);
	blockArray.push_back(10);
	blockArray.print();
	std::cout << "Block array's forth element is " << blockArray[3] << std::endl;
	std::cout << "Remove last element from array.." << std::endl;
	blockArray.pop_back();
	blockArray.print();
	std::cout << "Size of array: " << blockArray.size() << std::endl;
	std::cout << "Remove sixth element from array..." << std::endl;
	blockArray.erase(5);
	blockArray.print();
	std::cout << "Inserting value 24 at ninth index..." << std::endl;
	blockArray.insert(8, 24);
	blockArray.print();
	std::cout << "Clear all content of array..." << std::endl;
	blockArray.clear();
	std::cout << "Size of array: " << blockArray.size() << std::endl;

	return 0;
}