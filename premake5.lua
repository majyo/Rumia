workspace "Rumia"
    architecture "x64"

    configurations
    {
         "Debug",
         "Release",
         "Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Rumia/vendor/GLFW/include"

include "Rumia/vendor/GLFW"

project "Rumia"
    location "Rumia"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "rmpch.h"
    pchsource "Rumia/src/rmpch.cpp"

    files
    {
         "%{prj.name}/src/**.h",
         "%{prj.name}/src/**.cpp",
	}

    includedirs
    {
         "%{prj.name}/src",
         "%{prj.name}/vendor/spdlog/include",
         "%{IncludeDir.GLFW}"
	}

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "RM_PLATFORM_WINDOWS",
			"RM_BUILD_DLL"
		}

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

    filter "configurations:Debug"
        defines "RM_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RM_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "RM_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "COnsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
         "%{prj.name}/src/**.h",
         "%{prj.name}/src/**.cpp",
	}

    includedirs
    {
         "Rumia/vendor/spdlog/include",
         "Rumia/src"
	}

    links
    {
         "Rumia"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "RM_PLATFORM_WINDOWS",
		}

    filter "configurations:Debug"
        defines "RM_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RM_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "RM_DIST"
        optimize "On"

