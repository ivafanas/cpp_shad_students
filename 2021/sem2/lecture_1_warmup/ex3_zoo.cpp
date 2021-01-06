#include <cstdio>
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace {

class Animal {
public:
    Animal(std::string name, int age)
        : name_(std::move(name))
        , age_(age)
    {}

    virtual ~Animal() = default;

    virtual std::string get_greeting() const = 0;

    const std::string& name() const { return name_; }
    int age() const { return age_; }

private:
    std::string name_;
    int age_;
};

class Turtle : public Animal {
public:
    explicit Turtle(std::string name, int age)
        : Animal(std::move(name), age) {}

    std::string get_greeting() const override { return "hello"; }
};

class NinjaTurtle : public Turtle {
public:
    NinjaTurtle(std::string name) : Turtle(std::move(name), 12) {}

    std::string get_greeting() const override { return "camabanga!"; }
};

}  // namespace

[[nodiscard]]
static std::vector<std::unique_ptr<Animal>> make_zoo() {
    std::vector<std::unique_ptr<Animal>> rv;
    rv.reserve(7);
    rv.emplace_back(std::make_unique<Turtle>("Tortilla", 100));
    rv.emplace_back(std::make_unique<Turtle>("Big Turtle", 100));
    rv.emplace_back(std::make_unique<Turtle>("Aunt Motya", 200));
    rv.emplace_back(std::make_unique<NinjaTurtle>("Leonardo"));
    rv.emplace_back(std::make_unique<NinjaTurtle>("Donatello"));
    rv.emplace_back(std::make_unique<NinjaTurtle>("Mikelangelo"));
    rv.emplace_back(std::make_unique<NinjaTurtle>("Rafael"));
    return std::move(rv);
}


int main() {
    for (const std::unique_ptr<Animal>& animal : make_zoo())
        std::printf("I'm %11s. My age is %3i. %s\n",
                    animal->name().c_str(),
                    animal->age(),
                    animal->get_greeting().c_str());
    return 0;
}

