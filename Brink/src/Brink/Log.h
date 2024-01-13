#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Brink {
	class BRINK_API Log {
		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
		public :
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};

}

// core log macros
#define BK_CORE_ERROR(...) ::Brink::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BK_CORE_WARN(...)  ::Brink::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BK_CORE_INFO(...)  ::Brink::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BK_CORE_TRACE(...) ::Brink::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BK_CORE_FATAL(...) ::Brink::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client log macros
#define BK_ERROR(...) ::Brink::Log::GetClientLogger()->error(__VA_ARGS__)
#define BK_WARN(...)  ::Brink::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BK_INFO(...)  ::Brink::Log::GetClientLogger()->info(__VA_ARGS__)
#define BK_TRACE(...) ::Brink::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BK_FATAL(...) ::Brink::Log::GetClientLogger()->fatal(__VA_ARGS__)

