#include "util.h"

int sum(const std::vector<int>& v)
{
    auto v_copy = v;
    int rv = 0;
    for (int x : v_copy)
        rv += x;
    return rv;
}

