// node-editor.cpp : Defines the entry point for the console application.
//
//standard headers
#include <iostream>

//opengl headers
#include <glad\glad.h>
#include <GLFW\glfw3.h>

//additional headers
#include "BasicNode.h"
#include "Window.h"
#include "imguiRender/imguiWrapper.h"
#include "imguiDemo.h"

using namespace std;

int main()
{
	std::cout << "ses " << std::endl;
	BasicNode a;
	a.update();

	//init window
	Window window(800, 600, "Node Editor");

	//imgui init
	imguiWrapper imgui(window.GetWindow());
	imgui.Init();

	//imgui demo
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	auto demo = new imguiDemo(clear_color);
	imgui.addObject((imguiObject*)demo);


	//render loop
	while (!glfwWindowShouldClose(window.GetWindow()))
	{
		glfwPollEvents();
		window.Update();

		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);

		imgui.Render();

		// Rendering

		glfwSwapBuffers(window.GetWindow());
	}

	imgui.Shutdown();
	glfwTerminate();
	return 0;
}

