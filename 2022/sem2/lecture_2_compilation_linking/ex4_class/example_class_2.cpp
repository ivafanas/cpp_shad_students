#include <cstdio>

class HTMLPrinter {
public:
    void p();
    void div();

private:
    void print(const char* s);
};

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

