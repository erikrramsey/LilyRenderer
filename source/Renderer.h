#pragma once

struct GLFWwindow;

class Renderer {
public:
	virtual void init(GLFWwindow* window) = 0;
	virtual void update(long long dt) = 0;
	virtual void shutdown() = 0;
protected:
	Renderer() {}
};
