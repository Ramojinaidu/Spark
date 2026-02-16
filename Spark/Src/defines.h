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
	
	#define SPARK_ENABLE_ASSERTS

#else

	#define SP_DEBUGBREAK()

#endif

#include "Utils/Logger.h"
#include "Utils/Assert.h"
#include "../pch.h"

#endif