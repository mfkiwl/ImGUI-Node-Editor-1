#pragma once
#include <GLFW\glfw3.h>
#include <imgui\imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <string>
#include <vector>
#include <functional>

class imguiObject {
public:
	virtual void imguiData()=0;
};


class imguiWrapper
{
	typedef std::string string;
	typedef std::vector<imguiObject*> imguiData;
	typedef std::function<void(ImGuiStyle*)> stylefunc;
public:
	imguiWrapper(GLFWwindow* window, 
			stylefunc defaulstyle = &ImGui::StyleColorsClassic, 
			string glsl_version = "#version 130") :
		m_window(window),
		m_defaulstyle(defaulstyle),
		m_glsl_version(glsl_version) {}

	~imguiWrapper() {};

	bool Init();
	void Render();
	void Shutdown();
	void addObject(imguiObject* imguiObject) 
		{ m_datavector.push_back(imguiObject); }

	bool hasInit;
private:
	GLFWwindow* m_window;
	string m_glsl_version;
	stylefunc m_defaulstyle;
	imguiData m_datavector;
};

