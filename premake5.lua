workspace "Brink"
	architecture "x64"
	
	-- Debug is for development, 
	-- Release is debug with a lot of function stripped but with optimization and logging,
	-- Dist is the distribution or final release form
	configurations { "Debug", "Release", "Dist" }

output_directory = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Brink"
	location "Brink"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. output_directory .. "/%{prj.name}")
	objdir ("bin-int/" .. output_directory .. "/%{prj.name}")

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

	includedirs { "%{prj.name}/vendor/spdlog/include" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines { "BK_PLATFORM_WINDOWS;", "BK_BUILD_DLL;" }

		postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. output_directory .. "/Sandbox") }

	filter "configurations:Debug"
		defines "BK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BK_DIST"
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
		systemversion "10.0.22621.0"

		defines { "BK_PLATFORM_WINDOWS;" }

	filter "configurations:Debug"
		defines "BK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BK_DIST"
		optimize "On"