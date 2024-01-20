#pragma once

#include "Brink/Layer.h"

#include "Brink/Events/ApplicationEvent.h"
#include "Brink/Events/KeyEvent.h"
#include "Brink/Events/MouseEvent.h"

namespace Brink {
	class BRINK_API ImGuiLayer : public Layer {
		private:
			float m_Time = 0.00f;

			bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
			bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
			bool OnMouseMovedEvent(MouseMovedEvent& e);
			bool OnMouseScrolledEvent(MouseScrolledEvent& e);
			bool OnKeyPressedEvent(KeyPressedEvent& e);
			bool OnKeyReleasedEvent(KeyReleasedEvent& e);
			bool OnKeyTypedEvent(KeyTypedEvent& e);
			bool OnWindowResizeEvent(WindowResizeEvent& e);
		public:
			ImGuiLayer();
			~ImGuiLayer();

			void OnUpdate();
			void OnEvent(Event& e);
			void OnAttach();
			void OnDetach();
	};
}