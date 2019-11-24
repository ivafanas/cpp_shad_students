#include <cstdio>

class HTMLPrinter {
public:
    HTMLPrinter();
    ~HTMLPrinter();

    void p();
    void div();

private:
    void print(const char* s);
};

HTMLPrinter::HTMLPrinter() = default;
HTMLPrinter::~HTMLPrinter() = default;

void HTMLPrinter::p() {
    print("<p>");
}

void HTMLPrinter::div() {
    print("<div>");
}

void HTMLPrinter::print(const char* const s) {
    std::puts(s);
}

void f() {
    HTMLPrinter printer;
    printer.p();
}

