#pragma once

#include "Core.h";
#include "Events/Event.h"
#include "Window.h"

namespace Brink {
	class BRINK_API Application {
		private:
			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	// Defined in client
	Application* CreateApplication();
}