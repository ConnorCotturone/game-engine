#include "bkpch.h"
#include "WindowsInput.h"
#include "Brink/Application.h"

#include <GLFW/glfw3.h>

namespace Brink {

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode) {
		auto window = static_cast<GLFWwindow*> (Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button) {
		auto window = static_cast<GLFWwindow*> (Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float>  WindowsInput::GetMousePosImpl() {
		auto window = static_cast<GLFWwindow*> (Application::Get().GetWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return std::pair<float, float>(x, y);
	}

	float WindowsInput::GetMouseXImpl() {
		auto [x, y] = GetMousePosImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl() {
		auto [x, y] = GetMousePosImpl();
		return y;
	}

}