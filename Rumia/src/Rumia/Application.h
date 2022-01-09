#pragma once

#include "Core.h"

#include <memory>

namespace Rumia
{
	class RUMIA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	std::unique_ptr<Rumia::Application> CreateApplication();
}

