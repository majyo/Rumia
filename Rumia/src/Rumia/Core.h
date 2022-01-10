#pragma once

#ifdef RM_PLATFORM_WINDOWS

#ifdef RM_BUILD_DLL

#define RUMIA_API __declspec(dllexport)

#else

#define RUMIA_API __declspec(dllimport)

#endif // RM_BUILD_DLL

#else

#error Rumia only supports Windows!

#endif // RM_PLATFORM_WINDOWS

#define BIT(x) (1 << x)

