#include "Window.h"
using namespace std;

Window::Window(int width, int height,string name) :
	width(width),
	height(height),
	name(name)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (m_window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
	}
	else {
		cout << "Window Created: Size(" + to_string(width) + "x" + to_string(height) + ")" << endl;
		glfwMakeContextCurrent(m_window);

		//Vsync ON:1 OFF:0
		glfwSwapInterval(1);
	}

	//initialize glad before calling any opengl function
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
	}

}


Window::~Window()
{
	glfwDestroyWindow(m_window);
}
