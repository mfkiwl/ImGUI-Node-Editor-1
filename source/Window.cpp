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
	glfwWindowHint(GLFW_DOUBLEBUFFER, 1);

	m_window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	if (m_window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
	}
	else {
		cout << "Window Created: Size(" + to_string(width) + "x" + to_string(height) + ")" << endl;
		glfwMakeContextCurrent(m_window);

		//set resize callback
		glfwSetFramebufferSizeCallback(m_window, Window::size_callback);

		//Vsync ON:1 OFF:0
		glfwSwapInterval(1);

		//initialize glad before calling any opengl function
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			cout << "Failed to initialize GLAD" << endl;
		}

		glViewport(0, 0, width, height); // set the viewport

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		//glEnable(GL_MULTISAMPLE);
		glCullFace(GL_BACK);
	}


}


Window::~Window()
{
	glfwDestroyWindow(m_window);
}

void Window::Update()
{
	glfwGetWindowSize(m_window, &width, &height);
	glViewport(0, 0, width, height);
}


void Window::size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}