#pragma once

#include "Core.h"

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Rumia
{
	class RUMIA_API Log
	{
	public:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger> GetClientLogger()
		{
			return s_ClientLogger;
		}
	};
}

// Core log macros
#define RM_CORE_TRACE(...)    ::Rumia::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RM_CORE_INFO(...)     ::Rumia::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RM_CORE_WARN(...)     ::Rumia::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RM_CORE_ERROR(...)    ::Rumia::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RM_CORE_FATEL(...)    ::Rumia::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log micros
#define RM_CLIENT_TRACE(...)    ::Rumia::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RM_CLIENT_INFO(...)     ::Rumia::Log::GetClientLogger()->info(__VA_ARGS__)
#define RM_CLIENT_WARN(...)     ::Rumia::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RM_CLIENT_ERROR(...)    ::Rumia::Log::GetClientLogger()->error(__VA_ARGS__)
#define RM_CLIENT_FATEL(...)    ::Rumia::Log::GetClientLogger()->critical(__VA_ARGS__)
