#include "math_utils.h"
#include "string_utils.h"

#include <cstdio>
#include <cstring>

void print_help() noexcept
{
    std::puts("USAGE:");
    std::puts("    exmaple.bin mmul 3 4");
    std::puts("        12");
    std::puts("    exmaple.bin smul 3 4");
    std::puts("        3333");
    std::puts("");
    std::puts("Errors processing is not implemented in order to simplify example");
}

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        print_help();
        return 1;
    }

    const char* const op = argv[1];
    const char* const a1 = argv[2];
    const char* const a2 = argv[3];
    if (!std::strcmp(op, "mmul"))
        math_utils::mul(a1, a2);
    else if (!std::strcmp(op, "smul"))
        string_utils::mul(a1, a2);
    return 0;
}
