// RAII

class String
{
public:
	String();
	String(const char *s);
        String(const char *s, int size);
	~String();
	String(const String& rhs);
	String(String&& rhs);

	String& operator = (const String& rhs);
	String& operator = (String&& rhs);

	String operator + (const String& rhs) const;

private:
	char* s_;  // pointer to null-terminated characters
	size_t l_; // strlen(s_) == l_
};

// implement first to demonstrate problems in c-tors
String String::operator + (const String& rhs) const
{
	const size_t res_size = l_ + rhs.l_;
	const char* res_s = new char[res_size + 1];
	strcpy(res_s, s_);
	strncpy(res_s + l_, rhs.s_, rhs.l_);
	String s(res_s, res_size);

	delete[] res_s;
	return s;
}

String::String()
	: s_(new char[1])
	, l_(0)
{
	s_[0] = 0;
}

String::String(const char* s)
{
	l_ = strlen(s);
	s_ = new char[l + 1];
	std::strcpy(s_, s);
}

String::String(const char *s, int size)
	: s_(new char[size + 1])
	, l_(size + 1)
{
	strncpy(s_, s, size);
	s_[l_] = 0;
}

String::~String()
{
	delete[] s_;
}

String::String(const String& rhs)
{
	s_ = new char[rhs.l_ + 1];
	l_ = rhs.l_;
	std::strcpy(s_, rhs.s_);
}


// use case:
// String s1 = "run, Forest, run!";
// String s2 = std::move(s1);

// why it is bad ?
String::String(String&& rhs)
	: s_(rhs.s_)
	, l_(rhs.l_)
{
}


// spoiler: d-tors

// why it is bad ?
String::String(String&& rhs)
	: s_(rhs.s_)
	, l_(rhs.l_)
{
	rhs.s_ = 0;
	rhs.l_ = 0;
}


// spoiler: rhs is broken

// implementation 1
String::String(String&& rhs)
{
	s_ = rhs.s_;
	l_ = rhs.l_;

	rhs.s_ = new char[1];
	rhs.s_[0] = 0;
	rhs.l_ = 0;
}

// implementation 2
String::String(String&& rhs)
{
	std::swap(s_, rhs.s_);
	std::swap(l_, rhs.l_);
}

// which implementation is better and why?

String& String::operator =(const String& rhs)
{
	if (this != &rhs)
	{
		delete[] s_;

		s_ = new char[rhs.l_ + 1];
		l_ = rhs.l_;
		std::strcpy(s_, rhs.s_);
	}
	return *this;
}

String& String::operator =(String&& rhs)
{
	if (this != &rhs)
	{
		delete[] s_;

		s_ = rhs.s_;
		l_ = rhs.l_;

		rhs.s_ = new char[1];
		rhs.s_[0] = 0;
		rhs.l_ = 0;
	}
	return *this;
}


// notes:
// && methods correct but bad: can throw exceptions, it would be better to implement them in noexcept way
// task: how to do this?
