#include "Application.h"

#include <stdio.h>

#include "Rumia/Event/ApplicationEvent.h"
#include "Log.h"

namespace Rumia
{
	Application::Application()
	{
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

		while (true)
		{
		}
	}

}
