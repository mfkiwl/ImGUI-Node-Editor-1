#pragma once

#include <vector>
#include<iostream>

class BasicNode;

class BasicConnection
{
public:
	BasicConnection();

	std::vector<BasicNode*> node_from;
	std::vector<BasicNode*> node_to;

	~BasicConnection();
};

