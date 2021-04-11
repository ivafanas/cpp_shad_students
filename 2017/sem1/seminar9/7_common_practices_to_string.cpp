#include <sstream>
#include <string>

static std::string to_string1()
{
	uint64_t val(12345678900ul);
	benchmark::DoNotOptimize(val);

	std::ostringstream oss;
	oss << val;
	return oss.str();
}










static std::string to_string2()
{
	uint64_t val(12345678900ul);
	benchmark::DoNotOptimize(val);

	return std::to_string(val);
}








static void BMToString1(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = to_string1();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMToString1);

static void BMToString2(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = to_string2();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMToString2);
