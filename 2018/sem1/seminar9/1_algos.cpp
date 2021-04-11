#include <algorithm>
#include <list>
#include <numeric>
#include <vector>

// accumulate

int sum_98(const std::vector<int>& v)
{
	int res = 0;
	const std::vector<int>::const_iterator v_end = v.end();
	for (std::vector<int>::const_iterator it = v.begin(); it != v_end; ++it)
		res += *it;
	return res;
}

int sum_stl(const std::vector<int>& v)
{
	return std::accumulate(v.begin(), v.end(), 0);
}

int sum_range_for_11(const std::vector<int>& v)
{
	int res = 0;
	for (auto x : v)
		res += x;
	return res;
}

// find

bool contains_98(const std::vector<int>& v, int val)
{
	const std::vector<int>::const_iterator v_end = v.end();
	for (std::vector<int>::const_iterator it = v.begin(); it != v_end; ++it)
		if (*it == val)
			return true;
	return false;
}

bool contains_stl(const std::vector<int>& v, int val)
{
	// tell what is better (stl of course; it better shows intent)
	// tell about syntax problem here:
	// v contains val
	// std:: .begin() v.end() != v.end()
	return std::find(v.begin(), v.end(), val) != v.end();
}

bool contains_range_for_11(const std::vector<int>& v, int val)
{
	for (auto x : v)
		if (x == val)
			return true;
	return false;
}

// count

size_t count_98(const std::vector<int>& v, int val)
{
	size_t rv = 0;
	const std::vector<int>::const_iterator v_end = v.end();
	for (std::vector<int>::const_iterator it = v.begin(); it != v_end; ++it)
		if (*it == val)
			++rv;
	return rv;
}

size_t count_stl(const std::vector<int>& v, int val)
{
	return std::count(v.begin(), v.end(), val);
}

size_t count_range_for_11(const std::vector<int>& v, int val)
{
	size_t rv = 0;
	for (auto x : v)
		if (x == val)
			++rv;
	return rv;
}

// http://www.cplusplus.com/reference/algorithm/
// http://www.cplusplus.com/reference/numeric/

// output iterators feature

void copy_example_bug()
{
	std::vector<int> a = {1, 2, 3, 4, 5};
	std::vector<int> b;

	std::copy(a.begin(), a.end(), b.begin());
}

void copy_example_fix1()
{
	std::vector<int> a = {1, 2, 3, 4, 5};
	std::vector<int> b;

	b.resize(a.size(), 0);
	std::copy(a.begin(), a.end(), b.begin());
}

void copy_example_fix2()
{
	std::vector<int> a = {1, 2, 3, 4, 5};
	std::vector<int> b;

	std::copy(a.begin(), a.end(), std::back_inserter(b));
	// back_inserter calls b.push_back(...)
}

// replace_copy

void replace_copy_bug()
{
	std::vector<int> a = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	std::vector<int> b;

	std::replace_copy(a.begin(), a.end(), b.begin(), 2, 7);
}

void replace_copy_fix()
{
	std::vector<int> a = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	std::vector<int> b;

	std::replace_copy(a.begin(), a.end(), std::back_inserter(b), 2, 7);
}

void replace_copy_better()
{
	std::vector<int> a = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	std::vector<int> b;

	b.reserve(a.size());
	std::replace_copy(a.begin(), a.end(), std::back_inserter(b), 2, 7); // O(n)
}

// removing elements from container

void remove_usage_bug()
{
	std::vector<int> a = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	std::remove(a.begin(), a.end(), 2);

	// std::remove does not change container size (it cann't!)
	// it leaves last elements in garbage state
}

void remove_usage_fix()
{
	std::vector<int> a = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	auto new_end = std::remove(a.begin(), a.end(), 2);
	a.resize(std::distance(a.begin(), new_end));
}

void remove_usage_list_exception()
{
	std::list<int> a = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	a.remove(2);
	// list is an exception!
}

// remove repeating elements from container

void unique_usage_bug()
{
	std::vector<int> a = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	std::sort(a.begin(), a.end()); // unique removes only adjacent uniques
	std::unique(a.begin(), a.end());

	// unique does not change container size!
}

void unique_usage_fix()
{
	std::vector<int> a = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	std::sort(a.begin(), a.end()); // unique removes only adjacent uniques
	auto new_end = std::unique(a.begin(), a.end());
	a.resize(std::distance(a.begin(), new_end));
}

void unique_usage_list_excepion()
{
	std::list<int> a = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	a.sort(); // unique removes only adjacent uniques
	a.unique();
}

int main()
{
	return 0;
}
