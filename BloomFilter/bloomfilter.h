#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <string>
#include <vector>
#include <functional>

class BloomFilter 
{
public:
	BloomFilter(int, const std::vector<std::hash<std::string>>&);
	void add(const std::string&);
	std::pair<bool, double> search(const std::string&, int);
private:
	int numOfCells;
	std::vector<bool> cells;
	std::vector<std::hash<std::string>> hashFunctions;
	double falsePositiveProbability(int);
};

#endif //BLOOMFILTER_H