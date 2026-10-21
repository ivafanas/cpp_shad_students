#pragma once

#include <type_traits>

template <typename T, int NRows, int NCols> class Matrix {
  static_assert(std::is_same_v<T, float> || std::is_same_v<T, double> ||
                    (std::is_integral_v<T> && !std::is_unsigned_v<T>),
                "only float, double and signed integer types are supported");
  static_assert(NRows > 0, "only positive rows count values are supported");
  static_assert(NCols > 0, "only positive cols count values are supported");

public:
};
