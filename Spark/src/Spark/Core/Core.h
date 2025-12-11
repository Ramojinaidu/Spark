#pragma once

#define BIT(x) (1 << x)
#define SP_BIND_FUNC(func) [this](auto&&... args) -> decltype(auto) { return this->func(std::forward<decltype(args)>(args)...); }
