#include <cstdio>

class HTMLPrinter {
public:
    HTMLPrinter() = default;
    ~HTMLPrinter() = default;

    void p() {
        print("<p>");
    }

    void div() {
        print("<div>");
    }

private:
    void print(const char* s) {
        std::puts(s);
    }
};

void f() {
    HTMLPrinter printer;
    printer.p();
}

