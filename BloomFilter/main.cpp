#include "bloomfilter.h"

#include <iostream>

int main() {
    int numOfCells = 1000; 
    int numOfHashFunctions = 3;

    std::vector<std::hash<std::string>> hashFunctions(numOfHashFunctions);

    BloomFilter filter(numOfCells, hashFunctions);

    filter.add("apple");
    filter.add("banana");
    filter.add("cherry");

    auto result = filter.search("apple", 3);
    std::cout << "Contains apple? " << result.first << std::endl;
    std::cout << "Estimated false positive probability: " << result.second << std::endl;
    auto result1 = filter.search("banana", 5);
    std::cout << "Contains banana? " << result1.first << std::endl;
    std::cout << "Estimated false positive probability: " << result1.second << std::endl;
    auto result2 = filter.search("orange", 2);
    std::cout << "Contains orange? " << result2.first << std::endl;
    std::cout << "Estimated false positive probability: " << result2.second << std::endl;
    
    return 0;
}
