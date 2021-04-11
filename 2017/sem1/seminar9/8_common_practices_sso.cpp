#include <string>

static std::string make_string_14()
{
	std::string rv("12345678901234");
	benchmark::DoNotOptimize(rv);
	return rv;
}

static std::string make_string_15()
{
	std::string rv("123456789012345");
	benchmark::DoNotOptimize(rv);
	return rv;
}

static std::string make_string_16()
{
	std::string rv("1234567890123456");
	benchmark::DoNotOptimize(rv);
	return rv;
}

static std::string make_string_17()
{
	std::string rv("12345678901234567");
	benchmark::DoNotOptimize(rv);
	return rv;
}

static void BMMakeString14(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = make_string_14();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMMakeString14);

static void BMMakeString15(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = make_string_15();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMMakeString15);

static void BMMakeString16(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = make_string_16();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMMakeString16);

static void BMMakeString17(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = make_string_17();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMMakeString17);
