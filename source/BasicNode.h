#pragma once

#include <iostream>
#include <vector>
#include "BasicConnection.h"

class BasicNode
{
public:
	BasicNode();

	virtual void update();
	virtual void output_set(BasicConnection connection);

	/*
	float posX, posY;
	float width, height;
	bool selected{ false };
	bool clicked{ false };
	*/
	std::string name;
	std::vector<BasicConnection*> input;
	std::vector<BasicConnection*> output;

	virtual ~BasicNode();
};

