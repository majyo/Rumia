#pragma once

#ifdef RM_PLATFORM_WINDOWS

extern Rumia::Application* Rumia::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Rumia::CreateApplication();
	app->Run();
	delete app;
}

#endif // RM_PLATFORM_WINDOWS

