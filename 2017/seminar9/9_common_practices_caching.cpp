#include <string>
#include <vector>

const std::vector<std::vector<double>> data = {
	{3.17744692, 5.92620571, 8.25519352, 5.38791914, 0.8765440},
	{2.08272032, 8.32814122, 8.80346836, 0.03075542, 7.5883834},
	{1.36476568, 4.29295626, 8.35784302, 0.42031432, 1.7609703},
	{9.96206844, 1.32851998, 7.53035291, 7.55081274, 2.8070660},
	{3.17744692, 5.92620571, 8.25519352, 5.38791914, 0.8765440},
	{2.08272032, 8.32814122, 8.80346836, 0.03075542, 7.5883834},
	{1.36476568, 4.29295626, 8.35784302, 0.42031432, 1.7609703},
	{9.96206844, 1.32851998, 7.53035291, 7.55081274, 2.8070660},
	{3.17744692, 5.92620571, 8.25519352, 5.38791914, 0.8765440},
	{2.08272032, 8.32814122, 8.80346836, 0.03075542, 7.5883834},
	{1.36476568, 4.29295626, 8.35784302, 0.42031432, 1.7609703},
	{9.96206844, 1.32851998, 7.53035291, 7.55081274, 2.8070660},
};

static std::vector<std::string> run()
{
	std::vector<std::string> rv;
	rv.reserve(data.size());
	for (const auto& row: data)
	{
		std::string str;
		for (double v : row)
			str += std::to_string(v);
		rv.push_back(str);
	}
	return rv;
}

static std::vector<std::string> run_alloc_caching()
{
	std::vector<std::string> rv;
	rv.reserve(data.size());
	std::string str;
	for (const auto& row: data)
	{
		str.clear();
		for (double v : row)
			str += std::to_string(v);
		rv.push_back(str);
	}
	return rv;
}

static void BMRun(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = run();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMRun);

static void BMRunAllocCaching(benchmark::State& state) {
	for (auto _ : state) {
		const auto x = run_alloc_caching();
		benchmark::DoNotOptimize(x);
	}
}
BENCHMARK(BMRunAllocCaching);
