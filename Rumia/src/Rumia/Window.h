#pragma once

#include "rmpch.h"

#include "Rumia/Core.h"
#include "Rumia/Event/Event.h"

namespace Rumia {
	struct WindowProps
	{
		std::string title;
		unsigned int width, height;

		WindowProps(std::string title = "Rumia", unsigned int width = 1280, unsigned int height = 720)
			: title(std::move(title)), width(width), height(height)
		{
		}
	};

	class RUMIA_API Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window() {}
		virtual void OnUpdate() = 0;
		[[nodiscard]] virtual unsigned int GetWidth() const = 0;
		[[nodiscard]] virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		[[nodiscard]] virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
