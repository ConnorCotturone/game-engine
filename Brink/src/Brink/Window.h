#pragma once

#include "bkpch.h"

#include "Brink/Core.h"
#include "Brink/Events/Event.h"

namespace Brink {
	struct WindowProperties {
		unsigned int Width;
		unsigned int Height;
		std::string Title;

		WindowProperties(unsigned int width = 1080,
					unsigned int height = 720,
					const std::string& title = "BrinK Engine")
					: Width(width), Height(height), Title(title) {}
	};

	// implemented per platform
	class BRINK_API Window {
		public:
			using EventCallbackFn = std::function<void(Event&)>;

			virtual ~Window() {}

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			virtual void SetEventCallback(const EventCallbackFn&) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			virtual void* GetNativeWindow() const = 0;

			static Window* Create(const WindowProperties& props = WindowProperties());
	};
}