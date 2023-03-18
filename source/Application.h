#pragma once
#include <chrono>

#include "GLFW/glfw3.h"

#include "Renderer.h"
#include "RendererVulkan.h"

class Application {
private:
	GLFWwindow* m_window;
	Renderer* m_renderer;
public:
	Application();
	~Application();
	void run();
private:
	void init();
	void initGLFW();

};

