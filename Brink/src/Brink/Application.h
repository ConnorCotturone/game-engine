#pragma once

#include "Core.h";
#include "Events/Event.h"

namespace Brink {
	class BRINK_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Defined in client
	Application* CreateApplication();
}