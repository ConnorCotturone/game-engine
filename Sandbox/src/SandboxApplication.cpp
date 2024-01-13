#include <Brink.h>

class Sandbox : public Brink::Application {
	public :
		Sandbox() {

		}

		~Sandbox() {

		}
};

Brink::Application* Brink::CreateApplication() {
	return new Sandbox();
}