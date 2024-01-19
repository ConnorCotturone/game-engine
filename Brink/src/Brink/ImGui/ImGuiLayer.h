#pragma once

#include "Brink/Layer.h"

namespace Brink {
	class BRINK_API ImGuiLayer : public Layer {
		private:
			float m_Time = 0.00f;
		public:
			ImGuiLayer();
			~ImGuiLayer();

			void OnUpdate();
			void OnEvent(Event& e);
			void OnAttach();
			void OnDetach();
	};
}