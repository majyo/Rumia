#pragma once

#include "Rumia/Window.h"

#include <GLFW/glfw3.h>

namespace Rumia
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		[[nodiscard]] inline unsigned int GetWidth() const override
		{
			return m_Data.width;
		}

		[[nodiscard]] inline unsigned int GetHeight() const override
		{
			return m_Data.height;
		}

		inline void SetEventCallback(const EventCallbackFunc& callback) override
		{
			m_Data.eventCallback = callback;
		}

		void SetVSync(bool enabled) override;
		[[nodiscard]] bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFunc eventCallback;
		};

		WindowData m_Data;
	};
}
