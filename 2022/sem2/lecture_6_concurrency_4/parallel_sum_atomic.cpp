#include <atomic>
#include <cassert>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std::chrono;

int parallel_sum(const std::vector<int>& v, const unsigned threads_count)
{
    const unsigned len = v.size() / threads_count;
    assert(len * threads_count == v.size());

    std::atomic<int> rv{0};

    std::vector<std::thread> threads;
    for (unsigned i = 0; i < threads_count; ++i)
        threads.emplace_back([&v, &rv, i, len](){
            const unsigned start_ix = len * i;
            const unsigned final_ix = len * i + len;
            for (unsigned ix = start_ix; ix < final_ix; ++ix)
                 rv += v[ix];
        });

    for (auto& t: threads)
        t.join();

    return rv;
}

int main()
{
    const unsigned size = 60'000'000;
    const unsigned threads_count = 6;

    std::vector<int> v(size, 1);

    const auto start_ts = high_resolution_clock::now();

    const int sum = parallel_sum(v, threads_count);

    const auto final_ts = high_resolution_clock::now();

    std::cout
        << "parallel sum atomic:" << std::endl
        << "  size          = " << size << std::endl
        << "  threads_count = " << threads_count << std::endl
        << "  result        = " << sum << std::endl
        << "  time, sec     = " << duration_cast<microseconds>(final_ts - start_ts).count() / 1e6 << std::endl;
}

