// RAII

class String
{
public:
	String();
	String(const char *s);
	~String();
	String(const String& rhs);
	String(String&& rhs);

	String& operator = (const String& rhs);
	String& operator = (String&& rhs);

private:
	char* s_;
	size_t l_;
};

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

String::String(String&& rhs)
{
	s_ = rhs.s_;
	l_ = rhs.l_;

	rhs.s_ = new char[1];
	rhs.s_[0] = 0;
	rhs.l_ = 0;
}

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
