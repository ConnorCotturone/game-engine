#include <Brink.h>

// Example layer

class ExampleLayer : public Brink::Layer {
	public:

		ExampleLayer() : Layer("Example") {}

		void OnUpdate() override { 
			//BK_INFO("ExampleLayer::Update"); 
			
		}

		void OnEvent(Brink::Event& event) override { 
			// temp test
			//BK_TRACE("{0}", event); 
			if (event.GetEventType() == Brink::EventType::KeyPressed) {
				Brink::KeyPressedEvent& e = (Brink::KeyPressedEvent&) event;
				BK_TRACE("{0} pressed", (char) e.GetKeyCode());
			}
		}
};

class Sandbox : public Brink::Application {
	public :
		Sandbox() {
			PushLayer(new ExampleLayer());
			PushOverlay(new Brink::ImGuiLayer());
		}

		~Sandbox() {

		}
};

Brink::Application* Brink::CreateApplication() {
	return new Sandbox();
}