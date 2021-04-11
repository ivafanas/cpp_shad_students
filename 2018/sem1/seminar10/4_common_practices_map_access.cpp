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
	rv.reserve(n);
	for (int i = 0; i < n; ++i)
		rv[i] = i;
	return rv;
}


static void BMAccessMap(benchmark::State& state) {
  const auto x = fill_map();
	for (auto _ : state) {
		for (int i = n - 1; i >= 0; --i)
			benchmark::DoNotOptimize(x.find(i));
	}
}
BENCHMARK(BMAccessMap);

static void BMAccessUnorderedMap(benchmark::State& state) {
  const auto x = fill_unordered_map();
	for (auto _ : state) {
		for (int i = n - 1; i >= 0; --i)
			benchmark::DoNotOptimize(x.find(i));
	}
}
BENCHMARK(BMAccessUnorderedMap);