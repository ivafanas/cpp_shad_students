#include "util.h"

#include <cstdio>
#include <vector>

int mul(const std::vector<int>& v)
{
    auto v_copy = v;
    int rv = 1;
    for (int x : v_copy)
        rv *= x;
    return rv;
}

int main(int argc, char** argv)
{
    std::vector<int> v = {1, 2, 3};
    std::printf("%d", mul(v));
    std::printf("%d", sum(v));
    return 0;
}

