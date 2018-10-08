
struct Point
{
	double x;
	double y;
};

struct Color
{
	char r;
	char g;
	char b;
};

// ???
struct Size
{
	double w;
	double h;
};

struct Rectangle
{
	Point origin;
	Size size;
};


class JuiceBottle
{
	// ...;

private:
	double max_volume_;
	double cur_volume_;
};


class String
{
private:
	char *s_;
	size_t len_;
	size_t capacity_;
};


struct Task 
{
	Theme theme;
	std::string text; 
};


struct Hometask
{
	std::vector<Task> tasks;
};


class CourseState
{
	...;
private:
	std::set<Theme> learned_themes_;
	Hometask last_hometask_;
};

