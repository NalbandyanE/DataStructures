#include "centralServer.h"

#include <iostream>

int main() {
	Node n1, n2, n3, n4, n5;
	std::vector<Node> nodes;
	nodes.push_back(n1);
	nodes.push_back(n2);
	nodes.push_back(n3);
	nodes.push_back(n4);
	nodes.push_back(n5);
	std::vector<int> nums{14, 45, 68, 79, 2, 4, 5, 3};
	CentralServer cS(nodes, nums);
	std::cout << cS.distributedSum() << std::endl;

	return 0;
}