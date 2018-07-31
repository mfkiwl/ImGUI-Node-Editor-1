#pragma once
#include "imguiRender/imguiWrapper.h"

class imguiDemo : public imguiObject
{
public:
	imguiDemo(ImVec4& clearcolor) :
		m_clearcolor(clearcolor) {}
	~imguiDemo() {};

	virtual void imguiData() override;

private:
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4& m_clearcolor;
};

