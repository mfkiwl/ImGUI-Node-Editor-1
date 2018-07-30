#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <string>

class Window
{
//per comodita' e per evitare di usare using namespace std;
typedef std::string string;

public:
	Window(int width, int height, string name);
	~Window();

	int width, height;
	string name;
private:
	GLFWwindow* m_window;
};

