#include <deque>
#include <list>
#include <vector>

static const int n = 10000;

static std::list<int> fill_list()
{
	std::list<int> rv;
	for (int i = 0; i < n; ++i)
		rv.push_back(i);
	return rv;
}

static std::vector<int> fill_vec()
{
	std::vector<int> rv;
	for (int i = 0; i < n; ++i)
		rv.push_back(i);
	return rv;
}

static std::deque<int> fill_deq()
{
	std::deque<int> rv;
	for (int i = 0; i < n; ++i)
		rv.push_back(i);
	return rv;
}

static void BMFillList(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_list();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillList);

static void BMFillVec(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_vec();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillVec);

static void BMFillDeque(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_deq();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillDeque);
