#include "bkpch.h"

#include "WindowsWindow.h"

namespace Brink {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProperties& props) { return new WindowsWindow(props); }

	WindowsWindow::WindowsWindow(const WindowProperties& props) { Init(props); }

	WindowsWindow::~WindowsWindow() { Shutdown(); }

	void WindowsWindow::Init(const WindowProperties& props) {
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;

		BK_CORE_INFO("Creating window {0} ({1} x {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) {
			int pass = glfwInit();
			BK_CORE_ASSERT(pass, "Could not initalize GLFW");
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown() { glfwDestroyWindow(m_Window); }

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const { return m_Data.VSync; }

}