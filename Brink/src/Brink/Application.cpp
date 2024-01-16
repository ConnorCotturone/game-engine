#include "bkpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Brink/Log.h"

// temp for test
#include <GLFW/glfw3.h>

namespace Brink {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			// temp for test
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}