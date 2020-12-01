#include "string_utils.h"

#include <cstdio>
#include <cstdlib>

int convert_to_int(const char* const s) noexcept
{
    return std::atoi(s);
}

namespace string_utils
{
    void sum(const char* const a1, const char* const a2) noexcept
    {
        std::puts(a1);
        std::puts(a2);
    }

    void mul(const char* const a1, const char* const a2) noexcept
    {
        const int x2 = convert_to_int(a2);
        for (int i = 0; i < x2; ++i)
            std::puts(a1);
    }
}  // namespace string_utils

