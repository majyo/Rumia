#pragma once

#include "rmpch.h"

#include "Core.h"
#include "Window.h"
#include "Rumia/Event/ApplicationEvent.h"

namespace Rumia
{
	class RUMIA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:
		bool OnWindowClosed(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	std::unique_ptr<Rumia::Application> CreateApplication();
}

