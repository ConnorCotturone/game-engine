project "Glad"
    kind "StaticLib"
    language "C"

	targetdir ("bin/" .. output_directory .. "/%{prj.name}")
    objdir ("bin-int/" .. output_directory .. "/%{prj.name}")

	files {
        "include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
    }

    includedirs { "include" }

	filter "system:windows"
        systemversion "latest"
        staticruntime "On"

    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"
