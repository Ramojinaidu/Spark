#pragma once

#ifdef SPARK_DEBUG
#endif

#define BIT(x) (1 << x)
#define SP_BIND_FUNC(func) [this](auto&&... args) -> decltype(auto) { return this->func(std::forward<decltype(args)>(args)...); }
