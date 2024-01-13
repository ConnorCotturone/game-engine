#pragma once

#include "Core.h";

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