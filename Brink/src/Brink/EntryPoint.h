#pragma once

#ifdef BK_PLATFORM_WINDOWS

extern Brink::Application* Brink::CreateApplication();

int main(int argc, char** argv) {

	//temp
	Brink::Log::Init();

	BK_INFO("Initialized Client...");
	//temp

	auto application = Brink::CreateApplication();
	application->Run();
	delete application;
}

#endif
