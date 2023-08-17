#include "bloomfilter.h"

#include <algorithm>
#include <cmath>

BloomFilter::BloomFilter(int nC, const std::vector<std::hash<std::string>>& f)
	: numOfCells{nC}
	, cells(nC)
	, hashFunctions{f}
{
}

void BloomFilter::add(const std::string& h) {
	for (auto const& item: hashFunctions) {
        	cells[item(h) % numOfCells] = true;
    	}
}

std::pair<bool, double> BloomFilter::search(const std::string& h, int numElements) {
    	auto f = std::find_if(hashFunctions.begin(), hashFunctions.end(),
        	[this, &h](const std::hash<std::string>& hash) {
            		return !cells[hash(h) % numOfCells];
        	});

    	double falsePositiveProb = falsePositiveProbability(numElements);

    	return std::make_pair(f == hashFunctions.end(), falsePositiveProb);
}

double BloomFilter::falsePositiveProbability(int numElements) {
    	double k = static_cast<double>(hashFunctions.size());
    	double m = static_cast<double>(numOfCells);
    	double n = static_cast<double>(numElements);

    	return std::pow(1 - std::exp(-k * n / m), k);
}
