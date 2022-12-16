#include <cstdio>

namespace {
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
}  // namespace

void f() {
    HTMLPrinter printer;
    printer.p();
}
