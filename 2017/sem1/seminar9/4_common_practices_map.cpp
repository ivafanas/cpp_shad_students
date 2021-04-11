#include <map>
#include <unordered_map>

static const int n = 50000;

static std::map<int, int> fill_map()
{
	std::map<int, int> rv;
	for (int i = 0; i < n; ++i)
		rv[i] = i;
	return rv;
}













static std::unordered_map<int, int> fill_unordered_map()
{
	std::unordered_map<int, int> rv;
	for (int i = 0; i < n; ++i)
		rv[i] = i;
	return rv;
}












static std::unordered_map<int, int> fill_unordered_map_reserve()
{
	std::unordered_map<int, int> rv;
	rv.reserve(n);
	for (int i = 0; i < n; ++i)
		rv[i] = i;
	return rv;
}

static void BMFillMap(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_map();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillMap);

static void BMFillUnorderedMap(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_unordered_map();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillUnorderedMap);

static void BMFillUnorderedMapReserve(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_unordered_map_reserve();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillUnorderedMapReserve);
