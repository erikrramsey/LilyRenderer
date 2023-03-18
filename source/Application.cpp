#include "Application.h"

Application::Application() {
	init();
}

Application::~Application() {
	m_renderer->shutdown();
}

void Application::init() {
	initGLFW();
	m_renderer = &RendererVulkan::getSingleton();
	m_renderer->init(m_window);
}

void Application::initGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	m_window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetFramebufferSizeCallback(m_window, RendererVulkan::framebufferResizeCallback);
}

void Application::run() {
	auto last_frame_time = std::chrono::high_resolution_clock::now();
	while (!glfwWindowShouldClose(m_window)) {
		auto current = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - last_frame_time).count();
		last_frame_time = std::chrono::high_resolution_clock::now();

		glfwPollEvents();
		m_renderer->update(current);

		std::cout << 1'000'000.0 / current << '\r';
	}

}
