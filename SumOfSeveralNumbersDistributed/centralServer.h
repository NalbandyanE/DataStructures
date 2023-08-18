#ifndef CENTRALSERVER_H
#define CENTRALSERVER_H

#include "node.h"

#include <vector>
#include <iostream>

class CentralServer {
public:
	CentralServer(const std::vector<Node>&, const std::vector<int>&);
	int distributedSum();
private:
	std::vector<Node> nodes;
	std::vector<int> nums;
};

CentralServer::CentralServer(const std::vector<Node>& n, const std::vector<int>& ns)
	: nodes{n}
	, nums{ns}
{
}

int CentralServer::distributedSum() {
	int sum = 0;
    	int numPairsPerNode = nums.size() / nodes.size();

    	for (int i = 0; i < nodes.size(); ++i) {
        	std::cout << "Node " << i << ": ";
        	int startIndex = i * numPairsPerNode;
        	int endIndex = startIndex + numPairsPerNode;
        	int sum2 = 0;
        
        	for (int j = startIndex; j < endIndex; ++j) {
            		std::cout << "(" << nums[j * 2] << ", " << nums[j * 2 + 1] << ")";
            		sum2 += nodes[i].sumOfNums(nums[j * 2], nums[j * 2 + 1]);
            		std::cout << " = " << sum2;
        	}
        	sum += sum2;
        	std::cout << std::endl;
    	}
    	std::cout << "Total sum is: ";
    	return sum;
}

#endif //CENTRALSERVER_H
