#include "imguiWrapper.h"

bool imguiWrapper::Init()
{
	if (hasInit = IMGUI_CHECKVERSION()) {
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui_ImplGlfw_InitForOpenGL(m_window, true);
		ImGui_ImplOpenGL3_Init("#version 130");
		m_defaulstyle(nullptr);
		return true;
	}
	return false;
}

void imguiWrapper::Render()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	for (int i = 0; i < m_datavector.size(); i++)
		m_datavector[i]->imguiData();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void imguiWrapper::Shutdown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
