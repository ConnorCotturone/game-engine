#pragma once

#include "Core.h";
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "LayerStack.h"

// remove
#include "Window.h"

namespace Brink {
	class BRINK_API Application {
		private:
			bool OnWindowClose(WindowCloseEvent& e);

			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
			LayerStack m_LayerStack;
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);
	};

	// Defined in client
	Application* CreateApplication();
}