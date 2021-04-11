#include <memory>
#include <vector>

static const int n = 50000;

static std::vector<std::shared_ptr<int>> fill_vec1()
{
	std::vector<std::shared_ptr<int>> rv;
	rv.reserve(n);
	for (int i = 0; i < n; ++i)
		rv.push_back(std::shared_ptr<int>(new int(i)));
	return rv;
}








static std::vector<std::shared_ptr<int>> fill_vec2()
{
	std::vector<std::shared_ptr<int>> rv;
	rv.reserve(n);
	for (int i = 0; i < n; ++i)
		rv.push_back(std::make_shared<int>(i));
	return rv;
}











static std::vector<std::unique_ptr<int>> fill_vec3()
{
	std::vector<std::unique_ptr<int>> rv;
	rv.reserve(n);
	for (int i = 0; i < n; ++i)
		rv.push_back(std::make_unique<int>(i));
	return rv;
}

static void BMFillVec1(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_vec1();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillVec1);

static void BMFillVec2(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_vec2();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillVec2);

static void BMFillVec3(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = fill_vec3();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMFillVec3);
