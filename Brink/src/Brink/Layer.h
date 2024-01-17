#pragma once

#include "Brink/Core.h"
#include "Brink/Events/Event.h"

namespace Brink {
	class BRINK_API Layer {
		protected:
			std::string m_DebugName;
		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer();

			virtual void OnAttach() {}
			virtual void OnDetach() {}
			virtual void OnUpdate() {}
			virtual void OnEvent(Event& event) {}

			inline const std::string& GetName() const { return m_DebugName; }
	};
}