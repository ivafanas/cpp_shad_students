// forward-declare std::istream
namespace std {
  template<class CharT> struct char_traits;
  template<class CharT, class Traits = char_traits<CharT>> class basic_istream;
  using istream = basic_istream<char>;
}

extern int read_int(std::istream& is);
extern int read_float(std::istream& is);

struct Person
{
    int age;
    float weight;
};

Person read_person(std::istream& is)
{
    Person p;
    p.age = read_int(is);
    p.weight = read_float(is);
    return p;
}

