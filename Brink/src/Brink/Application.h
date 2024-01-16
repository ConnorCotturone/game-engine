#pragma once

#include "Core.h";
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"

#include "Window.h"

namespace Brink {
	class BRINK_API Application {
		private:
			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
			bool OnWindowClose(WindowCloseEvent& e);
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& e);
	};

	// Defined in client
	Application* CreateApplication();
}