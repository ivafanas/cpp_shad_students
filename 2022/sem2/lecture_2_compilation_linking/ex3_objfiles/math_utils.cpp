#include "math_utils.h"

#include "convert.h"

#include <cstdio>

namespace math_utils
{
    void mul(const char* const a1, const char* const a2) noexcept
    {
        const int x1 = convert_to_int(a1);
        const int x2 = convert_to_int(a2);
        std::printf("%d\n", x1 * x2);
    }
}  // namespace math_utils

