#include "bkpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Brink/Log.h"

namespace Brink {
	Application::Application() {

	}
	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent tmp(500, 500);
		BK_TRACE(tmp);

		while (true);
	}
}