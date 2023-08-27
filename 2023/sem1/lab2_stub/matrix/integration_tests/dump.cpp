#include "matrixlib/matrix.h"

#include <iostream>
#include <string>
#include <sstream>

static bool check1() {
  const Matrix<int, 3, 3> m = Matrix<int, 3, 3>::identity();
  std::stringstream ss;
  ss << m;
  std::cout << m;
  return ss.str() ==
    "[1 0 0]\n"
    "[0 1 0]\n"
    "[0 0 1]\n";
}

static bool check2() {
  const Matrix<int, 2, 2> m = Matrix<int, 2, 2>::diagonal(100);
  std::stringstream ss;
  ss << m;
  std::cout << m;
  return ss.str() ==
    "[100 0]\n"
    "[0 100]\n";
}

int main(int, char **) {
  if (!check1())
    return 1;
  if (!check2())
    return 1;
  return 0;
}
