// node-editor.cpp : Defines the entry point for the console application.
//

#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include<iostream>
#include "BasicNode.h"

int main()
{
	std::cout << "ses " << std::endl;
	BasicNode a;
	a.update();

	system("pause");
    return 0;
}

