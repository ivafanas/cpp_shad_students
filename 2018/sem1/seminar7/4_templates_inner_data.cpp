#include <iostream>
#include <string>
#include <vector>

template<typename T>
class Stack
{
public:
	Stack() = default;

	void push(const T& x)
	{
		v_.push_back(x);
	}

	T pop()
	{
		T rv = v_.back();
		v_.pop_back();
		return rv;
	}

private:
	UnderlyingContainer v_;
};

int main(int argc, char **argv)
{
	Stack<int> s;
	s.push(5);
	s.push(7);

	// because I can!
	Stack<Stack<std::string>> sss;
	sss.push(Stack<std::string>());
	sss.push(Stack<std::string>());

	return 0;
}

template<typename T>
class Stack
{
public:
	using UnderlyingContainer = std::vector<T>;

public:
	Stack() = default;

	void push(const T& x)
	{
		v_.push_back(x);
	}

	T pop()
	{
		T rv = v_.back();
		v_.pop_back();
		return rv;
	}

public:
	class iterator
	{
		...
	};

	class const_iterator
	{
		...
	};

	iterator begin() { return ...; }
	iterator end() { return ...; }
	const_iterator begin() const { return ...; }
	const_iterator end() const { return ...; }

private:
	UnderlyingContainer v_;
};


int main(int argc, char **argv)
{
	Stack<int>::UnderlyingContainer container{1, 2, 3, 4, 5};
	Stack<int>::UnderlyingContainer::value_type some_value = 42;

	Stack<int> s;
	Stack<int>::iterator s_begin = s.begin();
	Stack<int>::iterator s_end = s.end();

	for (int x : s)
		std::cout << x << std::endl;

	return 0;
}