#ifndef ASSERT_H
#define ASSERT_H

#include "../defines.h"

#ifdef SPARK_ENABLE_ASSERTS

	#define SPARK_ASSERT(check,...) {if(!(check)){\
										SPARK_ERROR(__VA_ARGS__)\
										SPARK_DEBUGBREAK()\
									}}

#else 

	#define SPARK_ASSERT() 

#endif

#endif