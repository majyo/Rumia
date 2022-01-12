#include "rmpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>
#include "Rumia/Event/ApplicationEvent.h"
#include "Log.h"

namespace Rumia
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
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
			RM_CORE_TRACE("Event [{0}] is in EventCategoryApplication. ", e);
		}

		while (m_Running)
		{
			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));

		RM_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}
