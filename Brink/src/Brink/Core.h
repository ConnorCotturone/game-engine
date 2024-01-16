#pragma once

#ifdef BK_PLATFORM_WINDOWS
	#ifdef BK_BUILD_DLL
		#define BRINK_API __declspec(dllexport)
	#else
		#define BRINK_API __declspec(dllimport)
	#endif
#else
	#error Brink only currently supports Windows
#endif

#define BIT(x) (1 << x)