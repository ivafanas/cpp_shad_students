#include <iostream>

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

