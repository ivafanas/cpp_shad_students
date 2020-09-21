#include <iostream>

class Name {
public:
    Name() { std::cout << "Name "; }
    ~Name() { std::cout << "~Name "; }
};

class Leg {
public:
    Leg() { std::cout << "Leg "; }
    ~Leg() { std::cout << "~Leg "; }
};

class Hat {
public:
    Hat() { std::cout << "Hat "; }
    ~Hat() { std::cout << "~Hat "; }
};

class Animal {
public:
    Animal() { std::cout << "Animal "; }
    ~Animal() { std::cout << "~Animal "; }

private:
    Name name_;
};

class Turtle : public Animal {
public:
    Turtle() { std::cout << "Turtle "; }
    ~Turtle() { std::cout << "~Turtle "; }

private:
    Leg l1_, l2_, l3_, l4_;
    Hat hat_;
};

// show this later
// Animal animal;

int main() {
    std::cout << "hello!" << std::endl;
    Turtle tortilla;
    std::cout << std::endl << "goodbye!" << std::endl;
    return 0;
}

