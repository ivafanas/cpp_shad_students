
class Animal
{
public:
	Animal() = default;
	virtual ~Animal() = default;

private:
	std::string name_;
};

class Turtle : public Animal
{
public:
	Turtle()
	{
		// first ask before throwing exception
		// throw std::runtime_error("There are no turtles in our fairy tale.");
	}
	~Turtle() override = default;

private:
	Leg[4] legs_;
};

class Tortilla : public Turtle
{
public:
	Tortilla() = default;
	~Tortilla() override = default;

private:
	Headdress bonnet_;
};

int main()
{
	try
	{
		Tortilla t;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
