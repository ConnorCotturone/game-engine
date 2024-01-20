#pragma once

#include "Brink/Window.h"

#include <GLFW/glfw3.h>

namespace Brink {
	class WindowsWindow : public Window {
		private:
			virtual void Init(const WindowProperties& props);
			virtual void Shutdown();
		private:
			GLFWwindow* m_Window;

			struct WindowData {
				unsigned int Width, Height;
				std::string Title;
				bool VSync;

				EventCallbackFn EventCallback;
			};

			WindowData m_Data;

		public:
			WindowsWindow(const WindowProperties& props);
			virtual ~WindowsWindow();

			void OnUpdate() override;

			inline unsigned int GetWidth() const override { return m_Data.Width; }
			inline unsigned int GetHeight() const override { return m_Data.Height; }

			// window attributes
			inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
			void SetVSync(bool enabled) override;
			bool IsVSync() const override;

			virtual void* GetNativeWindow() const { return m_Window; }
	};
}