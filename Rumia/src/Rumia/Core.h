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

#ifdef RM_ENABLE_ASSERTS
#define RM_ASSERT(x, ...) {if (!(x)) {RM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#define RM_CORE_ASSERT(x, ...) {if (!(x)) {RM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#define RM_ASSERT(x, ...)
#define RM_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

