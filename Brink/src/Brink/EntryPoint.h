#pragma once

#ifdef BK_PLATFORM_WINDOWS

extern Brink::Application* Brink::CreateApplication();

int main(int argc, char** argv) {
	auto application = Brink::CreateApplication();
	application->Run();
	delete application;
}

#endif
