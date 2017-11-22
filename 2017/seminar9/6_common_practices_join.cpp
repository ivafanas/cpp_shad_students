#include <string>
#include <vector>

static const std::vector<std::string> strings {
	"Yellow Submarine\n",
	"\n",
	"In the town where I was born\n",
	"Lived a man who sailed to sea\n",
	"And he told us of his life\n",
	"In the land of submarines\n",
	"So we sailed up to the sun\n",
	"Till we found the sea of green\n",
	"And we lived beneath the waves\n",
	"In our yellow submarine\n"
};

static std::string join1()
{
	std::string rv;
	for (const auto line: strings)
		rv = rv + line;
	return rv;
}






static std::string join2()
{
	std::string rv;
	for (const auto& line: strings)
		rv = rv + line;
	return rv;
}









static std::string join3()
{
	std::string rv;
	for (const auto& line: strings)
		rv += line;
	return rv;
}







static std::string join4()
{
	size_t total_size = 0;
	for (const auto& line: strings)
		total_size += line.size();

	std::string rv;
	rv.reserve(total_size);
	for (const auto& line: strings)
		rv += line;
	return rv;
}

static void BMJoin1(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = join1();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMJoin1);

static void BMJoin2(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = join2();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMJoin2);

static void BMJoin3(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = join3();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMJoin3);

static void BMJoin4(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = join4();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMJoin4);
