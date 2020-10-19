#pragma once

template<unsigned N>
struct Factorial
{
    static const int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0>
{
    static const int value = 1;
};

