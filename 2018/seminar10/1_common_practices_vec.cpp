#include <vector>

static const int n = 50000;

static std::vector<int> fill_vec()
{
	std::vector<int> rv;
	for (int i = 0; i < n; ++i)
		rv.push_back(i);
	return rv;
}

static std::vector<int> fill_vec_with_reserve()
{
	std::vector<int> rv;
	rv.reserve(n);
	for (int i = 0; i < n; ++i)
		rv.push_back(i);
	return rv;
}

static void BMFillVec(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_vec();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillVec);

static void BMFillVecWithReserve(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_vec_with_reserve();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillVecWithReserve);
