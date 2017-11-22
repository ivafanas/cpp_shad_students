#include <vector>

static std::vector<int> vec{
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

static void sum1(const int* a, int n, int* res)
{
	res = 0;
	for (int i = 0; i < n; ++i)
		res += a[i];
}

static void sum2(const int* a, int n, int* res)
{
	int rv = 0;
	for (int i = 0; i < n; ++i)
		rv += a[i];
	*res = rv;
}

static void BMSum1(benchmark::State& state) {
	for (auto _ : state) {
		int x = 0;
		sum1(&data[0], data.size(), &x);
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMSum1);

static void BMSum2(benchmark::State& state) {
	for (auto _ : state) {
		int x
		sum2(&data[0], data.size(), &x);
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMSum2);
