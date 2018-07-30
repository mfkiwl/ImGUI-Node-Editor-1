#include "BasicNode.h"



BasicNode::BasicNode()
{
	std::cout << "basic node constructor called" << std::endl;
}

void BasicNode::update() {
	std::cout << "node updated" << std::endl;
}

void BasicNode::output_set(BasicConnection connection) {
	output.push_back(&connection);
}

BasicNode::~BasicNode()
{
}
