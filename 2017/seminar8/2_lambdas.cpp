#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <utility>
#include <vector>


// sort

struct Person
{
	std::string name;
	unsigned age;
};

// simple example

bool less_by_age(const Person& lhs, const Person& rhs)
{
	return std::tie(lhs.age, lhs.name) < std::tie(rhs.age, rhs.name);
}

void mysort_naive(std::vector<Person>& v)
{
	std::sort(v.begin(), v.end(), less_by_age);
}

// functor example

class LessByAge
{
public:
	bool operator() (const Person& lhs, const Person& rhs) const
	{
		return std::tie(lhs.age, lhs.name) < std::tie(rhs.age, rhs.name);
	}
};

void mysort_with_functor(std::vector<Person>& v)
{
	std::sort(v.begin(), v.end(), LessByAge());
}

// lambda example

void mysort_with_lambda(std::vector<Person>& v)
{
	std::sort(v.begin(), v.end(), [](const Person& lhs, const Person& rhs) {
		return std::tie(lhs.age, lhs.name) < std::tie(rhs.age, rhs.name);
	});
}


// specific sort

// functor example

class LessByAgeFellow
{
public:
	LessByAgeFellow(const std::string& fellow)
		: fellow_(fellow)
	{}

	bool operator() (const Person& lhs, const Person& rhs) const
	{
		if (lhs.name == fellow_ && rhs.name != fellow_)
			return true;

		if (lhs.name != fellow_ && rhs.name == fellow_)
			return false;

		return std::tie(lhs.age, lhs.name) < std::tie(rhs.age, rhs.name);
	}

private:
	std::string fellow_;
};

void mysort_with_fellow_functor(std::vector<Person>& v, const std::string& fellow)
{
	std::sort(v.begin(), v.end(), LessByAgeFellow(fellow));
}

// lambda example

void mysort_with_fellow_lambda(std::vector<Person>& v, const std::string& fellow)
{
	std::sort(v.begin(), v.end(), [&fellow](const Person& lhs, const Person& rhs) {
		if (lhs.name == fellow && rhs.name != fellow)
			return true;

		if (lhs.name != fellow && rhs.name == fellow)
			return false;

		return std::tie(lhs.age, lhs.name) < std::tie(rhs.age, rhs.name);
	});
	// fellow - capture by copy
	// &fellow - capture by reference
}

void mutable_lambda_example()
{
	auto fun = [i = 0]() mutable -> bool {
		++i;
		return i != 4;
	};
	while (fun())
		std::cout << "ho";
}


int main()
{
	mutable_lambda_example();
	return 0;
}
