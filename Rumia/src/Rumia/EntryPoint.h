#pragma once

#include "Log.h"

#ifdef RM_PLATFORM_WINDOWS

extern std::unique_ptr<Rumia::Application> Rumia::CreateApplication();

int main(int argc, char** argv)
{
	Rumia::Log::Init();
	RM_CORE_WARN("Initialized Log!");
	RM_CLIENT_INFO("Initialized Log!");

	auto app = Rumia::CreateApplication();
	app->Run();
}

#endif // RM_PLATFORM_WINDOWS

