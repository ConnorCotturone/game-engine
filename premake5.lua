workspace "Brink"
	architecture "x64"
	
	-- Debug is for development, 
	-- Release is debug with a lot of function stripped but with optimization and logging,
	-- Dist is the distribution or final release form
	configurations { "Debug", "Release", "Dist" }

output_directory = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirectories = {}
IncludeDirectories["GLFW"] = "Brink/vendor/GLFW/include"

include "Brink/vendor/GLFW"

project "Brink"
	location "Brink"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. output_directory .. "/%{prj.name}")
	objdir ("bin-int/" .. output_directory .. "/%{prj.name}")

	pchheader "bkpch.h"
	pchsource "Brink/src/bkpch.cpp"

	files { 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp" 
	}

	includedirs { 
		"%{prj.name}/src", 
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDirectories.GLFW}"
	}

	links { 
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib" 
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines { "BK_PLATFORM_WINDOWS;", "BK_BUILD_DLL;" }

		postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. output_directory .. "/Sandbox") }

	filter "configurations:Debug"
		defines "BK_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "BK_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "BK_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. output_directory .. "/%{prj.name}")
	objdir ("bin-int/" .. output_directory .. "/%{prj.name}")

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

	includedirs { "Brink/vendor/spdlog/include", "Brink/src" }

	links { "Brink" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines { "BK_PLATFORM_WINDOWS;" }

	filter "configurations:Debug"
		defines "BK_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "BK_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "BK_DIST"
		buildoptions "/MD"
		optimize "On"