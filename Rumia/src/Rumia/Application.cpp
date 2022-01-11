#include "rmpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>
#include "Rumia/Event/ApplicationEvent.h"
#include "Log.h"

namespace Rumia
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		RM_CORE_TRACE(e);

		if (e.IsInCategory(EventCategoryApplication))
		{
			RM_CORE_TRACE("Event [{}] is in EventCategoryApplication. ", e);
		}

		while (m_Running)
		{
			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}
