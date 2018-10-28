#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

class Turtle
{
public:
	Turtle(bool is_ninja) : is_ninja_(is_ninja) {}

	void jump()
	{
		if (!is_ninja_)
			throw std::logic_error("Turtles cannot jump :(");

		std::cout << "Camabanga!" << std::endl;
	}

private:
	bool is_ninja_;
};

class Swarm
{
public:
	Swarm() {}

	void add(std::unique_ptr<Turtle> t)
	{
		turtles_.push_back(std::move(t));
	}

	Turtle& at(size_t i)
	{
		if (i >= turtles_.size())
			throw std::out_of_range("no such turtle");

		return *turtles_[i];
	}

private:
	std::vector<std::unique_ptr<Turtle>> turtles_;
};

int main()
{
	try
	{
		Swarm swarm;
		swarm.add(std::make_unique<Turtle>(false));
		swarm.add(std::make_unique<Turtle>(true));
		swarm.add(std::make_unique<Turtle>(false));

		auto& turtle = swarm.at(1);
		// auto& turtle = swarm.at(5);
		// auto& turtle = swarm.at(2);
		turtle.jump();

		// throw 12345;
	}
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "std exception" << std::endl;
	// 	std::cerr << e.what() << std::endl;
	// }
	catch(const std::out_of_range& e)
	{
		std::cerr << "out of range" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	catch(const std::logic_error& e)
	{
		std::cerr << "logic error" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "std exception" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
