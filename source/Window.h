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

	void Update();

	GLFWwindow* GetWindow() { return m_window; };

	int width, height;
	string name;
private:
	static void Window::size_callback(GLFWwindow * window, int width, int height);
	GLFWwindow* m_window;
};

