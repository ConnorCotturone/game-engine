workspace "Brink"
	architecture "x64"
	
	-- Debug is for development, 
	-- Release is debug with a lot of function stripped but with optimization and logging,
	-- Dist is the distribution or final release form
	configurations { "Debug", "Release", "Dist" }
	startproject "Sandbox"

output_directory = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirectories = {}
IncludeDirectories["GLFW"] = "Brink/vendor/GLFW/include"
IncludeDirectories["Glad"] = "Brink/vendor/Glad/include"
IncludeDirectories["ImGui"] = "Brink/vendor/imgui"

group "Dependencies"
	include "Brink/vendor/GLFW"
	include "Brink/vendor/Glad"
	include "Brink/vendor/imgui"
group ""

project "Brink"
	location "Brink"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDirectories.GLFW}",
		"%{IncludeDirectories.Glad}",
		"%{IncludeDirectories.ImGui}"
	}

	links { 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib" 
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines { "BK_PLATFORM_WINDOWS", "BK_BUILD_DLL", "GLFW_INCLUDE_NONE" }

		postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. output_directory .. "/Sandbox/\"") }

	filter "configurations:Debug"
		defines "BK_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "BK_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "BK_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. output_directory .. "/%{prj.name}")
	objdir ("bin-int/" .. output_directory .. "/%{prj.name}")

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

	includedirs { "Brink/vendor/spdlog/include", "Brink/src" }

	links { "Brink" }

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines { "BK_PLATFORM_WINDOWS" }

	filter "configurations:Debug"
		defines "BK_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "BK_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "BK_DIST"
		runtime "Release"
		optimize "On"