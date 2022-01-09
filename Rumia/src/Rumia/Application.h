#pragma once

#include "Core.h"

namespace Rumia
{
	class RUMIA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

