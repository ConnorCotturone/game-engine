#pragma once

#ifdef BK_PLATFORM_WINDOWS

extern Brink::Application* Brink::CreateApplication();

int main(int argc, char** argv) {

	//temp
	Brink::Log::Init();
	BK_CORE_WARN("Initialized Log");
	int temp = 100;
	BK_INFO("Initialized Client {0}", temp);
	//temp

	auto application = Brink::CreateApplication();
	application->Run();
	delete application;
}

#endif
