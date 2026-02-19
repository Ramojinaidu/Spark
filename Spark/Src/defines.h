#ifndef DEFINES_H
#define DEFINES_H

#ifdef _WIN32

	#error "Platform not supported"

#elif defined(__APPLE__) || defined(__MACH__)

	#error "Platform not supported"

#elif defined(__linux__)

	#define SPARK_LINUX_PLATFORM

#else
	#error "Unknown Platform"
#endif



#if SPARK_DEBUG

	#ifdef SPARK_LINUX_PLATFORM
		#include <signal.h>
		#define SPARK_DEBUGBREAK() raise(SIGTRAP);
	#else
		#error "Platform not supported"
	#endif

	#define SPARK_ENABLE_ASSERTS 1

#else

	#define SPARK_DEBUGBREAK()

#endif



#define SP_BIND_FUNC(func) [this](auto&&... args) -> decltype(auto) { return this->func(std::forward<decltype(args)>(args)...); }

#endif
